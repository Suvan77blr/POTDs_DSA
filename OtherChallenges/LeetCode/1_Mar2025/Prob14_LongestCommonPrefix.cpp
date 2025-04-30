
// 070325
/*
    14. Longest Common Prefix.
        = finding the Longest common prefix in a given array of strings.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    public:
        string getLongestCommonPrefix(vector<string>& strs) {
            int n = strs.size();
            string prefix = strs[0];

            for(int i=1; i<n; i++) {
                int k=0;

                while(prefix[k] == strs[i][k] && k<strs[i].length()) {
                    k++;
                }

                prefix = prefix.substr(0, k);
            }
            return prefix;
        }
};

int main(void) {
    int n;
    cout << "Enter the array size : ";
    cin >> n;

    vector<string> strs(n, "");
    cout << "Enter the " << n << " strings : ";
    for(int i=0; i<n; i++) {
        cin >> strs[i];
    }

    string longestCommonPrefix = Solution().getLongestCommonPrefix(strs);
    cout << "Longest Common Prefix : " << longestCommonPrefix << endl;
    return 0;
}