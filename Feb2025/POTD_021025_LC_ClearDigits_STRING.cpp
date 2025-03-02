
// 100225
/* POTD LC : Clear Digits 

   	-  Problem to remove delete all the digits in the given string. 
		=> Need to delete the 'first' digit and the 'closest non-digit character' to its left. 
*/

#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    string clearDigits(string s) {
        int n = s.length();
        int i=0;
        while(i < s.length())
        {
            if(s[i] >= '0' && s[i] <= '9') {
                s.erase(i, 1);
                for(int j = i-1; j>=0; j--)
                {
                    if(s[j] >= 'a' && s[j] <= 'z') {
                        s.erase(j, 1);
                        n = n-1;
                        break;
                    }
                }
                i=0;
                continue;
            }
            i = i+1;
        }
    return s;
    }
};

int main(void)
{
	string s;
	cout << "Enter the string : ";
	cin >> s;

	Solution obj = Solution();
	string output = obj.clearDigits(s);
	if(output.length() == 0)
		output = "EMPTY STRING";

	cout << "Output : " << output << endl;
	return 0;
}
