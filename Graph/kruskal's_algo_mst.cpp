// Time C:  O(MlogM) for sorting the queue + O(M * 4alpha) for comparing the components
// Space C: O(M) for queue + O(N) for rank array + O(N) for parent array
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<cstring>

using namespace std;


int findPar(int node, vector<int> & par){
    if(node == par[node]){
        return node;
    }
    
    return par[node] = findPar(par[node], par);
}

void union1(int v, int u, vector<int>& rank, vector<int>& par){
    v = findPar(v, par);
    u = findPar(u, par);
    
    if(rank[v] > rank[u]){
        par[u] = v;
    }
    else if(rank[u] > rank[v]){
        par[v] = u;
    }
    else{
        par[v] = u;
        rank[u]++;
    }
}



int spanningTree(int V, vector<vector<int> > adj[]){
    vector<int> rank(V, 0), par(V);
    for(int i = 0; i < V; i++){
        par[i] = i;
    }
    
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;
    pair<int, pair<int, int> > temp;
    int n1, n2, e;
    for(int i = 0; i < V; i++){
        for(int j = 0; j < adj[i].size(); j++){
            n1 = i;
            n2 = adj[i][j][0];
            e = adj[i][j][1];
            temp.first = e;
            temp.second.first = n1;
            temp.second.second = n2;
            
            pq.push(temp);
        }
    }
    
    int sum = 0;
    
    while(!pq.empty()){
        temp = pq.top();
        pq.pop();
        e = temp.first;
        n1 = temp.second.first;
        n2 = temp.second.second;
        if(findPar(n1, par) != findPar(n2, par)){
            union1(n1, n2, rank, par);
            sum += e;
        }
    }
    
    return sum;
    
}











struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b) {
    return a.wt < b.wt; 
}

int findPar(int u, vector<int> &parent) {
    if(u == parent[u]) return u; 
    return parent[u] = findPar(parent[u], parent); 
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findPar(u, parent);
    v = findPar(v, parent);
    if(rank[u] < rank[v]) {
    	parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
    	parent[v] = u; 
    }
    else {
    	parent[v] = u;
    	rank[u]++; 
    }
}
int main(){
	int N=5,m=6;
	vector<node> edges; 
	edges.push_back(node(0,1,2));
	edges.push_back(node(0,3,6));
	edges.push_back(node(1,0,2));
	edges.push_back(node(1,2,3));
	edges.push_back(node(1,3,8));
	edges.push_back(node(1,4,5));
	edges.push_back(node(2,1,3));
	edges.push_back(node(2,4,7));
	edges.push_back(node(3,0,6));
	edges.push_back(node(3,1,8));
	edges.push_back(node(4,1,5));
	edges.push_back(node(4,2,7));
	sort(edges.begin(), edges.end(), comp); 
	
	vector<int> parent(N);
	for(int i = 0;i<N;i++) 
	    parent[i] = i; 
	vector<int> rank(N, 0); 
	
	int cost = 0;
	vector<pair<int,int>> mst; 
	for(auto it : edges) {
	    if(findPar(it.v, parent) != findPar(it.u, parent)) {
	        cost += it.wt; 
	        mst.push_back({it.u, it.v}); 
	        unionn(it.u, it.v, parent, rank); 
	    }
	}
	cout << cost << endl;
	for(auto it : mst) cout << it.first << " - " << it.second << endl; 
	return 0;
}