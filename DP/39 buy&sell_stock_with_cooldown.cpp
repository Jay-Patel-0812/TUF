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
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1){
            return 0;
        }

        vector<vector<int> > prev(2, vector<int> (2, 0));

        for(int i = n - 1; i >= 0; i--){
            vector<vector<int> > cur(2, vector<int> (2, 0));
            cur[0][1] = prev[0][0];
            cur[1][1] = prev[1][0];

            cur[0][0] = max(prev[1][0] - prices[i], prev[0][0]);
            cur[1][0] = max(prev[0][1] + prices[i], prev[1][0]);

            prev[0] = cur[0];
            prev[1] = cur[1];
        }

        return prev[0][0];
    }
};



// why does below code run, in the loop there should be n - 3 instead of n - 2, still it gives correct answer

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1){
            return 0;
        }

        vector<vector<int> > prev(2, vector<int> (2, 0));

        prev[1][1] = prices[n - 1];
        prev[1][0] = max(prices[n - 1], prices[n - 2]);

        for(int i = n - 2; i >= 0; i--){
            vector<vector<int> > cur(2, vector<int> (2, 0));
            cur[0][1] = prev[0][0];
            cur[1][1] = prev[1][0];

            cur[0][0] = max(prev[1][0] - prices[i], prev[0][0]);
            cur[1][0] = max(prev[0][1] + prices[i], prev[1][0]);

            prev[0] = cur[0];
            prev[1] = cur[1];
        }

        return prev[0][0];
    }
};