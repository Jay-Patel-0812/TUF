#include<iostream>
#include<vector>

using namespace std;

bool dfscycle(vector<int>& vis, vector<int>& dfvis, int V, vector<int> adj[], int node){
    vis[node] = 1;
    dfvis[node] = 1;
    for(auto i : adj[node]){
        if(!vis[i]){
            if(dfscycle(vis, dfvis, V, adj, i))
                return true;
        }
        else if(vis[i] && dfvis[i]){    // is vis[i] necessary ?
            return true;
        }
    }
    dfvis[node] = 0;
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    vector<int> dfvis(V, 0);
    
    for(int i = 0; i < V; i++){
        if(!vis[i]){
            if(dfscycle(vis, dfvis, V, adj, i))
                return true;
        }
    }
    return false;
}






class Solution {
  private:
    bool checkCycle(int node, vector < int > adj[], int vis[], int dfsVis[]) {
      vis[node] = 1;
      dfsVis[node] = 1;
      for (auto it: adj[node]) {
        if (!vis[it]) {
          if (checkCycle(it, adj, vis, dfsVis)) return true;
        } else if (dfsVis[it]) {
          return true;
        }
      }
      dfsVis[node] = 0;
      return false;
    }
  public:
    bool isCyclic(int N, vector < int > adj[]) {
      int vis[N], dfsVis[N];
      memset(vis, 0, sizeof vis);
      memset(dfsVis, 0, sizeof dfsVis);

      for (int i = 0; i < N; i++) {
        if (!vis[i]) {
          // cout << i << endl; 
          if (checkCycle(i, adj, vis, dfsVis)) {
            return true;
          }
        }
      }
      return false;
    }
};