
// COde yet to be completed & committed.

// 080325
/*
    28. Find the first occurence of the string.
        => Given two strings 'needle' and 'haystack'.
        Return the index of the first occurrence of 'needle' in 'haystack'.
        Return -1 if needle is not part of 'haystack'.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
        int strStr(string haystack, string needle)
        {
            return -1;
        }
};

int main(void) {
    string haystack, needle;
    cout << "Enter the 'haystack' string : ";
    cin >> haystack;
    cout << "Enter the 'needle' string : ";
    cin >> needle;

    int needleFoundAtIndex = Solution().strStr(haystack, needle);
    cout << "Needle Found at Index : " << needleFoundAtIndex;
}