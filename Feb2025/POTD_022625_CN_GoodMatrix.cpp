
// To Be editied and locally tested.

#include <bits/stdc++.h> 
vector<vector<int>> findGoodMatrix(vector<vector<int>> &arr) 
{
    // Write your code here
    int r = arr.size();
    int c = arr[0].size();
    vector< pair<int, int> > zeros;
    vector< vector<int> > result (r, vector<int>(c, 1));

    int zr, zc;
    bool bFound = false;
    for(int i = 0; i<r; i++)
    {
        for(int j = 0; j<c; j++)
        {
            if(arr[i][j] == 0)
            {
                zeros.emplace_back(pair<int, int>{i, j});
            }
        }
        if(bFound){
            break;
        }
    }

    // cout << zr << " " << zc << endl;
    for(const auto& zeroIndex : zeros)
    {
        zr = zeroIndex.first;
        zc = zeroIndex.second;

        for(int i = 0; i<c; i++) {
        result[zr][i] = 0;
        }
        for(int i = 0; i<r; i++) {
            result[i][zc] = 0;
        }
    }
    
    
    return result;
}

