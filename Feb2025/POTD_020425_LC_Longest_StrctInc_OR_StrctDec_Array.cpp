
// 040225
// Finding the Longest_Strictly-Increasing_OR_Strictly-Decreasing_SubArray (LC)

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        int longestIncSubArray(vector<int>& nums);    
        int longestDecSubArray(vector<int>& nums);
        int longestMonotonicSubarray(vector<int>& nums);
};

int Solution :: longestIncSubArray(vector<int>& nums) {
    int n = nums.size();
    int slow = 0, fast = 1;
    int longSubArr = 0, currPos;
    for(slow = 0; slow<n; slow++)
    {
        currPos = slow;
        for(fast = currPos+1; fast<n; fast++, currPos++)
        {
            if(nums[currPos] >= nums[fast] )
            {
                break;
            }
        }

        if(longSubArr < (fast-slow))
        {
            longSubArr = fast-slow;
        }
    }
    return longSubArr;
}

int Solution :: longestDecSubArray(vector<int>& nums) {
    int n=nums.size();
    int slow = 0, fast = 1;
    int longSubArr=0, currPos;

    for(slow = 0; slow<n; slow++)
    {
        currPos = slow;
        for(fast = currPos+1; fast<n; fast++, currPos++)
        {
            if(nums[currPos] <= nums[fast])
                break;
        }

        if(longSubArr < (fast-slow))
        {
            longSubArr = fast-slow;
        }
    }
    return longSubArr;
}

int Solution :: longestMonotonicSubarray(vector<int>& nums) {
    int longInc = longestIncSubArray(nums);
    int longDec = longestDecSubArray(nums);
    cout << "(longInc, longDec) : (" << longInc << ", " << longDec << ")" << endl;
    return (longInc > longDec) ? longInc : longDec;
}

int main(void)
{
    int n;
    cout << "Enter array size : ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the " << n << " elements of tha array : ";
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }

    cout << "INPUT Array : [ ";
    for(const int& ele : nums){ cout << ele << " ";}
    cout << "]\n";

    Solution obj = Solution();

    int longestMonotonicSubArrayLength = obj.longestMonotonicSubarray(nums);
    cout << "Longest Strct-Incr OR Strct-Decr SubArray length : " << longestMonotonicSubArrayLength << endl;
    return 0;
}

/*
    TEST CASES :-
    1. [1,4,3,3,2] => 2
    2. [3,3,3,3] => 2
    3. [3,2,1] => 3
    4. [1,1,5] => 2
*/