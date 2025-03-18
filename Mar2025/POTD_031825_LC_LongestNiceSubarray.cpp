
// 180325
/*
    2401. Longest Nice Subarray.

    Given is an array 'nums' consisting of positive integers.
    A subarray of nums is called 'nice' if the bitwise AND of every pair of 
        elements that are in different positions in the subarray is equal to 0.
    Return the length of the longest nice subarray.

    (A subarray is a contiguous part of an array.
        Note that subarrays of length 1 are always considered nice.
    )
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
        int longestNiceArray(vector<int>& nums);
        bool isNiceWindow(vector<int>& nums, int l, int r);
};

int Solution :: longestNiceArray(vector<int>& nums)
{
    int n=nums.size();
    int maxLen=0, currLen;

    int left=0, right=0;

    while(left<n && right<n)
    {
        // Whenever the current subarray is 'nice', we increase the window size.
        if(isNiceWindow(nums, left, right)) {
            currLen = right - left + 1;
            maxLen = max(maxLen, currLen);
            right++;
        }
        
        // If it is not a Nice-Window, we increment the left-point.
        else {
            left++;
        }
    }
    return maxLen;
}

bool Solution :: isNiceWindow(vector<int>& nums, int l, int r)
{
    // Outer loop will run till the last-but-one index of the window.
    for(int i=l; i<r; i++)
    {
        for(int j=l+1; j<=r; j++)
        {
            if(nums[i] & nums[j])
            {
                // This will happen when '&' will get a non-zero value.
                return false;
            }
        }
    }
    return true;
}

int main(void) {
    int n;
    cout << "Enter array size : ";
    cin >> n;    

    vector<int> nums(n);
    cout << "Enter " << n << " array elements : ";
    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    int maxNiceArrayLength = Solution().longestNiceArray(nums);
    cout << "Longest \'Nice\' array length : " << maxNiceArrayLength << endl;

    return 0;
}

/*
    TCs :
    1) IP : [1,3,8,48,10]
       OP : 3               The longest nice subarray is [3,8,48].

    2) IP : [3,1,5,11,13]
       OP : 1               The length of the longest nice subarray is 1. Any subarray of length 1 can be chosen.
*/