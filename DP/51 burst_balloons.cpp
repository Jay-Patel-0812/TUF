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

#define ll long long

class Solution {
public:
    ll maxCoins(vector<int>& nums) {
        vector<ll> V;
        V.push_back(1);
        for(int i = 0; i < nums.size(); i++){
            V.push_back(nums[i]);
        }
        V.push_back(1);
        
        ll n = V.size();
        vector<vector<ll> > dp(n, vector<ll> (n, 0));

        ll maxi, t;
        for(int i = n - 1; i >= 1; i--){
            for(int j = i + 1; j < n; j++){
                maxi = INT_MIN;
                for(int k = i; k < j; k++){
                    t = V[i - 1] * V[k] * V[j] + dp[i][k] + dp[k + 1][j];
                    if(t > maxi){
                        maxi = t;
                    }
                }

                dp[i][j] = maxi;
            }
        }

        return dp[1][n - 1];
    }
};





class Solution {
public:
    int solve(vector<int>& V, int i, int j, vector<vector<int> >& dp){
        if(i >= j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int maxi = INT_MIN, t;
        for(int k = i; k < j; k++){
            t = V[i - 1] * V[k] * V[j] + solve(V, i, k, dp) + solve(V, k + 1, j, dp);
            if(t > maxi){
                maxi = t;
            }
        }

        return dp[i][j] = maxi;
    }

    int maxCoins(vector<int>& nums) {
        vector<int> V;
        V.push_back(1);
        for(int i = 0; i < nums.size(); i++){
            V.push_back(nums[i]);
        }
        V.push_back(1);
        
        int n = V.size();
        vector<vector<int> > dp(n, vector<int> (n, -1));

        solve(V, 1, n - 1, dp);

        return dp[1][n - 1];
    }
};