
// POTD of 010325 - Array Operations.
/*
    Given an array of 'n' elements, we need to apply two main operations.
        > 'n-1' operations where for the 'i'th index, if (nums[i]==nums[i+1]),
            then, nums[i] is multiplied by 2 & nums[i+1] is made 0;
        > We need to shift all the zeros the end of the array.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
    public:
        void applyOps(vector<int>& arr)
        {
            int n = arr.size();
            for(int i = 0; i<n-1; i++) {
                if(arr[i] == arr[i+1])
                {
                    arr[i] *= 2;
                    arr[i+1] = 0;
                }
            }
        }

        void shiftZeros(vector<int>& arr)
        {
            int n = arr.size();

            // Finding the first zero;
            int slow = -1;
            for(int i=0; i<n; i++) {
                if(arr[i] == 0) {
                    slow = i;
                    break;
                }
            }

            if(slow == -1) {
                return;
            }

            for(int fast = slow+1; fast<n; fast++)
            {
                if(arr[fast] != 0) {
                    int temp = arr[fast];
                    arr[fast] = arr[slow];
                    arr[slow] = temp;
                    slow++;
                }
            }
        }
};

int main(void)
{
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    vector<int> arr (n);
    cout << "Enter the " << n << " array elements : ";
    for(int i = 0; i<n; i++) {
        cin >> arr[i];
    }

    Solution obj = Solution();
    obj.applyOps(arr);
    obj.shiftZeros(arr);

    cout << "Final Array : [ ";
    for(const int& ele : arr) {
        cout << ele << " ";
    } cout << "]\n";

    cout << "\nEOP!\n";
    return 0;
}