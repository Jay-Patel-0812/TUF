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

        int n = prices.size(), j, k;

        vector<vector<int> > prev(2, vector<int> (3, 0));

        prev[1][1] = prev[1][2] = prices[n - 1];

        for(int i = n - 2; i >= 0; i--){
            vector<vector<int> > cur(2, vector<int> (3, 0));


            j = 1, k = 0;
            cur[k][j] = max(prev[k][j], prev[k + 1][j] - prices[i]);

            j = 1, k = 1;
            cur[k][j] = max(prev[k - 1][j - 1] + prices[i], prev[k][j]);

            j = 2, k = 0;
            cur[k][j] = max(prev[k][j], prev[k + 1][j] - prices[i]);
            
            j = 2, k = 1;
            cur[k][j] = max(prev[k - 1][j - 1] + prices[i], prev[k][j]);

            // prev = cur;
            for(int i = 0; i < 2; i++){
                prev[i] = cur[i];
            }
        }

        return prev[0][2];
        
    }
};






class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<vector<int>> ahead(2,vector<int> (3,0));
    
        vector<vector<int>> cur(2,vector<int> (3,0));
        
        
        for(int ind = n-1; ind>=0; ind--){
            for(int buy = 0; buy<=1; buy++){
                for(int cap=1; cap<=2; cap++){
                    
                    if(buy==0){// We can buy the stock
                        cur[buy][cap] = max(0+ahead[0][cap], 
                                    -prices[ind] + ahead[1][cap]);
                    }
        
                    if(buy==1){// We can sell the stock
                        cur[buy][cap] = max(0+ahead[1][cap],
                                    prices[ind] + ahead[0][cap-1]);
                    }
                }
            }
            ahead = cur;
        }
        
        return ahead[0][2];
    }
};