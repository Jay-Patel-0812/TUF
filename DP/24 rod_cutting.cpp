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

// TC: O(N * N)
// SC: O(N)

class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<int> V(n + 1, 0);
        
        int pick, notpick = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n + 1; j++){
                pick = notpick = 0;
                
                notpick = V[j];
                if(j >= i + 1){
                    pick = price[i] + V[j - i - 1];
                }
                
                V[j] = max(pick, notpick);
            }
        }
        
        return V[n];
    }
};