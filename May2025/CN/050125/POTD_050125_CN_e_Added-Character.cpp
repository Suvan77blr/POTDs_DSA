
// 010525
/*
    POTD_CN : Added Character.
        You are given a string 'S'. 
        Now one more additional character is introduced in this string, which turns 'S' into new string 'T'. 
        You have to find out this newly added character.

        All characters in 'S' and 'T' are upper case only.
        Length of 'T' is always 1 more than length of 'S'.
*/

#include <iostream>
#include <string>
using namespace std;

char findAddedCharacter(string& s, string& t) {
    char addedChar = '\0';

    int n = s.length();
    for(int i=0; i<n; i++) {
        if(s[i] != t[i]) {
            addedChar = t[i];
            break;
        }
    }

    if(!addedChar) { 
        // if(addedChar == '\0')
        addedChar = t[n];        // Last character of 't' will be the added-character.
    }
    return addedChar;
}

int main(void) {
    string s, t;
    // cout << "Enter \'s\' : ";
    cin >> s;
    // cout << "Enter \'t\' : ";
    cin >> t;

    char addedChar = findAddedCharacter(s, t);
    cout << "Added Character : \'" << addedChar << "\'\n";

    return 0;
}