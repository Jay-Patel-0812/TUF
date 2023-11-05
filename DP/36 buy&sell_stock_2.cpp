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

class Solution1{
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<int> prev(2, 0);

        prev[0] = 0;
        prev[1] = prices[n - 1];

        for(int i = n - 2; i >= 0; i--){
            vector<int> cur(2, 0);
            cur[0] = max(prev[1] - prices[i], prev[0]);
            cur[1] = max(prev[0] + prices[i], prev[1]);
            prev = cur;
        }

        return prev[0];
    }
};





class Solution {
public:
    int solve(vector<int>& prices, int& n, vector<vector<int> >& dp, int index, int bought){
        if(index == n){
            return 0;
        }
        if(dp[index][bought] != -1){
            return dp[index][bought];
        }

        int m1 = 0, m2 = 0;
        if(bought){
            m1 = solve(prices, n, dp, index + 1, 0) + prices[index];
            m2 = solve(prices, n, dp, index + 1, 1);

            dp[index][bought] = max(m1, m2);
        }
        else{
            m1 = solve(prices, n, dp, index + 1, 0);
            m2 = solve(prices, n, dp, index + 1, 1) - prices[index];

            dp[index][bought] = max(m1, m2);
        }

        return dp[index][bought];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int> > dp(n, vector<int> (2, -1));
        
        solve(prices, n, dp, 0, 0);
        return dp[0][0];
    }
};