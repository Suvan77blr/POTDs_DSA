
#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <cmath>
using namespace std;

class Solution {
    public:
    int maximumScore(vector<int>& nums, int k);
    int getPrimeScore(int num);

    void displayVector(vector<int>& v);

    void nge(vector<int>& nums);
};

int Solution :: maximumScore(vector<int>& nums, int k)
{
    int n=nums.size();
    vector<int> pScore (n);

    for(int i=0; i<n; i++) {
        pScore[i] = getPrimeScore(nums[i]);
    }

    cout << "nums[] : ";
    displayVector(nums);
    cout << "PSc[] : ";
    displayVector(pScore);
}

int Solution :: getPrimeScore(int num) 
{
//     set<int> primeFactors;
    
//     while(num%2 == 0){
//         primeFactors.insert(2);
//         num /= 2;
//     }

//     int limit = sqrt(num);
//     for(int i=3; i<sqrt(num); ) {
//         if(num%i == 0) {
//             primeFactors.insert(i);
//             num /= i;
//         }
//         else {
//             i+=2;
//         }
//     }

//     if(num>1){
//         primeFactors.insert(num);
//     }
//     return primeFactors.size();
}

void Solution :: displayVector(vector<int>& v) {
    cout << "[ ";
    for(int ele : v) {
        // cout << ele << " ";
        printf("%2d ",ele);
    } cout << "]\n";
}

void Solution :: nge(vector<int>& nums) {
    int n=nums.size();
    vector<int> res (n, -1);
    // stack<int> stk;
    vector<int> stk;

    for(int i=0; i<n; i++) {
        while(!stk.empty() && nums[stk.back()]>nums[i]){
            stk.pop_back();
        }
        if(!stk.empty())
            res[i] = nums[stk.back()];
        stk.push_back(i);
    }

    cout << "num : ";
    displayVector(nums);
    cout << "NGE : ";
    displayVector(res);
}

int main(void) {
    // int num;
    // // cout << "Enter the number : ";
    // cin >> num;

    // int pS = Solution().getPrimeScore(num);
    // cout << num << " : " << pS << endl;

    int n;
    // cout << "\nEnter the \'nums\' size : ";
    cin >> n;

    vector<int> nums (n);
    // cout << "\nEnter the " << n << " elements of \'nums\' : ";
    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    Solution().nge(nums);

    return 0;
}
