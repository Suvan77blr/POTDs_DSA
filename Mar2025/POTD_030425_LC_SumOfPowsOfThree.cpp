
// 040325
/*
    Check if Number is a sum of powers of Three. (Prob 1780)
*/

#include <iostream>
#include <math.h>
using namespace std;

class Solution {
    public:
        bool checkPowersOfThree(int n) {
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
};

int main(void) {
    int n;
    cout << "Enter number to check : ";
    cin >> n;

    Solution soln = Solution();
    bool result = soln.checkPowersOfThree(n);
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