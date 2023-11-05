#include<vector>
#include<iostream>
#include<queue>

using namespace std;

bool isCyclic(int V, vector<int> adj[]){
    // vector<int> ans;
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
    int count = 0;
    
    
    while(!q.empty()){
        node = q.front();
        // ans.push_back(node);
        count++;
        q.pop();
        for(auto i : adj[node]){
            indeg[i]--;
            if(indeg[i] == 0){
                q.push(i);
            }
        }
    }
    // if there is a cycle in the graph then, count will be less than V
    if(count == V) return false;
    
    return true;
    
    // return ans;
}


class Solution {
public:
	bool isCyclic(int N, vector<int> adj[]) {
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
	    int cnt = 0;
	    while(!q.empty()) {
	        int node = q.front(); 
	        q.pop(); 
	        cnt++; 
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
	    if(cnt == N) return false; 
	    return true; 
	}
};