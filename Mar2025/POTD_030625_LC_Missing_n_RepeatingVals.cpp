
// 060325
/*
    2965. Find Missing and Repeated Values.

    Given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n^2].
        - Each integer appears exactly once except 'a' which appears twice.
        - An integer 'b' which is missing. 
    The task is to find the repeating and missing numbers 'a' and 'b'.

    Return a 0-indexed integer array 'ans' of size 2,
        where ans[0] = a and ans[1] = b.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> findMissingAndRepeatedElements(vector<vector<int>>& grid) {
            int n = grid.size();
            int maxNum = n*n;

            int reqSum = maxNum * (maxNum+1) / 2;
            int gotSum = 0;

            vector<bool> hashArr (maxNum, false);
            int repeated, missing;

            for(const auto& row : grid) {
                for(const int ele : row) {
                    if(hashArr[ele-1] != false) {
                        repeated = ele;
                    }
                    hashArr[ele-1] = true;
                    gotSum += ele;
                }
            }

            gotSum -= repeated;
            missing = reqSum - gotSum;

            return vector<int> {repeated, missing};
        }
};

int main(void) 
{
    int n;
    cout << "Enter 'n' : ";
    cin >> n;

    vector< vector<int> > grid (n, vector<int> (n));
    cout << "Enter the " << n*n << " elements : ";
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    vector<int> result = Solution().findMissingAndRepeatedElements(grid);
    cout << "Repeated value : " << result[0] << endl;
    cout << "Missing value : " << result[1] << endl;

    return 0;
}

/*
    TCs:
    1) IP : grid=[ [1,3], [2,2] ] 
       OP : [2,2] 
    
    2) IP : grid=[ [9,1,7], [8,9,2], [3,4,6] ]
       OP : [9,5] 
*/