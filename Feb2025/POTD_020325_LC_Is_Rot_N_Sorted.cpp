
// 030225
// Check if array is Sorted and Rotated. (LC)

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        bool isSorted_n_Rotated(vector<int>& nums)
        {
            int n=nums.size();

            // Optimizing.
            if(n <= 2)
                return true;

            int count = 0;
            for(int i=1; i<n; i++)
            {
                if(nums[i-1] > nums[i])
                    count++;
                
                // Optimizing.
                if(count > 1)
                    break;
            }
            if(nums[n-1] > nums[0])
                count++;
            return (count<=1);
        }
};

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

    bool result = obj.isSorted_n_Rotated(nums) ? true : false;
    cout << "Is the array both Sorted and Rotated ? : " << result << endl;
    return 0;
}

/*
    TEST CASES :-
    1. [3,4,5,1,2] => true
    2. [2,1,3,4] => false
    3. [1,2,3] => true
    4. [10,2] => true
*/