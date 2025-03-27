
// 270325
/*
    2780. Minimum Index of a Valid Split.alignas

    Given is a 0-indexed integer array 'nums' of length 'n' with one dominant element.
    An element 'x' of 'nums' is dominant if more than half the elements of 'nums' have 'x'.

    You can split nums at an index i into two arrays nums[0, ..., i] and nums[i + 1, ..., n - 1].
    But this split is only valid if:

        - 0 <= i < n - 1
        - nums[0, ..., i], and nums[i + 1, ..., n - 1] have the same dominant element.

        Return the minimum index of a valid split.
        If no valid split exists, return -1.

    (Here, nums[i, ..., j] denotes the subarray of nums starting at index i and ending at index j, both ends being inclusive. Particularly, if j < i then nums[i, ..., j] denotes an empty subarray.)
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            int n = nums.size();
            
            unordered_map<int, int> ump;
            for(int ele : nums) {
                ump[ele]++;
            }

            int dominant, maxiCount = 0;
            for(auto it : ump) {
                if(it.second > maxiCount) {
                    dominant = it.first;
                    maxiCount = it.second;
                }
            }

            int currCount = 0;
            for(int i=0; i<n; i++) {
                if(nums[i] == dominant) {
                    currCount++;
                    if( (currCount > (i+1)/2 ) && ((maxiCount-currCount) > (n-i-1)/2 ) )
                        return i;
                }
            }
            return -1;
        }
};

int main(void) {
    int n;
    // cout << "\nEnter the array size : ";
    cin >> n;

    vector<int> nums(n);
    // cout << "\nEnter the " << n << " elements of array : ";
    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    int minSplitIndex = Solution().minimumIndex(nums);
    cout << "\nMinimum Split Index : " << minSplitIndex << endl;
    return 0;
}

/*
    TCs :
    1) IP : 4
            1 2 2 2
       OP : 2

    2) IP : 10
            2 1 3 1 1 1 7 1 2 1 
       OP : 4

    3) IP : 7
            3 3 3 3 7 2 2 
       OP : -1 
*/