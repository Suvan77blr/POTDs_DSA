
// 300325
/*
    2818. Apply Operations to Maximize Score.
    Given is an array 'nums' of n positive integers and an integer k.

    Initially, you start with a score of 1. 
    You have to maximize your score by applying the following operation at most k times:

        - Choose any non-empty subarray nums[l, ..., r] that you haven't chosen previously.
        - Choose an element x of nums[l, ..., r] with the highest prime score. If multiple such elements exist, choose the one with the smallest index.
        - Multiply your score by x.

        ( Here, nums[l, ..., r] denotes the subarray of nums starting at index l and ending at the index r, both ends being inclusive. )

        ( The prime score of an integer x is equal to the number of distinct prime factors of x. For example, the prime score of 300 is 3 since 300 = 2 * 2 * 3 * 5 * 5. )

    Return the maximum possible score after applying at most k operations.
    Since the answer may be large, return it modulo 1e9 + 7.
*/

#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

class Solution {
    public:
    int maximumScore(vector<int>& nums, int k);
    int getPrimeScore(int num);

    void displayVector(vector<int>& v);
};

int Solution :: maximumScore(vector<int>& nums, int k)
{
    int n=nums.size();
    vector<int> pScore (n);

    for(int i=0; i<n; i++) {
        pScore[i] = getPrimeScore(nums[i]);
    }


    vector<int> leftIndex (n, -1);
    // for(int i=1; i<n; i++) {
    //     for(int j=0; j<i; j++){
    //         if(pScore[j] >= pScore[i]){
    //             leftIndex[i] = j;
    //         }
    //     }
    // }
    
    vector<int> stk;
    for(int i=0; i<n; i++) {
        while(!stk.empty() && pScore[i] > pScore[stk.back()]) {
            stk.pop_back();
        }

        if(!stk.empty())
            leftIndex[i] = stk.back();
        stk.push_back(i);
    }

    vector<int> rightIndex (n, n);
    // for(int i=n-2; i>=0; i--) {
    //     for(int j=i+1; j<n; j++) {
    //         if(pScore[j] > pScore[i]) {
    //             rightIndex[i] = j;
    //         }
    //     }
    // }
    stk.clear();
    int poppedIdx;
    for(int i=0; i<n; i++) {
        while(!stk.empty() && pScore[i] > pScore[stk.back()]) {
            poppedIdx = stk.back();
            stk.pop_back();
            rightIndex[poppedIdx] = i;
        }
        stk.push_back(i);
    }

    cout << "nums[] : ";
    displayVector(nums);
    cout << "PSc[] : ";
    displayVector(pScore);
    cout << "Left[] : ";
    displayVector(leftIndex);
    cout << "Right[] : ";
    displayVector(rightIndex);
}

int Solution :: getPrimeScore(int num) 
{
    set<int> primeFactors;
    
    while(num%2 == 0){
        primeFactors.insert(2);
        num /= 2;
    }

    int limit = sqrt(num);
    for(int i=3; i<limit; ) {
        if(num%i == 0) {
            primeFactors.insert(i);
            num /= i;
            limit = sqrt(num);
        }
        else {
            i+=2;
        }
    }
    if(num>1){
        primeFactors.insert(num);
    }

    return primeFactors.size();
}

void Solution :: displayVector(vector<int>& v) {
    cout << "[ ";
    for(int ele : v) {
        cout << ele << " ";
    } cout << "]\n";
}

int main(void) {
    int n;
    // cout << "\nEnter the \'nums\' size : ";
    cin >> n;

    vector<int> nums (n);
    // cout << "\nEnter the " << n << " elements of \'nums\' : ";
    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    int k;
    // cout << "\nEnter \'k\' : ";
    cin >> k;

    // int maxOps = Solution().maximumScore(nums, k);
    Solution().maximumScore(nums, k);
    return 0;
}