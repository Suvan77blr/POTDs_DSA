
// 260525
/*
    2033. Minimum Operations to Make a Uni-Value Grid.

    You are given a 2D integer 'grid' of size (mxn) and an integer 'x'. 
    In one operation, you can add x to or subtract x from any element in the grid.

    A uni-value grid is a grid where all the elements of it are equal.

    Return the minimum number of operations to make the grid uni-value. 
    If it is not possible, return -1.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            int n=grid.size(), m=grid[0].size();

            int modValue = grid[0][0] % x;
            for(auto& row : grid) {
                for(int ele : row) {
                    if(ele % x != modValue) {
                    // If any two integers have different remainders dividing by x, then they cannot be made equal by +/e of x.
                        return -1;
                    }
                }
            }

            vector<int> vec;
            for(const auto& row : grid) {
                for(int ele : row) {
                    vec.push_back(ele);
                }
            }

            sort(vec.begin(), vec.end());

            int mid = (0 + vec.size()-1) / 2;
            int target = vec[mid];

            int count = 0;
            for(const auto& row : grid) {
                for(int ele : row) {
                    count += abs(target - ele) / x;
                }
            }
            return count;
        }
};

int main(void) {
    int n, m;
    // cout << "Enter the number of rows and cols : ";
    cin >> n >> m;

    vector<vector<int>> grid (n, vector<int>(m));
    // cout << "Enter the " << n*m << " elements of the grid : " << endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> grid[i][j];
        }
    }

    int x;
    // cout << "Enter the integer to be add/sub-ed : ";
    cin >> x;

    int minOps = Solution().minOperations(grid, x);
    cout << "\nMin-Ops to make Uni-Grid : " << minOps << endl;
    return 0;
}

// Similar Sums : 462. Minimum Moves to Equal Array Elements II