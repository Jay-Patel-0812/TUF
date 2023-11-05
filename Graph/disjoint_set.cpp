#include<iostream>

using namespace std;

int parent[1000];
int rank1[1000];

void makeset(){
    for(int i = 0; i < 1000; i++){
        parent[i] = i;
        rank1[i] = 0;
    }
}

int findPar(int node){
    if(node == parent[node]){
        return node;
    }
    
    return parent[node] = findPar(parent[node]);
}

void union1(int u, int v){
    v = findPar(v);
    u = findPar(u);

    if(rank1[u] < rank1[v]){
        parent[u] = v;
    }
    else if(rank1[u] > rank1[v]){
        parent[v] = u;
    }
    else{
        parent[u] = v;
        rank1[v]++;
    }
}

void main(){
    makeset();
    int m;
    cin >> m;
    while(m--){
        int u, v;
        union1(u, v);
    }

    if(findPar(2) != findPar(3)){
        cout << "They belong to different components";
    }
    else{
        cout << "Same components";
    }
}