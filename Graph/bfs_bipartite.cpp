#include<iostream>
#include<queue>
#include<vector>

// Time C: O(N + E)
// Space C: O(N + E) + O(N) + O(N)
// auxilary space: O(N)

using namespace std;

bool isBipartite(int V, vector<int> adj[]){
    vector<int> col(V, -1);
    
    for(int i = 0; i < V; i++){
        if(col[i] == -1){
            queue<int> q;
            q.push(i);
            col[i] = 0;
            int temp;
            
            while(!q.empty()){
                temp = q.front();
                q.pop();
                for(auto i : adj[temp]){
                    if(col[i] == -1){
                        if(col[temp]){
                            col[i] = 0;
                        }
                        else{
                            col[i] = 1;
                        }
                        q.push(i);
                    }
                    else if(col[i] == col[temp]){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}



bool bipartiteBfs(int src, vector<int> adj[], int color[]) {
    queue<int>q;
    q.push(src); 
    color[src] = 1; 
    while(!q.empty()) {
        int node = q.front(); 
        q.pop();
        
        for(auto it : adj[node]) {
            if(color[it] == -1) {
                color[it] = 1 - color[node]; 
                q.push(it); 
            } else if(color[it] == color[node]) {
                return false; 
            }
        }
    }
    return true; 
}

bool checkBipartite(vector<int> adj[], int n) {
    int color[n];
    memset(color, -1, sizeof color); 
    for(int i = 0;i<n;i++) {
        if(color[i] == -1) {
            if(!bipartiteBfs(i, adj, color)) {
                return false;
            }
        }
    }
    return true; 
}