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

// TC: O(N * W)
// SC: O(W)

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<int> prev(W + 1, 0);
       
        int pick = 0, notpick;
        for(int i = 0; i < n; i++){
            vector<int> cur(W + 1, 0);
            for(int j = 0; j < W + 1; j++){
               notpick = pick = 0; 
               notpick = prev[j];
               if(wt[i] <= j)
                    pick = val[i] + prev[j - wt[i]];
                cur[j] = max(pick, notpick);
            }
            prev = cur;
        }
        
        return prev[W];
    }
};