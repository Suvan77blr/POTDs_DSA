
// 040325
/*
    Check if Number is a sum of powers of Three. (Prob 1780)
*/

#include <iostream>
#include <math.h>
using namespace std;

class Solution {
    public:
        bool checkPowersOfThree_Intuition(int n) {
            // To get the max power of 3 to represent the number 'n'.
            int maxExp = (int)(log10(n) / log10(3)) + 1;
            int sum = 0, val;

            for(int i=maxExp; i>=0; i--) {
                val = pow(3, i);
                sum += val;

                if(sum == n)
                    return true;
                
                if(sum > n) {
                    sum -= val;
                }
            }
            return false;
        }

        bool checkPowersOfThree_CrazyOptimal(int n) {
            /*
                Logic : num%3 can have 3 values : 0,1,2
                2 - that number can never be expressed as a sum of 3 powers.

                0, 1 - that number may be expressed as a power of 3.
                    we reupdate the quotient in this case and then continue the iteration.
            */
            
            if(n<0) return false;

            while(n>0) {
                auto [q, r] = div(n, 3);
                
                if(r == 2)
                    return false;

                n=q;
            }
            return true;
        }
};

int main(void) {
    int n;
    cout << "Enter number to check : ";
    cin >> n;

    Solution soln = Solution();
    // bool result = soln.checkPowersOfThree_Intuition(n);
    bool result = soln.checkPowersOfThree_CrazyOptimal(n);
    cout <<"Is " << n << " a Sum of Powers of 3 ? : " << (result?"True":"False") << endl;
}

/*
    TCs :-
    1) IP : n=12
       OP : true    (3^1 + 3^2)

    2) IP : n=91    (3^0 + 3^2 + 3^4)
       OP : true

    3) IP : n=21
       OP : false
*/