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

// TC: O(N * N)
// SC: O(N * N)

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m - 1].size();
        vector<vector<int> > dp(m, vector<int> (n, -1));

        int ans = solve(0, 0, triangle, m, n, dp);
        return ans;
    }

    int solve(int i, int j, vector<vector<int> > & triangle, int m, int n, vector<vector<int> >& dp){
        if(i == m - 1){
            return triangle[i][j];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int x = solve(i + 1, j, triangle, m, n, dp);
        int y = solve(i + 1, j + 1, triangle, m, n, dp);

        dp[i][j] = triangle[i][j] + min(x, y);

        return dp[i][j];
    }
};




using namespace std;

int minimumPathSum(vector<vector<int> > &triangle, int n){
    vector<int> front(n,0), cur(n,0);
    
    for(int j=0;j<n;j++){
        front[j] = triangle[n-1][j];
    }
    
    for(int i=n-2; i>=0; i--){
        for(int j=i; j>=0; j--){
            
            int down = triangle[i][j]+front[j];
            int diagonal = triangle[i][j]+front[j+1];
            
            cur[j] = min(down, diagonal);
        }
        front=cur;
    }
    
    return front[0];
    
}

int main() {

  vector<vector<int> > triangle{{1},
                                {2,3},
                                {3,6,7},
                                {8,9,6,10}};
                            
  int n = triangle.size();
  
  cout<<minimumPathSum(triangle,n);
}