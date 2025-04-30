
// 020325
/*
    Merging 2D Arrays by Summing the Values :

    Given are two 2D integer arrays nums1 and nums2.
        => each element : [idi, vali] => 'id' and 'val' at index 'i'.

    Each array contains unique ids and is sorted in ascending order by id.

    Merge the two arrays into one array that is sorted in ascending order by id, respecting the following conditions :
        - Only ids that appear in at least one of the two arrays should be included in the resulting array.
        - Each id should be included only once and its value should be the sum of the values of this id in the two arrays. If the id does not exist in one of the two arrays, then assume its value in that array to be 0.
    
    Return the resulting array. The returned array must be sorted in ascending order by id.
*/

// Core Logic is present.
// Code to take input and print Output is yet to be added.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector< vector<int> > res;

        int ii = 0, jj = 0;
        int i, j, sumValue = 0;
        while(ii < n1 && jj < n2)
        {
            i = nums1[ii][0];          // id of nums1 at iith row.
            j = nums2[jj][0];          // id of nums2 at jjth row.

            if(i > j) {
                sumValue = 0 + nums2[jj][1];
                res.emplace_back(vector<int>{j, sumValue});        
                jj++;
            }
            else if (j > i) {
                sumValue = nums1[ii][1] + 0;
                res.emplace_back(vector<int>{i, sumValue});        
                ii++;
            }
            else {  // Here i == j
                sumValue = nums1[ii][1] + nums2[jj][1];
                res.emplace_back(vector<int>{i, sumValue});        
                ii++; jj++;
            }
        }

        while(ii < n1) {
            res.emplace_back(vector<int>{nums1[ii][0], nums1[ii][1]});
            ii++;        
        }


        while(jj < n2) {
            res.emplace_back(vector<int>{nums2[jj][0], nums2[jj][1]});
            jj++;        
        }

        return res;
    }
};


/*
    TCs :-
    1) Input: 
            nums1 = [[1,2],[2,3],[4,5]], 
            nums2 = [[1,4],[3,2],[4,1]]

        Output: [[1,6],[2,3],[3,2],[4,6]]

    2) Input: 
            nums1 = [[2,4],[3,6],[5,5]], 
            nums2 = [[1,3],[4,3]]
        Output: [[1,3],[2,4],[3,6],[4,3],[5,5]]
*/