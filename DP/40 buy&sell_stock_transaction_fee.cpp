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
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> prev(2, 0), cur(2, 0);
        int n = prices.size();

        for(int i = n - 1; i >= 0; i--){
            cur[0] = max(prev[0], prev[1] - prices[i]);
            cur[1] = max(prev[1], prev[0] + prices[i] - fee);

            prev = cur;
        }

        return prev[0];
    }
};