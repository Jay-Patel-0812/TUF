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

class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int max = 0;
        vector<int> prev(n + 1, 0);
        
        for(int i = 1; i < m + 1; i++){
            vector<int> cur(n + 1, 0);
            for(int j = 1; j < n + 1; j++){
                if(S1[j - 1] == S2[i - 1]){
                    cur[j] = prev[j - 1] + 1;
                    if(cur[j] > max){
                        max = cur[j];
                    }
                }
                else{
                    cur[j] = 0;
                }
            }
            prev = cur;
        }
        
        return max;
    }
};