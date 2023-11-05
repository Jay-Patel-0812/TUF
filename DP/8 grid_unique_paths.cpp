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
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(m, vector<int> (n, 0));
        dp[0][0] = 1;
        int x = 0, y = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0;j < n; j++){
                x = 1, y = 1;
                if(i > 0){
                    x = dp[i - 1][j];
                }
                
                if(j > 0){
                    y = dp[i][j - 1];
                }
                dp[i][j] = x + y;
                if(i == 0 || j == 0){
                    dp[i][j] = 1;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};

int solve(int i, int j, int m, int n, vector<vector<int> >& B){
	if(i == m - 1 && j == n - 1){
		return 1;
	}
	if(B[i][j] != -1){
		return B[i][j];
	}
	int x = 0, y = 0;
	if(i + 1 < m){
		x = solve(i + 1, j, m, n, B);
	}
	if(j + 1 < n){
		y = solve(i, j + 1, m, n, B);
	}

	return B[i][j] = x + y;
}

int uniquePaths(int m, int n) {
	vector<vector<int> > B(m, vector<int> (n, -1));
	ll ans = solve(0, 0, m, n, B);
	return ans;
}



int countWaysUtil(int i, int j, vector<vector<int> > &dp) {
  if(i==0 && j == 0)
    return 1;
  if(i<0 || j<0)
    return 0;
  if(dp[i][j]!=-1) return dp[i][j];
    
  int up = countWaysUtil(i-1,j,dp);
  int left = countWaysUtil(i,j-1,dp);
  
  return dp[i][j] = up+left;
  
}

int countWays(int m, int n){
    vector<vector<int> > dp(m,vector<int>(n,-1));
    return countWaysUtil(m-1,n-1,dp);
    
}

int main() {

  int m=3;
  int n=2;
  
  cout<<countWays(m,n);
}




// Time Complexity: O(M*N)
// Space Complexity: O(N)

using namespace std;

int countWays(int m, int n){
    vector<int> prev(n,0);
    for(int i=0; i<m; i++){
        vector<int> temp(n,0);
        for(int j=0; j<n; j++){
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

  int m=3;
  int n=2;
  
  cout<<countWays(m,n);
}