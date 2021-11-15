#include <bits/stdc++.h>
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL);
#define pii pair<int, int>
#define sq(x) (x)*(x) 
const int MAX {10005};

vector<bool> visited(MAX);
vector<int> adj[MAX];
pii coord[MAX];
int m;

void dfs(int s){
    visited[s] = true;

    for(int u : adj[s]){
        if(!visited[u]) dfs(u);
    }
}

bool is_connected(pii a, pii b){
    return sq(a.first - b.first) + sq(a.second - b.second) <= sq(m);
}

int main(){ sws;

    int n, x, y;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> x >> y;
        coord[i] = {x,y};
    }

    cin >> m;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(is_connected(coord[i], coord[j])){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    dfs(0);

    for(int i=0; i<n; i++){
        if(!visited[i]){
            return cout << 'N' << endl, 0;
        }
    }
    
    cout << 'S' << endl;
    return 0;

}