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

// TC: O(amount * N)
// SC: O(amount)

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> prev(amount + 1, INT_MAX - 1);

        prev[0] = 0;
        int n = coins.size();

        for(int i = 0; i < n; i++){
            for(int j = 1; j < amount + 1; j++){
                if(coins[i] <= j)
                    prev[j] = min(prev[j], prev[j - coins[i]] + 1);
            }
        }

        if(prev[amount] == INT_MAX - 1){
            return -1;
        }
        return prev[amount];
    }
};