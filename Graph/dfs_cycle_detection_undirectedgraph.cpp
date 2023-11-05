// Time C = O(N + E)
// Space C = O(N + E) + O(N) + O(N)

#include<vector>
#include<iostream>

using namespace std;

bool checkForCycle(int node, int parent, vector < int > & vis, vector < int > adj[]) {
    vis[node] = 1;
    for (auto it: adj[node]) {
        if (!vis[it]) {
            if (checkForCycle(it, node, vis, adj))
                return true;
        } 
        else if (it != parent)
            return true;
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    
    vector < int > vis(V, 0);
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (checkForCycle(i, -1, vis, adj)) 
                return true;
        }
    }
    return false;
}
