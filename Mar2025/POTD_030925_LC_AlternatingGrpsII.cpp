
// 090325
/*
    3208. Alternating Groups II.

    > There is a circle of red and blue tiles. 
    > Given is an array of integers 'colors' and an integer 'k'. 
    > The color of tile 'i' => colors[i]:
        - colors[i] == 0 means that tile i is red.
        - colors[i] == 1 means that tile i is blue.
    > An alternating group is every 'k' contiguous tiles in the circle with alternating colors.
        (each tile in the group except the first and last one has a different color from its left and right tiles).

    > Return the number of alternating groups.

    > Note that since 'colors' represents a circle, the first and the last tiles are considered to be next to each other.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int alternatingGroups(vector<int>& colors, int k)
        {
            int n = colors.size();
            bool hasSamePair = false;
            for(int i=0; i<n-1; i++)
            {
                if(colors[i] == colors[i+1]) {
                    hasSamePair = true;
                    break;
                }
            }
            if(colors[0]==colors[n-1]) 
                hasSamePair = true;

            if(!hasSamePair)
                return n;

            int resCount = n, left=0, right;

            for(; left < n; left++)
            {
                right = (left+k-1)%n;
                for(int j=left; j!=right; j=(j+1)%n)
                {
                    if(colors[j] == colors[(j+1)%n])
                    {
                        resCount--;
                        break;
                    }
                }
            }
            return resCount;
        }
};

int main(void) {
    int n;
    cout << "Enter array size : ";
    cin >> n;

    vector<int> colors(n);
    cout << "Enter the " << n << " elements : ";
    for(int i=0; i<n; i++)
    {
        cin >> colors[i];
    }

    int k;
    cout << "Enter 'k' value : ";
    cin >> k;

    int altGroupCount = Solution().alternatingGroups(colors, k);
    cout << "Alternating groups : "<< altGroupCount << endl;

    return 0;
}

/*
    TCs :
    1) IP : colors=[0,1,0,1,0]
            k=3
       OP : 3

    2) IP : colors=[0,1,0,0,1,0,1]
            k=6
       OP : 2 

    3) IP : colors=[1,1,0,1]
            k=4
       OP : 0
*/