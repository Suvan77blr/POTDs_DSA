
// 130325
/*
    3356. Zero Array Transformation II

    > Given an integer array 'nums' of length 'n'.
    > Also is given a 2D array 'queries' where queries[i] = [li, ri, vali].

    > Each queries[i] represents the following action on 'nums':

        - Decrement the value at each index in the range [li, ri] in nums by at most 'vali'.
        - The amount by which each value is decremented can be chosen independently for each index.

    > A Zero Array is an array with all its elements equal to 0.

    > Return the minimum possible non-negative value of 'k'
    => such that after processing the first 'k' queries in sequence, 
        nums becomes a Zero Array.
        
    > If no such k exists, return -1.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        // Methods.
        int zeroArrayTransformations(vector<int>& nums, vector<vector<int>>& queries);
        bool isZeroArray(vector<int>& nums);
};

int Solution :: zeroArrayTransformations(vector<int>& nums, vector<vector<int>>& queries)
{
    int n = nums.size();
    vector<int> diffArray (n);

    for(const auto& q : queries) {

    }
}

bool Solution :: isZeroArray(vector<int>& nums)
{
    for(int ele : nums) {
        if(ele != 0)
            return false;
    }
    return true;
}

int main(void) {
    int n;
    cout << "Enter the array size : ";
    cin >> n;

    vector<int> nums (n);
    cout << "Enter the " << n << " array elements : ";
    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    int q;
    cout << "Enter the count of queries : ";
    cin >> q;

    vector<vector<int>> queries(q, vector<int>(3));
    for(int i=0; i<q; i++){
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }

    int minQueryCount = Solution().zeroArrayTransforms(nums, queries);
    cout << "Min-Queries for Zero Array Transformations : " << minQueryCount << endl;
    return 0;
}



/*
class Solution {
    public:
        bool isZeroArray(vector<int>& nums){
            for(const int ele : nums){
                if(ele != 0)
                    return false;
            }
            return true;
        }

        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries)
        {
            int k=0;
            if(isZeroArray(nums)) {
                    return k;
            }
            int diff= 0;
            for(const auto& q : queries)
            {
                for(int i=q[0]; i<=q[1]; i++)
                {
                    diff = nums[i] - q[2];
                    nums[i] = (diff<0)? 0 : diff;
                }
                k++;
                if(isZeroArray(nums)) {
                    return k;
                }
            }
            return -1;
        }
};

*/