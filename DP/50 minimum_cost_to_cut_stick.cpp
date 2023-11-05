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


int cost(int n, int c, vector<int> &cuts){
    
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end());
    
    vector<vector<int>> dp(c+2,vector<int>(c+2,0));
    
    for(int i=c; i>=1; i--){
        for(int j=1; j<=c; j++){
            
            if(i>j) continue;
            
            int mini = INT_MAX;
    
            for(int ind=i; ind<=j; ind++){
        
                int ans = cuts[j+1] - cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];
        
                mini = min(mini, ans);
        
            }
    
            dp[i][j] = mini;
        }
    }
    
    return dp[1][c];

}


class Solution {
public:

    int solve(int i, int j, vector<int>& cuts, vector<vector<int> >& dp){
        if(i > j){
            return 0;
        }
        if(i == j){
            return cuts[j + 1] - cuts[i - 1];
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int t = INT_MAX, temp;
        for(int k = i; k <= j; k++){
            temp = solve(i, k - 1, cuts, dp) + solve(k + 1, j, cuts, dp) + 
                    cuts[j + 1] - cuts[i - 1];
            t = min(t, temp);
        }

        dp[i][j] = t;
        return t;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());
        int size = cuts.size();
        vector<vector<int> > dp(size, vector<int> (size, -1));

        int t = solve(1, cuts.size() - 1 - 1, cuts, dp);

        return t;
    }
};