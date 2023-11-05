
// if you use multiset
// time C:  O((N + E) logN)
// time C:  O(N logN) // i think it should be this
// space C: O(N) + O(N)


// if you use priority queue
// in worst case all nodes will be connected to other node, so that pq will get filled with
// N^2 edges, E = (N - 1) * N, 
// TC: = O(N^2 * log(N^2)) = O(E * 2 * logN)
// space C: O(N^2 = E)
#include<vector>
#include<iostream>
#include<stack>
#include<queue>


vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
	vector<int> dist(V, INT_MAX - 1);
	
	priority_queue<pair<int, int>, vector<pair<int,int> >, greater<pair<int, int> > > minh;
	dist[S] = 0;
	minh.push({0, S});
	
	pair<int, int> temp;
	
	while(!minh.empty()){
		temp = minh.top();
		minh.pop();
		for(auto i : adj[temp.second]){
			if(temp.first + i[1] < dist[i[0]]){
				dist[i[0]] = temp.first + i[1];
				minh.push({dist[i[0]], i[0]});
			}
		}
	}
	
	return dist;
}


using namespace std;
int main(){
	int n=5,m=6,source=1;
	vector<pair<int,int> > g[n+1]; 	// assuming 1 based indexing of graph
	// Constructing the graph
	g[1].push_back({2,2});
	g[1].push_back({4,1});
	g[2].push_back({1,2});
	g[2].push_back({5,5});
	g[2].push_back({3,4});
	g[3].push_back({2,4});
	g[3].push_back({4,3});
	g[3].push_back({5,1});
	g[4].push_back({1,1});
	g[4].push_back({3,3});
	g[5].push_back({2,5});
	g[5].push_back({3,1});	
	// Dijkstra's algorithm begins from here
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>> pq;
	vector<int> distTo(n+1,INT_MAX);//1-indexed array for calculating shortest paths
	distTo[source] = 0;
	pq.push(make_pair(0,source));	// (dist,source)
	while( !pq.empty() ){
		int dist = pq.top().first;
		int prev = pq.top().second;
		pq.pop();
		vector<pair<int,int> >::iterator it;
		for( it = g[prev].begin() ; it != g[prev].end() ; it++){
			int next = it->first;
			int nextDist = it->second;
			if( distTo[next] > distTo[prev] + nextDist){
				distTo[next] = distTo[prev] + nextDist;
				pq.push(make_pair(distTo[next], next));
			}
		}
	}
	cout << "The distances from source " << source << " are : \n";
	for(int i = 1 ; i<=n ; i++)	cout << distTo[i] << " ";
	cout << "\n";
	return 0;
}