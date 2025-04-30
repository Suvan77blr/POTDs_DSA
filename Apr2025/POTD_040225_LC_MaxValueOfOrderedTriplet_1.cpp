
// 020425
/*
    2873. Maximum Value of an Ordered Triplet I.

    > Given is a 0-indexed integer array 'nums'.
    
    > Value of a triplet of indices (i, j, k) is equal to (nums[i] - nums[j]) * nums[k].
    
    > Return the maximum value over all triplets of indices (i, j, k) such that i < j < k. 
        If all such triplets have a negative value, return 0.

    > Constraints : 
        3 <= nums.length <= 105
        1 <= nums[i] <= 106
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums)
        {
            long long maxValue = 0;
            int n = nums.size();
            for(int i=0; i<n-2; i++) 
            {
                for(int j=i+1; j<n-1; j++)
                {
                    for(int k=j+1; k<n; k++)
                    {
                        maxValue = max(maxValue, (long long)(nums[i] - nums[j])*nums[k]);
                    }
                }
            }
            return maxValue;
        }
        long long maxTripletValue_Greedy(vector<int>& nums);
};

long long Solution ::  maxTripletValue_Greedy(vector<int>& nums)
{
    int n=nums.size();
    long long maxVal = 0;
    for(int k=2; k<n; k++) {
        int temp = nums[0];
        for(int j=1; j<n; j++) {
            maxVal = max(maxVal, (long long)(temp - nums[j])*nums[k]);
            temp = max(temp, nums[j]);
        }
    }
    return maxVal;
}

int main(void) {
    int n;
    // cout << "Enter array size : ";
    cin >> n;

    vector<int> nums (n);
    // cout << "Enter " << n << " array elements : ";
    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    // int maxTripletVal = Solution().maximumTripletValue(nums);
    int maxTripletVal = Solution().maxTripletValue_Greedy(nums);
    cout << "Max Triplet Value = " << maxTripletVal << endl;

    return 0;
}

/*
    TCs :
    1) IP : 12 6 1 2 7
       OP : 77

    2) IP : 1 10 3 4 19
       OP : 133

    3) IP : 1 2 3
       OP : 0  
*/