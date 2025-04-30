
/*
    3306. Count of Substrings Containing Every Vowel and K Consonants II

    Given is a string 'word' and a non-negative integer 'k'.
    Return the total number of substrings of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once ..
        ..and exactly k consonants.
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        long long countOfSubstrings(string word, int k)
        {
            long long count = 0;
            unordered_map<char, int> vowelRef = {
                {'a', 1},{'e', 2},{'i', 3},{'o', 4},{'u', 5},
            };
            unordered_map<char, bool> vowelCheck (5, false);

            return count;
        }
}

/*
    TCs: 
    1) IP : 
       OP : 
*/