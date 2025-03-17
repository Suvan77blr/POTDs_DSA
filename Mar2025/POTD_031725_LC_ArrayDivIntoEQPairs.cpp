
// 170325
/*
    2206. Divide Array Into Equal Pairs

    - Given an integer array 'nums' consisting of '2*n' integers.
    
    - We need to divide nums into n pairs such that:
        - Each element belongs to exactly one pair.
        - The elements present in a pair are equal.
    - Return 'true' if nums can be divided into n pairs, otherwise return 'false'.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
    public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> ump_freq;

        for(const int ele : nums) {
            ump_freq[ele]++;
        }

        for(const auto& ele : ump_freq) {
            if(ele.second%2 != 0)
                return false;
        }
        return true;
    }
};

int main(void)
{
    int n;
    cout << "Enter array size : ";
    cin >> n;

    vector<int> nums (n);
    cout << "Enter the " << n << " array elements : ";
    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    bool result = Solution().divideArray(nums);
    cout << "Can array be divided into pairs of equal elements? : ";
    cout << (result ? "true!\n" : "false!\n");

    return 0;
}