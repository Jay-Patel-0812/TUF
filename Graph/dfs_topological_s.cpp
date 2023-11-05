// Time C: O(N + E)
// Space C: O(N) + O(N)(for the stack)
// Auxilary Space C: O(N)

#include<vector>
#include<iostream>
#include<stack>

using namespace std;


void dfs(int V, vector<int> adj[], vector<int>& vis, stack<int>& st, int node){
    vis[node] = 1;
    for(auto i : adj[node]){
        if(!vis[i]){
            dfs(V, adj, vis, st, i);
        }
    }
    st.push(node);
}

//Function to return list containing vertices in Topological order. 
vector<int> topoSort(int V, vector<int> adj[]) 
{
    vector<int> vis(V, 0);
    stack<int> st;
    for(int i = 0; i < V; i++){
        if(!vis[i]){
            dfs(V, adj, vis, st, i);
        }
    }
    
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}






class Solution {
  void findTopoSort(int node, vector < int > & vis, stack < int > & st, vector < int > adj[]) {
    vis[node] = 1;

    for (auto it: adj[node]) {
      if (!vis[it]) {
        findTopoSort(it, vis, st, adj);
      }
    }
    st.push(node);
  }
  public:
    vector < int > topoSort(int N, vector < int > adj[]) {
      stack < int > st;
      vector < int > vis(N, 0);
      for (int i = 0; i < N; i++) {
        if (vis[i] == 0) {
          findTopoSort(i, vis, st, adj);
        }
      }
      vector < int > topo;
      while (!st.empty()) {
        topo.push_back(st.top());
        st.pop();
      }
      return topo;

    }
};