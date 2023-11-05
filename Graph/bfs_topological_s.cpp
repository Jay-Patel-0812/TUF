
// this algo is also known as kahn's algo

// Time C: O(N + E)
// Space C: O(N) + O(N)
// Auxilary Space C: 

#include<vector>
#include<iostream>
#include<queue>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[]){
    vector<int> ans;
    
    vector<int> indeg(V, 0);
    for(int i = 0; i < V; i++){
        for(auto j: adj[i]){
            indeg[j]++;
        }
    }
    
    queue<int> q;
    
    for(int i = 0; i < V; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }
    
    int node;
    
    while(!q.empty()){
        node = q.front();
        ans.push_back(node);
        q.pop();
        for(auto i : adj[node]){
            indeg[i]--;
            if(indeg[i] == 0){
                q.push(i);
            }
        }
    }
    
    return ans;
}



vector<int> topo(int N, vector<int> adj[]) {
        queue<int> q; 
	    vector<int> indegree(N, 0); 
	    for(int i = 0;i<N;i++) {
	        for(auto it: adj[i]) {
	            indegree[it]++; 
	        }
	    }
	    
	    for(int i = 0;i<N;i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }
	    vector<int> topo;
	    while(!q.empty()) {
	        int node = q.front(); 
	        q.pop(); 
	        topo.push_back(node);
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
	    return topo;
	}

