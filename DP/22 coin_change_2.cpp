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

// TC: O(N * amount)
// SC: O(amount)

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(!amount) return 1;

        vector<int> prev(amount + 1, 0);
        prev[0] = 1;
        int n = coins.size();

        int pick =0 , notpick = 0;
        for(int i = 0; i < n; i++){
            vector<int> cur(amount + 1, 0);
            for(int j = 0; j < amount + 1; j++){
                pick = notpick = 0;
                notpick = prev[j];
                if(coins[i] <= j){
                    pick = cur[j - coins[i]];
                }
                cur[j] = pick + notpick;
            }
            prev = cur;
        }


        return prev[amount];
    }
};