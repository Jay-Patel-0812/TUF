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

// TC: O(N)
// SC: O(N)

ll solve(vector<int>& valueInHouse, vector<ll>& dp, ll index, ll start){
    if(index == start){
        return valueInHouse[start];
    }
    if(index < start){
        return 0;
    }

    ll one, two;
    if(dp[index] != -1){
        return dp[index];
    }

    one = solve(valueInHouse, dp, index - 1, start);
    two = solve(valueInHouse, dp, index - 2, start) + valueInHouse[index];

    dp[index] = max(one, two);
    return dp[index];
}

long long int houseRobber(vector<int>& valueInHouse)
{
    ll n = valueInHouse.size();
    if(n == 1){
        return valueInHouse[0];
    }
    vector<ll> dp1(n, -1), dp2(n, -1);
    bool B;
    ll ans1 = solve(valueInHouse, dp1, n - 2, 0);
    ll ans2 = solve(valueInHouse, dp2, n - 1, 1);
    return max(ans1, ans2);
}