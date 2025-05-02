
// 020525
/*
    POTD_CN_m : Rotten Oranges.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int getMinTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    queue< pair< pair<int, int>, int > > bfsQ;
    vector< vector<bool> > vis (n, vector<bool>(m, false));     // To keep track of the oranges, visited and rotted.

    int time = 0;

    int totCount=0, rotCount=0;

    // Initialization of Queue.
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(grid[i][j] != 0) {
                // Orange is found.
                totCount++;

                if(grid[i][j] == 2) {
                    // Orange is rotten.
                    bfsQ.push(
                        {{i, j}, time}
                    );
                    rotCount++;
                    
                    // A rotten orange is found!
                    vis[i][j] = true;
                }
            }
        }
    }

    int maxTime = time;
    
    vector< pair<int, int> > delta {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };
    
    int cX, cY, nX, nY, cTime;  // Current and Neighboring values.

    while(!bfsQ.empty()) {
        cX = bfsQ.front().first.first;
        cY = bfsQ.front().first.second;
        cTime = bfsQ.front().second;

        bfsQ.pop();

        // Updating the maximum time value.
        maxTime = max(maxTime, cTime);

        for(auto del : delta) {
            nX = cX + del.first;
            nY = cY + del.second;

            if(nX>=0 && nY>=0 && nX<n && nY<m && grid[nX][nY]==1 && !vis[nX][nY])
            {
                // This orange will get rotten.
                vis[nX][nY] = true;
                rotCount++;

                bfsQ.push(
                    {{nX, nY}, cTime+1}
                );
            }

        }
    }

    return (rotCount == totCount) ? maxTime : -1;

}


int main(void) {
    int n, m;
    // cout << "Enter the graph rows and cols count : ";
    cin >> n >> m;

    vector<vector<int>> grid (n, vector<int>(m, 0));
    // cout << "Enter the " << n*m << " graph elements : ";
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> grid[i][j];
        }
    }

    int minTimeToRot = getMinTimeToRot(grid, n, m);
    cout << "Min Time to Rot = " << minTimeToRot << endl;

    return 0;
}