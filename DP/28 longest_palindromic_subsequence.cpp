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
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string r = "";

        for(int i = n - 1; i >= 0; i--){
            r += s[i];
        }

        vector<int> prev(n + 1, 0);
        
        for(int i = 1; i < n + 1; i++){
            vector<int> cur(n + 1, 0);
            for(int j = 1; j < n + 1; j++){
                if(s[j - 1] == r[i - 1]){
                    cur[j] = prev[j - 1] + 1;
                }
                else{
                    cur[j] = max(prev[j], cur[j - 1]);
                }
            }

            prev = cur;
        }

        return prev[n];
    }
};