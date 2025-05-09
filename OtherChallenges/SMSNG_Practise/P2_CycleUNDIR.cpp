#include <iostream>
#include <cstring>
using namespace std;

int a[100][100], n;

bool findcycle(int st, bool visited[], int parent, int &prev){
    cout << "Finding - st: " << st << " parent: " << parent << " prev: " << prev << endl;
    visited[st]=true;
    
    for(int j=0;j<n;j++){

        if(a[st][j] == 1 && visited[j] == false){

            if( findcycle(j, visited, st, prev) ){
                if(st==prev){
                    cout << "Backing.. - st: *" << st << "* parent: " << parent << " prev: " << prev << endl;
                    // cout << st << " ";
                    prev = -1;
                }
                else if(prev != -1){
                    cout << "Backing.. - st: *" << st << "* parent: " << parent << " prev: " << prev << endl;
                    // cout << st << " ";
                }

                return true;
            }

        }
        else if(a[st][j] == 1 && parent != j && visited[j] == true){
            cout << "Backing.. - st: *" << st << "* parent: " << parent << " prev: " << prev << endl;
            // cout << st << " ";    
            return true;
        }

    }
    return false;
}

int main(){
    memset(a,0,sizeof(a));
    int m;
    cin >> n >> m;
    
    int x,y;
    while(m--){
        cin>>x>>y;
        a[x][y]=1;
        a[y][x]=1;
    }
    
    bool visited[n] = {false};
    int parent = -1, prev = -1;
    findcycle(0,visited,parent,prev);
    
    return 0;
}