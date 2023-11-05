// if the undirected graph has less number of nodes

#include<iostream>
#include<cstring>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int adj[n + 1][n + 1];
    memset(adj, 0, sizeof(adj));

    int u, v;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    return 0;
}