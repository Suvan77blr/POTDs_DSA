
// 020525
/*
    POTD_LC: Push dominoes.
        * 'n' : dominoes.

        * Some are pushed to the Left or Right simultaneously.

        * After each second : 
            - Left fall = pushes adj on the Left.
            - Right fall = pushes adj on the Right.
        
        * A vertical domino w/ dominoes falling on both sides, will remain vertical 
            => balance of forces.

        * For this sum, falling domino will exert no force on another falling or already fallen domino.

                                        
        * 'dominoes':[] ... gives the initial state of the dominoes.
        * dominoes[i] => 
            - 'L' : i'th domino is pushed to the Left.
            - 'R' : i'th domino is pushed to the Right.
            - '.' : not pushed.

        * Return a string representing the final state.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) 
    {
        int n = dominoes.length();
        vector<int> netForce (n, 0);
        int force = 0;
        
        // Left->Right pass.
        /*
            'R' = N; 'L' = 0; '.' = force-1;
        */
        for(int i=0; i<n; i++) {
            if(dominoes[i] == 'R') {
                force = n;
            }
            else if (dominoes[i] == 'L') {
                force = 0;
            }
            else {
                force = max(0, force-1);
            }
            netForce[i] += force;
        }

        // Right->Left pass.
        // 'R', 'L', '.' = 0, N, force-1;
        force = 0;
        for(int i=n-1; i>=0; i--) {
            if(dominoes[i] == 'R') {
                force = 0;
            }
            else if (dominoes[i] == 'L') {
                force = n;
            }
            else {
                force = max(0, force-1);
            }
            netForce[i] -= force;
        }

        string result = "";

        for(int i=0; i<n; i++) {
            if(netForce[i] > 0) {
                result.push_back('R');
            }
            else if(netForce[i] < 0) {
                result.push_back('L');
            }
            else {
                result.push_back('.');
            }
        }

        return result;
    }
};

/*
    Idea : 
    * We carry out a net force calculation on each of the dominos.
    * In Right-Left Pass; 'R': N, 'L': 0, '.': max(0, force-1).
    * In Left-Right Pass; 'L': N, 'R': 0, '.': max(0, force-1).
    * the net_force is added in RtoL pass & subtracted in the LtoR pass.
    * In the end, if net_force[i] > 0, then = 'R'
                  otherwise, = 'L'
                  if net_force[i] == 0, then = '.'
*/

int main(void)
{
    string dominoes;
    // cout << "Enter the initial dominoes state-string : ";
    cin >> dominoes;

    string finalState = Solution().pushDominoes(dominoes);
    cout << "Final State = " << finalState << endl;

    return 0;
}

/*
    // My earlier coding attempt.
    string pushDominoes(string dominoes) {
        queue<int> q;
        int n = dominoes.length();
        for(int i=0; i<n; i++)
        {
            if(dominoes[i] != '.')
                q.push(i);
        }

        int currIdx;
        while(!q.empty()) {
            currIdx = q.front();
            q.pop();

            if(dominoes[currIdx] == 'L')
            {
                if(currIdx == 0)
                    continue;

                int prev = currIdx-1;
                if(dominoes[prev] == '.') {
                    if(prev == 0) {
                        dominoes[prev] = 'L';
                        q.push(prev);
                    }
                    else if(dominoes[prev-1] != 'R') {
                        dominoes[prev] = 'L';
                        q.push(prev);
                    }
                }
            }
            else if(dominoes[currIdx] == 'R')
            {
                if(currIdx == n-1)
                    continue;
                int next = currIdx+1;
                if(dominoes[next] == '.') {
                    if(next == n-1) {
                        dominoes[next] = 'R';
                        q.push(next);
                    }
                    else if(dominoes[next+1] != 'L') {
                        dominoes[next] = 'R';
                        q.push(next);
                    }
                }
            }
            else {
                // if(dominoes[currIdx] == '.')
                continue;
            }
        }
        return dominoes;
    }
*/