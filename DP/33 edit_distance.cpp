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


    int minDistance(string word1, string word2) {
        int l1 = word1.size(), l2 = word2.size();

        // vector<vector<int> > dp(l1 + 1, vector<int> (l2 + 1, -1));

        vector<int> prev(l2 + 1, 0);

        for(int i = 0; i < l2 + 1; i++){
            prev[i] = i;
        }

        for(int i = 1; i < l1 + 1; i++){
            vector<int> cur(l2 + 1, 0);
            cur[0] = i;
            for(int j = 1; j < l2 + 1; j++){
                if(word1[i - 1] == word2[j - 1]){
                    cur[j] = prev[j - 1] ;
                }
                else{
                    cur[j] = 1 + min(cur[j - 1], min(prev[j - 1], prev[j]));
                }
            }
            prev = cur;
        }
        
        return prev[l2];
    }
};







class Solution {
public:
    int solve(string word1,string word2, int l1, int l2, vector<vector<int> >& dp){
        if(l1 <= 0){
            return l2;
        }
        if(l2 <= 0){
            return l1;
        }

        if(dp[l1][l2] != -1){
            return dp[l1][l2];
        }

        if(word1[l1 - 1] == word2[l2 - 1]){
            dp[l1][l2] = solve(word1, word2, l1 - 1, l2 - 1, dp);
        }
        else{
            dp[l1][l2] = min(solve(word1, word2, l1 - 1, l2 - 1, dp), min(solve(word1, word2, l1 - 1, l2, dp), solve(word1, word2, l1, l2 - 1, dp))) + 1;
        }

        return dp[l1][l2];
    }


    int minDistance(string word1, string word2) {
        int l1 = word1.size(), l2 = word2.size();

        vector<vector<int> > dp(l1 + 1, vector<int> (l2 + 1, -1));
        
        return solve(word1, word2, l1, l2, dp);
    }
};