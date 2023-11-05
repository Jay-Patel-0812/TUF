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

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<int> prev(W + 1, 0);
        
        int pick, notpick;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < W + 1; j++){
                pick = notpick = 0;
                notpick = prev[j];
                if(wt[i] <= j){
                    pick = val[i] + prev[j - wt[i]];
                }
                prev[j] = max(pick, notpick);
            }
        }
        
        return prev[W];
    }
};