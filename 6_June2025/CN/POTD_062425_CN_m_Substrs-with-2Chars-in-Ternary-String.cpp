// 240625.
/*
    Christmas at the Office.
        - Every Christmas, Jim gives Pam the perfect gift. 
        - This year, Pam wants to return the favor—with a special string!

        - She has a ternary string 's' (made of at most three different characters). Pam wants to count how many contiguous substrings of s contain at most two different characters—those are the ones she’ll gift to Jim.

        - Help Pam find the total number of such substrings.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int getTwoCharStringsCount(string& s) {
        int left=0, right=0, n=s.length();
        if(n < 1) { return 0; }

        int uniqChars=0, ans=0;
        vector<int> freq (26, 0);

        while(right < n) {
            if(freq[s[right] - 'a'] == 0) {
                uniqChars++;
            }
            freq[s[right] - 'a']++;

            while(uniqChars > 2) {
                freq[s[left] - 'a']--;
                if(freq[s[left] - 'a'] == 0) {
                    uniqChars--;
                }
                left++;
            }

            ans += (right - left + 1);
            right++;
        }
        return ans;
    }
};

int main(void) {
    string s;
    cin >> s;       // Inputing the ternary string.

    int twoCharStrings = Solution().getTwoCharStringsCount(s);
    cout << "Giftable-2Char strings: " << twoCharStrings << endl;

    return 0;
}

/*
    TCs:
    "abbc" => 9.
    "aabc" => 8.
    "john" => 7.
*/