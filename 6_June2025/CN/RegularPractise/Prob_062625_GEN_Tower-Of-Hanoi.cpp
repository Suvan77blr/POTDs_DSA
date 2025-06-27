// 260625

/*
    Tower Of Hanoi.
*/

#include <iostream>
#include <vector>
using namespace std;

void toh(int n, int src, int intrim, int dest, vector<vector<int>>& seq) {
    if(n < 1)
        return;

    toh(n-1, src, dest, intrim, seq);
    seq.push_back({src, dest});
    toh(n-1, intrim, src, dest, seq);
}

vector<vector<int>> getTowerOfHanoiSequence(int n) {
    vector<vector<int>> toh_seq;
    toh(n, 1, 2, 3, toh_seq);
    return toh_seq;
}

int main(void) {
    int n;
    cin >> n;       // Input the number of disks.

    int moves = 0;
    vector<vector<int>> toh_seq = getTowerOfHanoiSequence(n);
    for(auto seq : toh_seq) {
        cout << "{ " << seq[0] << ", " << seq[1] << " }\n";
        moves++;
    }
    cout << "Total disk moves: " << moves << endl;
    return 0;
}