
// 180325
/*
    2658. Maximum Number of Fish in a Grid.    
    
    Given a 0-indexed 2D matrix 'grid' of size (m x n), where (r, c) represents:
        A land cell if grid[r][c] = 0, or
        A water cell containing 'grid[r][c]' fish, if grid[r][c] > 0.
    A fisher can start at any water cell (r, c) and can do the following operations any number of times:

        Catch all the fish at cell (r, c), or
        Move to any adjacent water cell.
    Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally.
    Return 0 if no water cell exists.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int bfsArea(vector<vector<int>>& grid, vector<vector<bool>>& vis, int sr, int sc)
    {
        int n=grid.size(), m=grid[0].size();
        int area = 1;
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
                    area++;
                    vis[nX][nY] = true;
                    bfsQ.insert(bfsQ.begin(), {nX, nY});
                }
            }
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int maxArea = 0, currArea;
        vector< vector<bool> > vis(n, vector<bool>(m, false));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] && !vis[i][j])
                {
                    currArea = bfsArea(grid, vis, i, j);
                    maxArea = max(maxArea, currArea);
                }
            }
        }
        return maxArea;
    }
};

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

    int maxArea = Solution().maxAreaOfIsland(grid);
    cout << "Max Island area : " << maxArea << endl;

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
       OP : 5      
*/