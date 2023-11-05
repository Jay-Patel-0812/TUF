#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<iostream>

using namespace std;

// TC: O(N) * O(E)
// SC: O(N)

int isNegativeWeightCycle(int n, vector<vector<int>>edges){
    vector<int> dist(n, 1000000000);
    dist[0] = 0;
    int n1;
    int n2;
    int e;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < edges.size(); j++){
            n1 = edges[j][0];
            n2 = edges[j][1];
            e = edges[j][2];
            if(e + dist[n1] < dist[n2]){
                dist[n2] = e + dist[n1];
            }
        }
    }
    int count = 0;
    
    for(int j = 0; j < edges.size(); j++){
        n1 = edges[j][0];
        n2 = edges[j][1];
        e = edges[j][2];
        if(e + dist[n1] < dist[n2]){
            dist[n2] = e + dist[n1];
            count++;
            break;
        }
    }
    
    return count;
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

int main(){
    int N=6,m=7;
    vector<node> edges; 
	edges.push_back(node(0,1,5));
	edges.push_back(node(1,2,-2));
	edges.push_back(node(1,5,-3));
	edges.push_back(node(2,4,3));
	edges.push_back(node(3,2,6));
	edges.push_back(node(3,4,-2));
	edges.push_back(node(5,3,1));
    int src=0;
    int inf = 10000000; 
    vector<int> dist(N, inf); 
    dist[src] = 0; 
    for(int i = 1;i<=N-1;i++) {
        for(auto it: edges) {
            if(dist[it.u] + it.wt < dist[it.v]) {
                dist[it.v] = dist[it.u] + it.wt; 
            }
        }
    }

    int fl = 0; 
    for(auto it: edges) {
        if(dist[it.u] + it.wt < dist[it.v]) {
            cout << -1; 
            fl = 1; 
            break; 
        }
    }
    
    if(!fl) {
        for(int i = 0;i<N;i++) {
            cout << dist[i]<<" ";
        }
    }
    return 0;
}