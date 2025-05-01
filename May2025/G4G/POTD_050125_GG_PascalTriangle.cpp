
// 010525
/*  POTD: Pascal's Triangle.
    Given a positive integer n, return the nth row of pascal's triangle.
*/ 

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> getNthRowOfPascalTriangle(int n)
        {
            if(n < 1) {
                return {};
            }
            
            vector<int> curr = {1};
            if(n == 1) {
                return curr;
            }

            vector<int> next;
            int nPrev;

            for(int i=1; i<n; i++) {
                nPrev = curr.size();
                next = vector<int> (nPrev+1);
                next[0] = curr[0];

                for(int j = 1; j<nPrev; j++) {
                    next[j] = curr[j-1] + curr[j];
                }
                next[nPrev] = curr[nPrev-1];
                curr = next;

                next.clear();
                next.shrink_to_fit();
            }
            return curr;
        }
};

int main(void) {
    int n;
    // cout << "Enter \'n\' : ";
    cin >> n;

    vector<int> NthRow = Solution().getNthRowOfPascalTriangle(n);
    cout << "Pascal's Triangle's " << n << "'th Row : ";

    if(NthRow.empty()) {
        cout << "{}";
    }
    else {
        cout << "\n\t";
        for(int ele : NthRow) {
            cout << ele << " ";
        }
    }
    cout << "\n";

    return 0;
}

/*
// TCs :
    1. 3 => 1 2 1
    2. 5 => 1 4 6 4 1
*/