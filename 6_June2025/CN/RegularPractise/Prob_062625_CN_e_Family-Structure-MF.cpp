// 260625
/*
    Family Strucure:
        Every 'M' -> ['M', 'F'] as children.
        Every 'F' -> ['F', 'M'] as children.
        Root is always 'M'.
        Find the 'n'th generation's 'k'th child. => both are 1-based indexing.
*/

// M: 0
// F: 1

#include <iostream>
#include <cmath>
using namespace std;

int getNthGenKthChild(int n, long long k) {
    if (n == 1) {
        return 0;
    }

    int parent = getNthGenKthChild(n-1, (k+1) /2 );
    if(parent == 0)
        return (k % 2 == 1) ? 0 : 1;
    else   
        return (k % 2 == 1) ? 1 : 0;
}

int getSetBits(long long k) {
    int setBits = 0;
    while(k > 0) {
        if(k & 1){
            setBits++;
        }
        k >>= 1;
    }
    return k;
}

int binarySoln(int n, long long k) {
    int flips = getSetBits(k-1);
    return (flips%2 == 0) ? 0 : 1;
}

int main(void) {
    int n;
    long long k;
    cin >> n >> k;      // Input 'n' & 'k'.

    if( k > pow(2, n-1)) {
        cout << n << "th Gen doesn't have " << k << "th child." << endl;
        return 0;
    }

    int res = binarySoln(n, k);
    // int res = getNthGenKthChild(n, k);
        
    char ch = res ? 'F' : 'M';
    cout << n << "th Gen's " << k << "th child: " << ch << endl;
    return 0;
}

/*
                M
              /   \
             M     F   
           /   \ /   \
         M     F F    M

        (4, 6) => M
        (5, 3) => F
        (3, 6) => Invalid.
*/