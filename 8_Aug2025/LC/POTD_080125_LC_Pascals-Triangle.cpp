
// 080125
/*
    Pascal's Triangle.
    Topics: Array, Combinatorics, Math, Pattern Construction.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    vector<vector<int>> getPascalTriangle(int numRows) {
        vector<vector<int>> res;
        res.push_back({{1}});
        if(numRows == 1) {
            return res;
        }
        vector<int> curr, newArr;
        curr.push_back(1);

        int currLen;
        for(int i=2; i<=numRows; i++) {
            currLen = curr.size();
            newArr.push_back(1);
            for(int j=1; j<currLen; j++) {
                newArr.push_back(curr[j-1] + curr[j]);
            }
            newArr.push_back(1);
            res.push_back(newArr);
            curr = newArr;
            newArr.clear();
        }
        return res;
    }
};

int main(void) {
    int numRows; 
    cin >> numRows;

    vector<vector<int>> result = Solution().getPascalTriangle(numRows);
    for(auto row: result) {
        for(int ele: row) {
            cout << ele << " ";
        } cout << "\n";
    }

    return 0;
}