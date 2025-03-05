
// 050325
/*
    2579. Count Total Number of Colored Cells.

    There exists an infinitely large two-dimensional grid of uncolored unit cells. 
    You are given a positive integer n, indicating that you must do the following routine for n minutes:

        At the first minute, color any arbitrary unit cell blue.
        Every minute thereafter, color blue every uncolored cell that touches a blue cell.
    
    Return the number of colored cells at the end of n minutes.
*/
/*
    Approach : AGP approach is used .. based on the given test cases.
        => 1, 5, 13, .... where Ti = 1 + (4*i), i belongs in the range [0, n-1], n: number of minutes.
*/

#include <iostream>
using namespace std;

class Solution {
    public: 
        long long coloredCells(int n) {
            int base = 4;

            // Initially any cell is arbitrarily blue.
            long long gridSum = 1;

            for(int i=0; i<n; i++) {
                gridSum += base*i;
            }
            return gridSum;
        }
};

int main(void) {
    int n;
    cout << "Enter the \'n\' minutes : ";
    cin >> n;

    int cellCount = Solution().coloredCells(n);
    cout << "At end of \'" << n << "\' mins : " << cellCount << " colored cells.\n";

    return 0;
}
/*
*/