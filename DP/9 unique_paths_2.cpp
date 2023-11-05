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

// TC: O(N*M)
// SC: O(N*M)

int mod = 1e9 + 7;

int solve(int i, int j, int n, int m, vector<vector<int> > & mat, vector<vector<int> > &dp){
    if(i == n - 1 && j == m - 1){
        return 1;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int x = 0, y = 0;
    if(i < n - 1 && !mat[i + 1][j]){
        x = solve(i + 1, j, n, m, mat, dp);
    }
    if(j < m - 1 && !mat[i][j + 1]){
        y = solve(i, j + 1, n, m, mat, dp);
    }

    return dp[i][j] = (x + y)%mod;


}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    if(mat[0][0] == -1 || mat[n - 1][m - 1] == -1){
        return 0;
    }
    vector<vector<int> > dp(n, vector<int> (m, -1));
    int ans = solve(0, 0, n, m, mat, dp);
    return ans;
}


int mazeObstaclesUtil(int n, int m, vector<vector<int>> &maze,vector<vector<int>>
 &dp) 
{
  for(int i=0; i<n ;i++){
      for(int j=0; j<m; j++){
          
          //base conditions
          if(i>0 && j>0 && maze[i][j]==-1){
            dp[i][j]=0;
            continue;
          }
          if(i==0 && j==0){
              dp[i][j]=1;
              continue;
          }
          
          int up=0;
          int left = 0;
          
          if(i>0) 
            up = dp[i-1][j];
          if(j>0)
            left = dp[i][j-1];
            
          dp[i][j] = up+left;
      }
  }
  
  return dp[n-1][m-1];

  
}

int mazeObstacles(int n, int m, vector<vector<int> > &maze){
    vector<vector<int> > dp(n,vector<int>(m,-1));
    return mazeObstaclesUtil(n,m,maze,dp);
    
}

int main() {

  vector<vector<int> > maze{{0,0,0},
                            {0,-1,0},
                            {0,0,0}};
                            
  int n = maze.size();
  int m = maze[0].size();
  
  cout<<mazeObstacles(n,m,maze);
}


// TC: O(N * M)
// Space Complexity: O(N)

int mazeObstacles(int n, int m, vector<vector<int> > &maze){

    vector<int> prev(m,0);
    for(int i=0; i<n; i++){
        vector<int> temp(m,0);
        for(int j=0; j<m; j++){
            if(i>0 && j>0 && maze[i][j]==-1){
                temp[j]=0;
                continue;
            }
            if(i==0 && j==0){
                temp[j]=1;
                continue;
            }
            
            int up=0;
            int left =0;
            
            if(i>0)
                up = prev[j];
            if(j>0)
                left = temp[j-1];
                
            temp[j] = up + left;
        }
        prev = temp;
    }
    
    return prev[n-1];

    
}

int main() {

  vector<vector<int> > maze{{0,0,0},
                            {0,-1,0},
                            {0,0,0}};
                            
  int n = maze.size();
  int m = maze[0].size();
  
  cout<<mazeObstacles(n,m,maze);
}