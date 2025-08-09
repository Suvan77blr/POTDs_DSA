
// 090825
/*
    POTD_LC: Power of TWO.
        - Given an 'n' return if it is a valid power of 2 or not.

        Soln: a) while-loop.
              b) BIT-MANIPULATION
*/

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo_BIT_MANIP(int n) {
        return n>0 && (n & (n-1)) == 0;
    }

    bool isPowerOfTwo_RecFunc(int n) {
        if(n <= 0) return false;
        else if(n == 1) return true;
        else if(n & 1) return false;
        return isPowerOfTwo_RecFunc( n / 2 );
    }

    bool isPowerOfTwo_LOG(int n) {
        if(n<=0) return false;
        double logAns = log2(n);
        // return logAns == floor(logAns);
        return fabs(logAns - round(logAns)) < 1e-10;
    }

    bool isPowerOfTwo_WHILE(int n) {
        long long ans = 1LL;
        int base = 2;

        while(ans <= n) {
            if(ans == n) return true;
            ans *= base;
        }
        return false;
    }
};

int main(void) {
    int n;
    cin >> n;

    bool result = Solution().isPowerOfTwo_BIT_MANIP(n);
    // bool result = Solution().isPowerOfTwo_RecFunc(n);
    // bool result = Solution().isPowerOfTwo_LOG(n);
    // bool result = Solution().isPowerOfTwo_WHILE(n);

    cout << (result ? "TRUE\n" : "FALSE\n");
    return 0;
}