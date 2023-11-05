#include<iostream>
#include<vector>
#include<queue>
// #include<bits/stdc++.h>

// Time Complexity: O(V+E), where V is the number of nodes and E is the number of edges.
// Auxiliary Space: O(V)

using namespace std;

class solution{

public:
    vector<int>bfsofGraph(int V, vector<int> adj[]){
        vector<int> bfs;
        vector<int> vis(V + 1, 0);

        for(int i = 1; i <= V; i++){
            if(!vis[i]){
                queue<int> q;
                q.push(i);
                vis[i] = 1;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    bfs.push_back(node);

                    for(auto it : adj[node]){
                        if(!vis[it]){
                            q.push(it);
                            vis[it] = 1;
                        }
                    }
                }
            }
        }
    }
};