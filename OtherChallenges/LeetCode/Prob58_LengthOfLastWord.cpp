
// 080325
/*
    58. Length of Last Word.
        Given is a string 's' consisting of words and spaces.
        Return the length of the last word in the string.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution{
    public:
        int lengthOfLastWord(string s)
        {
            int right = s.length()-1;

            int wrdEnd=-1, wrdStart=-1;

            while(right>=0)
            {
                if(s[right] != ' '){
                    wrdEnd = right;
                    break;
                }
                right--;
            }

            while(right>=0)
            {
                if(s[right] == ' '){
                    wrdStart = right;
                    break;
                }
                right--;
            }
            return wrdEnd - wrdStart;
        }
};

int main(void) {
    string s;
    cout << "Enter the string of words : ";
    getline(cin , s);

    int lenOfLastWord = Solution().lengthOfLastWord(s);
    cout << "Length of last word : " << lenOfLastWord << endl;
    return 0;
}