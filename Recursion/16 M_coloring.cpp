#include<vector>
#include<iostream>
#include<stack>
#include<queue>
#include<map>
#include<unordered_map>
#include<set>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<list>
#include<numeric>
#include<string>
#include<sstream>
#define ll long long


using namespace std;

class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<vector<int> > E;
        for(int i = 0; i < n; i++){
            vector<int> temp;
            for(int j = 0; j < n; j++){
                if(graph[i][j]){
                    temp.push_back(j);
                }
            }
            E.push_back(temp);
        }
        
        vector<int> col(n, -1);
        
        bool ans = solve(E, m, n, 0, col);
        return ans;
        
    }
    
    bool solve(vector<vector<int> >& E, int& m, int& n, int index, vector<int>& col){
        if(index == n){
            return 1;
        }
        bool B = 0;
        
        for(int i = 1; i <= m; i++){
            B = 1;
            for(int j = 0; j < E[index].size(); j++){
                if(col[E[index][j]] == i)  {
                    B = 0;
                    break;
                }  
            }
            
            if(B){
                col[index] = i;
                if(solve(E, m, n, index + 1, col)){
                    return 1;
                }
                else{
                    col[index] = -1;
                }
            }
        }
        
        return false;
    }
};










bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {
  for (int k = 0; k < n; k++) {
    if (k != node && graph[k][node] == 1 && color[k] == col) {
      return false;
    }
  }
  return true;
}
bool solve(int node, int color[], int m, int N, bool graph[101][101]) {
  if (node == N) {
    return true;
  }

  for (int i = 1; i <= m; i++) {
    if (isSafe(node, color, graph, N, i)) {
      color[node] = i;
      if (solve(node + 1, color, m, N, graph)) return true;
      color[node] = 0;
    }

  }
  return false;
}

//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
// bool graphColoring(bool graph[101][101], int m, int N) {
//   int color[N] = {
//     0
//   };
//   if (solve(0, color, m, N, graph)) return true;
//   return false;
// }

// int main() {
//   int N = 4;
//   int m = 3;

//   bool graph[101][101];
//   memset(graph, false, sizeof graph);

//   // Edges are (0, 1), (1, 2), (2, 3), (3, 0), (0, 2)
//   graph[0][1] = 1; graph[1][0] = 1;
//   graph[1][2] = 1; graph[2][1] = 1;
//   graph[2][3] = 1; graph[3][2] = 1;
//   graph[3][0] = 1; graph[0][3] = 1;
//   graph[0][2] = 1; graph[2][0] = 1;
  
//   cout << graphColoring(graph, m, N);

// }