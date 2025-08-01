
// 080125
/*
    POTD_CN_e: Beautiful-Idx
        - Given an array A of length N;
            Find the leftmost index i (1-based) such that:
            sum of first (i-1) elements == sum of last (N - i) elements.

    TOPICs: Prefix Sum, Running Sum, Linear Scan, 1-Based Indexing Logic.
*/

#include <iostream>
#include <vector>
using namespace std;

int getBeautifulIndex(int N, vector<int> A)
{
	int sum=0;
	for(int ele: A) { sum += ele;   }
	
	int prefix = 0;
	for(int i=0; i<N; i++) {
		int suffix = sum - prefix - A[i];
		if(prefix == suffix) {
			return i+1;
		}
		prefix += A[i];
	}
	return -1;
}

int main(void) {
    int n; cin >> n;

    vector<int> arr (n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int beautifulIndex = getBeautifulIndex(n, arr);
    cout << "Beautiful Idx(1-based): " << beautifulIndex << "\n";
    return 0;
}

