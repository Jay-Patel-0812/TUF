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
#include<climits>
#define ll long long


// TC: O(N*k)
// SC: O(N)

using namespace std;

ll solve(ll index, vector<ll>& heights, vector<ll>& dp, ll& k){
    if(index == 0){
        return 0;
    }

    ll mini = INT_MAX;
    if(dp[index] != -1) return dp[index];

    for(ll i = index - 1; i >= 0 && i >= index - k; i--){
        mini = min(mini, abs(heights[index] - heights[i]) + solve(i, heights, dp, k));
    }

    dp[index] = mini;

    return dp[index];
}

int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> heights(n, 0);
    for(ll i = 0; i < n; i++){
        cin >> heights[i];
    }
    vector<ll> dp(n, -1);

    solve(n - 1, heights, dp, k);
    cout << dp[n - 1];
    return 0;
}