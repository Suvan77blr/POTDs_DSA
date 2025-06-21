
// 210525
/*
    Longest Substring - With Atmost-K-Distinct-Charecters.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    public:
    int kDistinctChars(int k, string& str) {
        vector<int> freq (26, 0);
        int left = 0, right = 0, n = str.length();

        int uniqueChar = 0, maxLen = 0;

        while(right < n){
            if(freq[str[right] - 'a'] == 0) {
                uniqueChar++;
            }
            freq[str[right] - 'a']++;

            while(uniqueChar > k) {
                freq[str[left] - 'a']--;
                if(freq[str[left] == 0]) {
                    uniqueChar--;
                }
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};

int main(void) {
    int k;
    // cout << "Enter the value of \'k\' : ";
    cin >> k;

    string str;
    // cout << "Enter the string: ";
    cin >> str;

    int maxLenOfStringWithKUniqueChars = Solution().kDistinctChars(k, str);
    cout << "The MaxLen Of String With " << k << " UniqueChars: " << maxLenOfStringWithKUniqueChars << endl;

    return 0;
}

/*
    TCs:
    3, "abcddefg" => 4
    4, "aaaaaaaa" => 8;
*/