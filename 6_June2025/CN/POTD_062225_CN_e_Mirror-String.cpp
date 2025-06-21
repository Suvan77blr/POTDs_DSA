// 220625
/*
    Mirror-String: Symmetric after mirror image.
*/

#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

bool isLetterSymmetric(char ch) {
	static unordered_set<char> symm = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};
	return symm.find(ch) != symm.end();
}

bool isMirrorString(string &s)
{
	// Write your code here.
	int left=0, n=s.length(), right=n-1;

	while(left <= right) {
		if(s[left] != s[right]) {
			return false;
		}

		if(!isLetterSymmetric(s[left]) || !isLetterSymmetric(s[right])) {
			return false;
		}

		left++; right--;
	}
	return true;
}

int main(void) {
    string str;
    cin >> str;

    bool result = isMirrorString(str);
    cout << "Is input string a mirror-string? : ";
    cout << (result ? "Yes.\n" : "No.\n");

    return 0;
}