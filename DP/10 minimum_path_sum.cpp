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

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        ll n = grid[0].size();
        ll m = grid.size();
        vector<vector<ll> > dp(m, vector<ll> (n, -1));
        ll ans = solve(0, 0, grid, m, n, dp);
        return ans;
    }

    ll solve(ll i, ll j, vector<vector<int> >& grid, ll m, ll n, vector<vector<ll > >& dp){
        if(i == m - 1 && j == n - 1){
            return grid[i][j];
        }
        if(i >= m || j >= n){
            return INT_MAX;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        ll x = INT_MAX, y = INT_MAX;

        x = solve(i + 1, j, grid, m, n, dp);

        y = solve(i, j + 1, grid, m, n, dp);


        dp[i][j] = grid[i][j] + min(x, y);
        return dp[i][j];
    }
};




// TC: O(N*M)
// SC: O(N)


using namespace std;

int minSumPath(int n, int m, vector<vector<int> > &matrix){
      vector<int> prev(m,0);
    for(int i=0; i<n ; i++){
        vector<int> temp(m,0);
        for(int j=0; j<m; j++){
            if(i==0 && j==0) temp[j] = matrix[i][j];
            else{
                
                int up = matrix[i][j];
                if(i>0) up += prev[j];
                else up += 1e9;
                
                int left = matrix[i][j];
                if(j>0) left+=temp[j-1];
                else left += 1e9;
                
                temp[j] = min(up,left);
            }
        }
        prev=temp;
    }
    
    return prev[m-1];
    
}



int main() {

  vector<vector<int> > matrix{{5,9,6},
                            {11,5,2}};
                            
  int n = matrix.size();
  int m = matrix[0].size();
  
  cout<<minSumPath(n,m,matrix);
}