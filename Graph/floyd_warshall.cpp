#include<iostream>
#include<vector>
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


using namespace std;
#define ll  long long int
// TC: O(N^3)
// SC: O(1)

// To detect the cycle check for all the diogonal entries, if anyone of them is negative then there is a negative cycle

// if there are no negative cycles in the graph, we can use dijkstra's algorithm on every node which will take TC:  O(N * (N + E)logN)
class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < n; j++){
	            if(matrix[i][j] == -1){
	                matrix[i][j] = 1e9;
	            }
	            
	        }
	        matrix[i][i] = 0;
	    }
	    
	    
	    
	    for(int val = 0; val < n; val++){
	        for(int j = 0; j < n; j++){
	            for(int i = 0; i < n; i++){
	                matrix[j][i] = min(matrix[j][i],
	                                    matrix[j][val] + matrix[val][i]);
	            }
	        }
	    }
	    
	    
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < n; j++){
	            if(matrix[i][j] == 1e9){
	                matrix[i][j] = -1;
	            }
	        }
	    }
	}
};