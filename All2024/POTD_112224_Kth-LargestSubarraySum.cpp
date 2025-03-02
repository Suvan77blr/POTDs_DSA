
// POTD : 221124.
// Problem : To find the 'K'th largest Sub-Array Sum in the given array of elements.

// Min-Heap Jugaad is used so as to keep the SC limited w/in O(K).


#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int getSum(vector<int> &arr, int start, int end);
int getKthLargest(vector<int> &arr, int k);

int main(void)
{
    int n;          // Size of array.
    cout << "Enter \'n\' : ";
    cin >> n;
    
    vector<int> arr (n);    // Input Array.
    cout << "Enter the " << n << " elements : ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    int k;          // 'k'th largest subarray sum to return.
    cout << "Enter \'k\' : ";
    cin >> k;

    int result = getKthLargest(arr, k);
    cout << k << "th - Largest Sub-array sum : " << result << endl;
    return 0;
}

int getSum(vector<int> &arr, int start, int end)
{
    int sum = 0;
    for(int i = start; i<=end; i++){
        sum += arr[i];
    }
    return sum;
}

int getKthLargest(vector<int> &arr, int k)
{
    // Priority Queue => MIN HEAP Implementation.
    priority_queue<int> pq;

    int n = arr.size(), sum;
    for(int i = 0; i<n; i++)
    {
        for(int j = i; j<n; j++)
        {
            sum = getSum(arr, i, j);

            // Priority Queue Insertion rules : To ensure that SC of PQ will not exceed O(k).
            //  If current_size < k => just push the sum value.
            // If current_size >= k => check if the top element of MIN HEAP is greater than the currentSum value. Then if found to be greater, first the current Top is popped and the new Sum will be pushed. Or else, the element is ignored and loop will continue its search in the next subarray.

            if(pq.size() < k){
                pq.push(sum * -1);
            }

            else{
                // if(sum > pq.top())
                if(sum*-1 <= pq.top())
                {
                    pq.pop();
                    pq.push(sum * -1);
                }
            }

        }
    }

    return pq.top()*-1;
}
