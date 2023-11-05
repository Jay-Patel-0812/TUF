// if the undirected graph has more number of nodes, and edges has weights

#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adj[n + 1];
    int u, v, w;

    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    return 0;
}