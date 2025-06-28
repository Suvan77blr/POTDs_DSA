// 260625
/*
    Grid Overlap:
        - Given 2 binary grids Mat1 and Mat2 of order 'n' => with only 0s and 1s.
        - 4 shifts are possible: Right, Left, Up and Down Shifts.
        - If a shift involves a row/col going beyond the boundary, it is lost and not circled back.
            ... new row or col on the other side will be full of 0s.
        - Any number of shifts are possible.
        - Overlap: nos of cells of Mat1 and Mat2 which have 1 in it, in both the grids, after the shifts

        - Find the max-overlap possible.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#define PII pair<int, int>
using namespace std;

inline int getPairHash(PII shift) {
    return shift.first*10007 + shift.second;
}

vector<PII> getAllOnePos(vector<vector<int>>& mat, int n) {
    vector<PII> onesPos;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(mat[i][j] == 1) {
                onesPos.push_back({i, j});
            }
        }
    }
    return onesPos;
}

int getMaxOverlaps(vector<vector<int>>& mat1, vector<vector<int>>& mat2, int n)
{
    vector<PII> onesPos1 = getAllOnePos(mat1, n);
    vector<PII> onesPos2 = getAllOnePos(mat2, n);

    unordered_map<int, int> hashFreq;

    PII shift;
    int hash;
    for(auto pos1: onesPos1) {
        for(auto pos2: onesPos2) {
            shift = {pos1.first - pos2.first, pos1.second - pos2.second};
            hash = getPairHash(shift);
            hashFreq[hash]++;
        }
    }

    int maxi = 0;
    for(auto it: hashFreq) {
        if (it.second > maxi) {
            maxi = it.second;
        }
    }

    return maxi;
}

void inputMatrix(vector<vector<int>>& mat, int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> mat[i][j];
        }
    }
}

int main(void) {
    int n;
    cin >> n;

    vector<vector<int>> mat1 (n, vector<int>(n, 0));
    vector<vector<int>> mat2 (n, vector<int>(n, 0));
    inputMatrix(mat1, n);
    inputMatrix(mat2, n);

    int overlap = getMaxOverlaps(mat1, mat2, n);
    cout << "Max Possible Overlaps: " << overlap << endl;

    return 0;
}

/*
    TCs:
    3 
    1 1 0
    0 0 0
    0 0 0 
    -----
    0 1 1
    0 0 0
    0 0 0
        => 2;


    3  
    1 1 0
    0 1 0
    0 1 0
    -----
    0 0 0
    0 1 1
    0 0 1
        => 3
*/