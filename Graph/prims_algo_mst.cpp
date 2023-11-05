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

int spanningTree(int V, vector<vector<int>> adj[])          // O(N^2)
{
    vector<int> dist(V, INT_MAX), par(V, -1);
    vector<bool> mst(V, false);
    int count = V - 1;
    int node = 0;
    mst[node] = true;
    dist[node] = 0;
    par[node] = -1;
    int node1;
    int edge1;
    int mini = INT_MAX;
    int node2;
    while(count > 0){
        mini = INT_MAX;
        for(int i = 0; i < adj[node].size(); i++){
            node1 = adj[node][i][0];
            edge1 = adj[node][i][1];
            if(dist[node1] >= edge1 && !mst[node1]){
                dist[node1] = edge1;
                par[node1] = node;  //  i think this line should be here instead of the line 48
            }
        }
        
        for(int i = 0; i < V; i++){
            if(!mst[i]){
                if(mini >= dist[i]){
                    mini = dist[i];
                    node2 = i;
                }
            }
        }
        
        mst[node2] = true;
        dist[node2] = mini;                 // is this line necessary ?
        // par[node2] = node;              // should this line be here ?
        node = node2;
        count--;
    }
    
    int sum = 0;
    for(int i = 0; i < V; i++){
        sum += dist[i];
    }
    
    return sum;
    
}

int spanningTree(int V, vector<vector<int>> adj[])          // O(E * logN), it is calculated using worst case, in which each node is connected to each and every other node
{
    vector<int> dist(V, INT_MAX), par(V, -1);
    vector<bool> mst(V, false);
    int count = V - 1;
    int node = 0;
    mst[node] = true;
    dist[node] = 0;
    par[node] = -1;
    int node1;
    int edge1;
    int mini = INT_MAX;
    int node2;
    
    priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pair<int, int> temp;
    while(count > 0){
        mini = INT_MAX;
        for(int i = 0; i < adj[node].size(); i++){
            node1 = adj[node][i][0];
            edge1 = adj[node][i][1];
            if(dist[node1] >= edge1 && !mst[node1]){
                dist[node1] = edge1;
                temp = {edge1, node1};
                par[node1] = node;  //  i think this line should be here instead of the line 102
                pq.push(temp);
            }
        }
        
        temp = pq.top();
        pq.pop();
        
        while(mst[temp.second]){
            temp = pq.top();
            pq.pop();
        }
        
        node2 = temp.second;
        
        mst[node2] = true;
        dist[node2] = temp.first;   // is this really neccesary ?
        // par[node2] = node;      // should this line be here ?
        node = node2;
        count--;
    }
    
    int sum = 0;
    for(int i = 0; i < V; i++){
        sum += dist[i];
    }
    
    return sum;
    
}




int main(){                                             // O(N ^2)
	int N=5,m=6;
	vector<pair<int,int> > adj[N]; 


	adj[0].push_back({1,2});
	adj[0].push_back({3,6});
	adj[1].push_back({0,2});
	adj[1].push_back({2,3});
	adj[1].push_back({3,8});
	adj[1].push_back({4,5});
	adj[2].push_back({1,3});
	adj[2].push_back({4,7});
	adj[3].push_back({0,6});
	adj[3].push_back({1,8});
	adj[4].push_back({1,5});
	adj[4].push_back({2,7});
	
    int parent[N];
    int key[N]; 
    bool mstSet[N]; 
  
    for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
    key[0] = 0; 
    parent[0] = -1; 
    int ansWeight = 0;
    for (int count = 0; count < N - 1; count++)
    { 
        
        int mini = INT_MAX, u; 
  
        for (int v = 0; v < N; v++) 
{
            if (mstSet[v] == false && key[v] < mini) 
                mini = key[v], u = v; 
}
                 mstSet[u] = true; 
        
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) 
                parent[v] = u, key[v] = weight; 
        }
            
    } 
    
    
    for (int i = 1; i < N; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
	return 0;
}





int main(){                                 // O(N*logN)
	int N=5,m=6;
	vector<pair<int,int> > adj[N]; 
	adj[0].push_back({1,2});
	adj[0].push_back({3,6});
	adj[1].push_back({0,2});
	adj[1].push_back({2,3});
	adj[1].push_back({3,8});
	adj[1].push_back({4,5});
	adj[2].push_back({1,3});
	adj[2].push_back({4,7});
	adj[3].push_back({0,6});
	adj[3].push_back({1,8});
	adj[4].push_back({1,5});
	adj[4].push_back({2,7});



	
	
    int parent[N]; 
      
    int key[N]; 
      
    bool mstSet[N]; 
  
    for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
    
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;

    key[0] = 0; 
    parent[0] = -1; 
    pq.push({0, 0});

    while(!pq.empty())
    { 
        int u = pq.top().second; 
        pq.pop(); 
        
        mstSet[u] = true; 
        
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) {
                parent[v] = u;
	    key[v] = weight; 
                pq.push({key[v], v});    
            }
        }
            
    } 
    
    for (int i = 1; i < N; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
	return 0;
}