
// 010825
/*
    POTD_US: Safe Zones in a Bomb Grid
    Topics: 2D Matrix Traversal, Directional Vectors.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;

int count_safe_zones(vector<vector<char>>& grid, int n, int m) {
    vector<vector<bool>> vis (n, vector<bool>(m, false));
    
    vector<pii> directions = {
        {-1, 0}, {1, 0}, {0, 1}, {0, -1}
    };

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j] == 'B') {
                // for(auto [dx, dy]: directions) {
                for(auto dir: directions) {
                    int dx=dir.first, dy=dir.second;
                    int x=i, y=j;
                    while(x>=0 && y>=0 && x<n && y<m && grid[x][y]!='W') {
                        vis[x][y] = true;
                        x += dx;
                        y += dy;
                    }
                }
            }
        }
    }

    int safe_cells = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!vis[i][j] && grid[i][j]=='0')
                safe_cells++;
        }
    }
    return safe_cells;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    int result = count_safe_zones(grid, n, m);
    cout << result << endl;
    return 0;
}

/*
    TC1:
        3 3
        000
        0B0
        000
*/