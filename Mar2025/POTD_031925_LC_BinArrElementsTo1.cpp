
// 190325
/*
    3191. Minimum Operations to Make Binary Array Elements Equal to One I.

    > Given a binary array 'nums'.

    > We can do the following operations on it, any number of times :-
        - Choose any 3 consequtive elements from the array and flip all of them.
        - Flipping an element means changing its value from 0 to 1, and from 1 to 0.

    > Return the minimum number of operations required to make all elements in nums equal to 1.
    > If it is impossible, return -1.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int minOperations(vector<int>& nums);
        bool isAllOnes(vector<int>& nums);
};

int Solution :: minOperations(vector<int>& nums)
{
    int n=nums.size();
    int k=3-1, flips = 0;

    int left=0, right;
    while(left<=n-k)
    {
        if(nums[left] == 0)
        {
            flips++;
            right = left+k;
            for(int i=left; i<=right; i++){
                nums[i] = nums[i] ^ 1;
            }
        }
        left++;
    }
    if(isAllOnes(nums))
        return flips;
    else return -1;
}

bool Solution :: isAllOnes(vector<int>& nums)
{
    for(const int ele : nums){
        if(ele != 1)
            return false;
    }
    return true;
}

int main(void){
    int n;
    cout << "Enter array size : ";
    cin >> n;

    vector<int> nums (n);
    cout << "Enter " << n << " array elements : ";
    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    int minFlips = Solution().minOperations(nums);
    cout << "Min Flips for all 1s : " << minFlips << endl;

    return 0;
}

/*
    TCs :
    1) IP : [0,1,1,1,0,0]
       OP : 3

    2) IP : [0,1,1,1] 
       OP : -1 
*/