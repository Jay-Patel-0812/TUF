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
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // vector<vector<int> > dp(n, vector<int> (n, -1));
        vector<int> cur(n, 0), prev(n, 0);

        for(int i = 0; i < n; i++){
            prev[i] = matrix[n - 1][i]; 
            // dp[n - 1][i] = prev[i];
        }
        int x, y, z, t;
        for(int i = n - 2; i >= 0; i--){
            for(int j = 0; j < n; j++){
                x = y = z = INT_MAX;
                if(j > 0){
                    x = prev[j - 1];
                }
                y = prev[j];
                if(j + 1< n){
                    z = prev[j + 1];
                }
                t = min(x, y);
                t = min(t, z);

                cur[j] = matrix[i][j] + t;
                // dp[i][j] = matrix[i][j] + t;
            }
            prev = cur;
        }

        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            ans = min(ans, prev[i]);
        }

        return ans;
    }
};
