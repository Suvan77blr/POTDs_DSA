
// 080125
/*
    POTD_CN_m: Getting all BinaryStrings of length 'N'.
    TOPICs: Recursion, Backtracking, Strings, Binary-Strings, Combinatorics.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void getAllStrings(int idx, int N, vector<string>& res, string& s, bool bPrevOne)
{
    if(idx == N) {
        res.push_back(s);
        return;
    }

    if(idx == 0 || !bPrevOne) {
        s.push_back('0');
        getAllStrings(idx+1, N, res, s, false);
        s.pop_back();
        
        s.push_back('1');
        getAllStrings(idx+1, N, res, s, true);
        s.pop_back();
        return;
    }

    // if(bPrevOne) {
    else {
        s.push_back('0');
        getAllStrings(idx+1, N, res, s, false);
        s.pop_back();
        return;
    }
}

vector<string> generateString(int N) {
    vector<string> res;
    string s = "";

    getAllStrings(0, N, res, s, false);
    return res;
}

int main(void) {
    int n; 
    cin >> n;

    vector<string> result = generateString(n);
    for(auto binStr: result) {
        cout << binStr << "\n";
    }
}