
// 070325
/*
    2523. Closest Prime Numbers in Range

    Given are two positive integers 'left' and 'right'.
    Find the two integers 'num1' and 'num2' such that:
        - 'left' <= 'num1' < 'num2' <= 'right'.
        - Both 'num1' and 'num2' are prime numbers.
        - 'num2' - 'num1' is the minimum amongst all other pairs satisfying the above conditions.

    Return the positive integer array ans = [num1, num2].
    If there are multiple pairs satisfying these conditions, return the one with the smallest 'num1' value. 
    If no such numbers exist, return [-1, -1].
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public: 
        vector<bool> getSieve(int right) {
            vector<bool> sieve (right+1, true);

            for(int i=2; i*i <= right; i++)
            {
                if(sieve[i]) {
                    for(int j=i*i; j<=right; j+=i) 
                    {
                        sieve[j] = false;
                    }
                }
            }
            return sieve;
        }

        vector<int> closestPrimes(int left, int right) {
            vector<bool> sieve = getSieve(right);

            
            int rightAcc = -1, leftAcc = -1;

            // Finding the first prime from the last.
            for(int i=right; i>=left; i--)
            {
                if(sieve[i]) {
                    rightAcc = i;
                    break;
                }
            }

            // When no prime number is found.
            if(rightAcc == -1) {
                return {leftAcc, rightAcc};
            }

            int minRight, minLeft, minDiff = INT32_MAX, diff;

            // Handling the cases where left = 1.
            if(left < 2)
                left = 2;
            for(int i=rightAcc-1; i>=left; i--)
            {
                if(sieve[i]) {
                    leftAcc = rightAcc;
                    rightAcc = i;

                    // Checking condition.
                    diff = leftAcc - rightAcc;
                    if(minDiff == diff) {
                        minLeft = min(leftAcc, minLeft);
                        minRight = min(rightAcc, minRight);
                    }
                    if(minDiff > diff) {
                        minDiff = diff;
                        minLeft = leftAcc;
                        minRight = rightAcc;        
                    }
                }
            }

            if(minRight == -1) {
                return {-1, minRight};
            }
            
            return {minRight, minLeft};

        }
};

int main(void) {
    int left, right;
    cout << "Enter the range [left, right] : ";
    cin >> left >> right;
    
    vector<int> result = Solution().closestPrimes(left, right);

    cout << "Closest primes btn " << left << " and " << right << " : [ ";
    for(const int ele : result) {
            cout << ele << " ";
    }

    cout << "]\nEOP!\n";
    return 0;
}

/*
    TCs :

    1) IP : left=10 , right=19 .
       OP : [11,13]
    2) IP : left=4 , right=6 .
       OP : [-1,-1]
    3) IP : left=19 , right=31.
       OP : [29,31]
    4) IP : left=1 , right=100
       OP : [2,3]
*/