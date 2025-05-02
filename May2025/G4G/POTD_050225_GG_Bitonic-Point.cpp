
// 020525
/*
    POTD_GG: Bitonic Point => PEAK ELEMENT.
        Given an array of integers arr[] that is first strictly increasing and then maybe strictly decreasing, 
            find the bitonic point, that is the maximum element in the array.

        Bitonic Point is a point before which elements are strictly increasing and after which elements are strictly decreasing.

        Note: It is guaranteed that the array contains exactly one bitonic point.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int findBitonicPoint(vector<int>& arr) {

            if(arr[0] > arr[1])     return arr[0];
            
            int n = arr.size();
            if(arr[n-1] > arr[n-2]) return arr[n-1];

            int left=1, right=n-2, mid;

            while(left <= right)
            {
                mid = left + (right-left)/2;
                if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]){
                    return arr[mid];
                }

                if(arr[mid-1] < arr[mid] && arr[mid] < arr[mid+1]) {
                    // Increasing curve => move to right search.
                    left = mid+1;
                }
                else {
                    // Decreasing curve => move to left search.
                    // (arr[mid-1] > arr[mid] && arr[mid] > arr[mid+1])
                    right = mid-1;
                }
            }
            return -1;
        }
};

int main(void) 
{
    int n;
    // cout << "Enter array size : ";
    cin >> n;

    vector<int> arr (n);
    // cout << "Enter the " << n << " array elements : ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int bitonicPoint = Solution().findBitonicPoint(arr);
    cout << "Bitonic Point of Input = " << bitonicPoint << endl;

    return 0;
}

/*
    // TCs:
    1) [1 2 4 5 7 8 3] => 8
    2) [10 20 30 40 50] => 50
    3) [120 100 80 20 0] => 120
*/