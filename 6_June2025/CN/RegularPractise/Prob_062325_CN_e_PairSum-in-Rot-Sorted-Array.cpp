// 230625
/*
    Pair-Sum in Rotated Sorted Array.
        - FInding the pivot element.
            - both cases checking
                ( mid<n-1 && mid+1-th < mid-th ) ||  ( mid>0 && mid-1-th > mid-th )
            - Moving towards the un-sorted side.

        - Circular two-pointer as long as left != right.
*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    vector<int> findPairSum(vector<int>& arr, int target)
    {
        vector<int> res = {};
        int n = arr.size();
        
        if(n < 2) {
            return res;
        }

        int pivot = findPivotIdx(arr);
        int left = pivot;
        int right = (pivot - 1 + n) %n;
        int currSum = 0;
        while( left != right ) {
            currSum = arr[left] + arr[right];

            if(currSum == target) {
                res = {arr[left], arr[right]};
                break;
            }

            else if(currSum < target) {
                left = (left + 1) %n;
            }
            else {
                right = (right - 1 +n) %n;
            }
        }
        return res;
    }

    private:
    int findPivotIdx(vector<int>& arr) {
        int n = arr.size();
        int l=0, r=n-1, mid;

        if(arr[l] < arr[r]) {
            return 0;
        }

        while( l <= r) {
            mid = l + (r-l) /2;

            if(mid>0 && arr[mid] < arr[mid-1]) {
                return mid;
            }
            if(mid<n-1 && arr[mid] > arr[mid+1]) {
                return mid+1;
            }

            if(arr[l] <= arr[mid]) {
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
        return -1;
    }
};

int main(void) {
    int n;
    cin >> n;                   // Input 'n'.

    vector<int> arr (n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];          // Input 'arr'.
    }

    int target;
    cin >> target;              // Input 'target'.

    vector<int> res = Solution().findPairSum(arr, target);
    cout << "PairSum exists ? : ";
    if(!res.empty()) {
        cout << "Yes!\n => { " << res[0] << ", " << res[1] << " }\n";
    }
    else {
        cout << "No.\n";
    }
    return 0;
}

/*
    TCs
    5, [10 5 5 2 6]
    6, [1 2 3 2 3 1]
*/