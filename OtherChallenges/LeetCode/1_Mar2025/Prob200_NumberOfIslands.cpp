
// 170325
/*
    200. Number of Islands.
        => 4-adjacency.
    
    Given an `m x n` 2D binary matrix 'grid' which represents a map of '1's (land) and '0's (water).
    Return the number of islands.

    An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
    You may assume all four edges of the grid are all surrounded by water.
*/

/* IMPT : May have to handle the CHAR input for each '0' and '1' in the practical sum.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void bfsSearch(vector<vector<int>>& grid, vector<vector<bool>>& vis, int sr, int sc);
    int getCountOfIsland(vector<vector<int>>& grid);
};

int Solution :: getCountOfIsland(vector<vector<int>>& grid) {
    int n=grid.size(), m=grid[0].size();
    int islandCount = 0;
    vector< vector<bool> > vis(n, vector<bool>(m, false));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(grid[i][j] && !vis[i][j])
            {
                islandCount++;
                bfsSearch(grid, vis, i, j);
            }
        }
    }
    return islandCount;
}

void Solution :: bfsSearch(vector<vector<int>>& grid, vector<vector<bool>>& vis, int sr, int sc)
{
    int n=grid.size(), m=grid[0].size();
    vector<pair<int, int>> bfsQ;

    vis[sr][sc] = true;
    bfsQ.push_back({sr, sc});

    vector<pair<int, int>> delta = {
        {-1, 0}, {0,1}, {1, 0}, {0,-1}
    };
    int nX, nY;

    while(!bfsQ.empty())
    {
        auto [currX, currY] = bfsQ.back();
        bfsQ.pop_back();

        for(auto& del : delta) {
            nX = currX + del.first;
            nY = currY + del.second;

            if(nX>=0 && nY>=0 && nX<n && nY<m && grid[nX][nY] && !vis[nX][nY])
            {
                vis[nX][nY] = true;
                bfsQ.insert(bfsQ.begin(), {nX, nY});
            }
        }
    }
}

int main(void)
{
    int n, m;
    // cout << "Enter the order of the matrix : ";
    cin >> n >> m;

    vector< vector<int> > grid (n, vector<int>(m, 0));
    // cout << "Enter the " << n <<"x" << n << " grid : " << endl;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> grid[i][j];
        }   
    }

    int islandCount = Solution().getCountOfIsland(grid);
    cout << "Island Count : " << islandCount << endl;

    return 0;
}

/*
    TCs :
    1) IP : 8 13
            [
                0 0 1 0 0 0 0 1 0 0 0 0 0
                0 0 0 0 0 0 0 1 1 1 0 0 0
                0 1 1 0 1 0 0 0 0 0 0 0 0
                0 1 0 0 1 1 0 0 1 0 1 0 0
                0 1 0 0 1 1 0 0 1 1 1 0 0
                0 0 0 0 0 0 0 0 0 0 1 0 0
                0 0 0 0 0 0 0 1 1 1 0 0 0
                0 0 0 0 0 0 0 1 1 0 0 0 0
            ]
       OP : 6

    2) IP : 5 4
            0 1 1 0
            0 1 1 0
            0 0 1 0
            0 0 0 0 
            1 1 0 1
       OP : 3      
*/