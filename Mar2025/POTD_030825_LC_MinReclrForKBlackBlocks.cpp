
// 080325
/*
    2379. Minimum Recolors to Get K Consecutive Black Blocks.

    Given a 0-indexed string blocks of length 'n', 
        where blocks[i] is either 'W' or 'B',  => the color of the ith block. 
        The characters 'W' and 'B' denote the colors white and black, respectively.

    Also given is an integer 'k', => the desired number of consecutive black blocks.
    
    In one operation, you can recolor a white block such that it becomes a black block.

    Return the minimum number of operations needed such that there is at least one occurrence of k consecutive black blocks.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
        int minimumRecolors(string blocks, int k)
        {
            int left=0, right = left+k-1, n = blocks.length();
            int minW = INT16_MAX, wCount = 0;

            while(right < n) 
            {
                wCount = 0;
                for(int i=left; i<=right; i++) {
                    if(blocks[i] == 'W')
                        wCount++;
                }
                if(minW > wCount) {
                    minW = wCount;
                }
                left++; right++;
            }
            return minW;
        }
};

int main(void) 
{
    string blocks;
    cout << "Enter the B-W block string : ";
    // cin >> blocks;
    getline(cin, blocks);

    int k;
    cout << "Enter \'k\' : ";
    cin >> k;

    int minBlackRecolors = Solution().minimumRecolors(blocks, k);
    cout << "Minimum recoloring of \'B\' blocks : " << minBlackRecolors << endl;

    return 0;
}