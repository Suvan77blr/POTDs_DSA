// 220625
/*
    Finding Triplets => Sum of Two Elements Equals Third
        - (i != j) && (j != k) && (i != k).
        - ( a[i]+a[j] == a[k] ) || ( a[j]+a[k] == a[i] ) || ( a[i]+a[k] == a[j] )
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
    vector<int> findTriplets(vector<int>& arr, int n)
    {
        vector<int> result = {};
        sort(arr.begin(), arr.end());
        for(int i = n-1; i >= 2; i--) {
            if(hasTwoSum(arr, i, result) ) {
                break;
            }
        }
        return result;
    }

    private:
    bool hasTwoSum(vector<int>& arr, int keyIdx, vector<int>& res) {
        int key = arr[keyIdx];
        int left=0, right=keyIdx-1;

        while( left < right ) { 
            if(arr[left] + arr[right] == key) {
                res = {arr[left], arr[right], key};
                return true;
            }
            else if(arr[left] + arr[right] < key) {
                left++;
            }
            else {
                right--;
            }
        }
        return false;
    }
};

int main(void) {
    int n;
    cin >> n;   // Arr size.

    vector<int> arr (n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    vector<int> res = Solution().findTriplets(arr, n);
    cout << "Given array has triplet? : ";
    if(res.size()) {
        cout << "Yes!\n => { ";
        for(int i : res) { cout << i << " ";}
        cout << "}\n";
    }
    else {
        cout << "No.";
    }
    return 0;
}

/*
    TCs
    5, [10 5 5 2 6]
    6, [1 2 3 2 3 1]
*/