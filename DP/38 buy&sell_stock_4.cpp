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
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size(), l;
        vector<vector<int> > prev(2, vector<int> (k + 1, 0));

        for(int i = 1; i <= k; i++){
            prev[1][i] = prices[n - 1];
        }

        for(int i = n - 2; i >= 0; i--){
            vector<vector<int> > cur(2, vector<int> (k + 1, 0));
            for(int j = 1; j <= k; j++){
                l = 0;
                cur[l][j] = max(prev[l + 1][j] - prices[i], prev[l][j]);

                l = 1;
                cur[l][j] = max(prev[l - 1][j - 1] + prices[i], prev[l][j]);
            }

            prev[0] = cur[0];
            prev[1] = cur[1];
        }

        return prev[0][k];
    }
};