
// Quick Sort Implementation - TAKING THIS AS THE ORIGIN FOR THE SORTING Folder!

// 030325
// Partition Array according to a given Pivot.

#include <iostream>
#include <vector>
using namespace std;

#define SWAP(a, b) { \
    if(a != b){ \
    a = a ^ b;  \
    b = a ^ b;  \
    a = a ^ b;  \
    }           \
};   \

class Solution {
    public:
        int getPivotIndex(const vector<int>& arr, const int pivot) {
            int index = -1, n=arr.size();
            for(int i=0; i<n; i++){
                if(arr[i] == pivot) {
                    index = i;
                    break;
                }
            }
            return index;
        }

        // vector<int> pivotArray(vector<int>& arr, int pivot)
        void pivotArray(vector<int>& arr, int pivot)
        {
            vector<int> res (arr);

            int n = arr.size();
            int givenPivotIndex = getPivotIndex(arr, pivot);
            SWAP(arr[0], arr[givenPivotIndex]);

            int newPivotIndex = partition(arr, 0, n-1);
            // qsAsc(arr, 0, newPivotIndex-1);
            // qsDesc(arr, newPivotIndex+1, n-1)
            qs(arr, 0, newPivotIndex-1, true);
            qs(arr, newPivotIndex+1, n-1, false);
        
            // int left = 0, right = arr.size()-1;
            // int i = left, j = right; 
            // int p = getPivotIndex(arr, pivot);
            // while(left < right){
            
            /*
            // logic 1
            {

            
            int n=arr.size();
            vector<int> result (n);

            int front = 0, back = n-1;
            for(const int& ele : arr) {
                if(front >= back)
                    break;

                if(ele < pivot) {
                    result[front] = ele;
                    front++;
                }
                // else if(ele > pivot) {
                else { // ele >=pivot
                    result[back] = ele;
                    back--;
                }
            }

            }
            */

            // Logic 2 
            /*
                Keep the pos
            */ 
            // return result;
        }

        void displayArray(const vector<int>& arr, int start, int end) {
            cout << "Array (" << start << " - " << end << ") : [ ";
            for(int i=start; i<=end; i++) {
                cout << arr[i] << " ";
            }
            cout << "]\n";
        }

        int partition(vector<int>& arr, const int start, const int end, bool reverse=false) {
            // cout << "Partitioning : (" << start << " - " << end << ") start .. \n";
            // displayArray(arr, start, end);

            int pivot = start;
            int i=start, j=end;

            // As usual ascending order.
            if(!reverse)
            {   
                while(i<j) {
                    while(arr[pivot] >= arr[i] && i<end)
                        i+=1;
                    while(arr[pivot] < arr[j])
                        j-=1;
                    SWAP(arr[i], arr[j]);
                }
            }

            // Descending order : reverse=true
            else {
                while(i<j) {
                    while(arr[pivot] <= arr[i] && i<end)
                        i+=1;
                    while(arr[pivot] > arr[j])
                        j-=1;
                    SWAP(arr[i], arr[j]);
                }
            }
            SWAP(arr[i], arr[j]);
            // cout << "Penul Swap : ";displayArray(arr, start, end);
            // cout << "(i, j, pivot) = " << i << ", " << j << ", " << pivot << endl;
            // cout << "(arr[j], arr[pivot]) = " << arr[j] << ", " <<  arr[pivot] << endl;
            SWAP(arr[j], arr[pivot]);

            // cout << "Partitioning closing state : !\n";
            // displayArray(arr, start, end);
            return j;
        }

        int revPartition(vector<int>& arr, const int start, const int end) {
            // cout << "Partitioning : (" << start << " - " << end << ") start .. \n";
            // displayArray(arr, start, end);

            int pivot = start;
            int i=start, j=end;

            while(i<j) {
            // cout << "Loop entry!\n";
                while(arr[pivot] <= arr[i] && i<end)
                    i+=1;
                while(arr[pivot] > arr[j])
                    j-=1;
                SWAP(arr[i], arr[j]);
            }
            SWAP(arr[i], arr[j]);
            // cout << "Penul Swap : ";displayArray(arr, start, end);
            // cout << "(i, j, pivot) = " << i << ", " << j << ", " << pivot << endl;
            // cout << "(arr[j], arr[pivot]) = " << arr[j] << ", " <<  arr[pivot] << endl;
            SWAP(arr[j], arr[pivot]);

            // cout << "Partitioning closing state : !\n";
            // displayArray(arr, start, end);
            return j;
        }

        void qs(vector<int>& arr, int start, int end, bool reverse=false) {
            // cout << "\nQS Started : " << 0 << "-" << arr.size() << endl;
            if(start < end) {
                int splitIndex = partition(arr, start, end, reverse);
                // int splitIndex = revPartition(arr, start, end);
                // cout << "splitIndex" << splitIndex << endl;
                qs(arr, start, splitIndex-1);
                qs(arr, splitIndex+1, end);
                displayArray(arr, 0, arr.size()-1);
            }
        }
        void quickSort(vector<int>& arr) {


            cout << "\nQuickSort Started : " << 0 << "-" << arr.size() << endl;
            qs(arr, 0, arr.size()-1);
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
    // vector<int> result = soln.pivotArray(arr, pivot);
    // soln.quickSort(arr);
    soln.pivotArray(arr, pivot);

    cout << " QS Result : \n[ ";
    for(const int& ele : arr){
        cout << ele << " ";
    }cout << "]\n";

    // cout << "Result : \n[ ";
    // for(const int& ele : result){
    //     cout << ele << " ";
    // }cout << "]\n";

    cout << "\nEOP!\n";
    return 0;
}



// while(left < right){
//     if(arr[left] < pivot) {
            //         left++;
            //         i++;
            //     }
            //     else {

            //     }
                // if(arr[right] > pivot) {
                //     right--;
                //     j--;
                // }                
            // }

/*
    TCs:
    1) IP : n=7
            arr = [9 12 5 10 14 3 10]
            pivot = 10
       OP : [9,5,3,10,10,12,14] 

    QS : 5 3 1 4 2 8 9 7 
*/
