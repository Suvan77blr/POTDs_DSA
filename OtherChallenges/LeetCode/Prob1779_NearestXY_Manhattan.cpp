
// 040325
/*
    1779. Find Nearest Point That Has the Same X or Y Coordinate.

    Given are two integers, x and y; repring two pts on the Cartesian plane.
    An array 'points' is also given, where points[i] = [ai, bi] => repring point (ai, bi) in the plane.
    A point is VALID if it shares the same x-coordinate or the same y-coordinate as your location.

    Return the index (0-indexed) of the valid point with the smallest Manhattan distance from your current location. 
    If there are multiple, return the valid point with the smallest index. 
    If there are no valid points, return -1.

    Manhattan distance btn two pts (x1, y1) & (x2, y2) = abs(x1-x2) + abs(y1-y2)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        bool isValidPoint(const int x, const int y, const vector<int>& crdinate, bool * exactMatch) {
            if(crdinate[0] == x && crdinate[1] == y) {
                *exactMatch = true;
                return true;
            }

            return (crdinate[0]==x || crdinate[1]==y);
        }

        int getManhattanDistance(int X, int Y, int x, int y) {
            return (abs(X-x) + abs(Y-y));
        }

        int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
            int minDist = INT16_MAX, currDist, minIndex = -1, n=points.size();
            bool exactMatch=false;
            for(int i=0; i<n; i++) {
                if(isValidPoint(x, y, points[i], &exactMatch)) {
                    if(exactMatch) {
                        return i;
                    }

                    currDist = getManhattanDistance(x, y, points[i][0], points[i][1]);

                    if(minDist > currDist) {
                        minIndex = (minDist == currDist) ? min(minIndex, i) : i;
                        minDist = currDist;
                    }
                }
            }
            return minIndex;
        }
};

int main(void) 
{
    int x,y;
    cout << "Enter the current location (x, y) : ";
    cin >> x >> y;

    int n;
    cout << "\nEnter the number of points : \n";
    cin >> n;

    cout << "Enter the " << n << " points : ";
    vector< vector<int> > points (n, vector<int>(2));
    for(int i=0; i<n; i++) {
        cin >> points[i][0] >> points[i][1];
    }

    Solution soln = Solution();
    int resultIndex = soln.nearestValidPoint(x, y, points);

    cout << "Result Index : " << resultIndex << endl;
    cout << "EOP!\n";

    return 0;
}

/*
    TCs :-
    1) IP : x = 3,
            y = 4,
            points = [[1,2],[3,1],[2,4],[2,3],[4,4]]
       OP : 2

    2) IP : x=3,
            y=4,
            points = [[2,3]]
       OP : -1

    3) IP : x=3,
            y=4,
            point = [[3,4]] 
       OP : 0 
*/