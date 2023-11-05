#include<iostream>
#include<vector>

using namespace std;

class Solution{

public:

    void dfs(vector<int> adj[], int node, vector<int>& ans, vector<bool>& B){
        B[node] = 1;
        ans.push_back(node);

        int n = adj[node].size();
        for(int i = 0; i < n; i++){
            if(!B[adj[node][i]]){
                dfs(adj, adj[node][i], ans, B);
            }
        }
    }

    vector<int> dfsofGraph(int V, vector<int> adj[]){
        vector<bool> B(V + 1, 0);
        vector<int> ans;

        for(int i = 1; i <= V; i++){
            if(!B[i]){
                dfs(adj, i, ans, B);
            }
        }
    }
};