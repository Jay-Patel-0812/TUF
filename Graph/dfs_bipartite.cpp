#include<iostream>
#include<vector>

// Time C: O(N + E)
// Space C: O(N + E) + O(N) + O(N)

using namespace std;

bool oddCycle(vector<int>& col, int V, vector<int> adj[], int node, int c){
    col[node] = c;
    for(auto i : adj[node]){
        if(col[i] == -1){
            if(oddCycle(col, V, adj, i, !c)){
                return true;
            }
        }
        else if(col[i] == c){
            return true;
        }
    }
    return false;
}

bool isBipartite(int V, vector<int> adj[]){
    vector<int> col(V, -1);
    for(int i = 0 ; i < V; i++){
        if(col[i] == -1){
            if(oddCycle(col, V, adj, i, 0)){
                return false;
            }
        }
    }
    return true;
}








bool bipartiteDfs(int node, vector<int> adj[], int color[]) {
    for(auto it : adj[node]) {
        if(color[it] == -1) {
            color[it] = 1 - color[node];
            if(!bipartiteDfs(it, adj, color)) {
                return false; 
            }
        } else if(color[it] == color[node]) return false; 
    }
    return true; 
}
bool checkBipartite(vector<int> adj[], int n) {
    int color[n];
    memset(color, -1, sizeof color); 
    for(int i = 0;i<n;i++) {
        if(color[i] == -1) {
            color[i] = 1;
            if(!bipartiteDfs(i, adj, color)) {
                return false;
            }
        } 
    }
    return true; 
}