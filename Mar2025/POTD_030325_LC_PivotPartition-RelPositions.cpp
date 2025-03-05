
// 030325
// Partition Array according to a given Pivot, maintaining the relative positions of the elements.

// Brute Force - seems to be inefficient logic(uses more SC) : needs updation.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        void appendVector(vector<int>& src, vector<int>& desti){
            for(const int& ele : src) {
                desti.emplace_back(ele);
            }
        }

        void displayVector(vector<int>& arr) {
            cout << "[ ";
            for(const int& ele : arr) {
                cout << ele << " ";
            } cout << "]\n";
        }

        vector<int> pivotArray_BruteForce(vector<int>& arr, int pivot){
            vector<int> smaller;
            vector<int> larger;
            int repeat = 0;
            for(const int& ele : arr){
                if(ele < pivot) {
                    smaller.emplace_back(ele);
                }
                else if(ele > pivot)
                {
                    larger.emplace_back(ele);
                }
                else repeat++;
            }

            cout << "Smaller : ";
            displayVector(smaller);
            cout << "Larger : ";
            displayVector(larger);
            cout << "Pivot repetitions : " << repeat << endl << endl;

            vector<int> result;
            appendVector(smaller, result);
            for(int i=0; i<repeat; i++) {
                result.emplace_back(pivot);
            }
            appendVector(larger, result);
            return result;
        }

        vector<int> pivotArray_TwoPointerApprch(vector<int>& arr, int pivot) {
            int n = arr.size();
            int left = 0, right = n-1;
            int i=left, j=right;

            vector<int> res (n, 0);

            while(i < n)
            {
                if(arr[i] < pivot) {
                    res[left] = arr[i];
                    left++;
                }
                if(arr[j] > pivot) {
                    res[right] = arr[j];
                    right--;
                }

                i++; j--;
            }

            while(left <= right) {
                res[left] = pivot;
                left++;
            }

            return res;
        }

        
};

int main(void) 
{
    int n;
    cout << "Enter vector size : ";
    cin >> n;

    vector<int> arr (n);
    cout << "Enter the " << n << " vector elements : ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int pivot;
    cout << "Enter pivot value : ";
    cin >> pivot;

    Solution soln = Solution();
    // vector<int> result = soln.pivotArray_BruteForce(arr, pivot);
    vector<int> result = soln.pivotArray_TwoPointerApprch(arr, pivot);

    cout << "Result : \n[ ";
    for(const int& ele : result){
        cout << ele << " ";
    }cout << "]\n";

    cout << "\nEOP!\n";
    return 0;
}

/*
    TCs:
    1) IP : n=7
            arr = [9 12 5 10 14 3 10]
            pivot = 10
       OP : [9,5,3,10,10,12,14] 

    2) IP : n=4
            arr = [-3 4 3 2]
            pivot = 2
       OP : [-3 2 4 3]

*/
