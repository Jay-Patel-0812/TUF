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
    int minInsertions(string s) {
        string r = "";
        int n = s.size();
        for(int i = 0; i < n; i++){
            r += s[n - i - 1];
        }
        vector<int> prev(n + 1, 0);

        for(int i = 1; i < n + 1; i++){
            vector<int> cur(n + 1, 0);
            for(int j = 1; j < n + 1; j++){
                if(s[i - 1] == r[j - 1]){
                    cur[j] = prev[j - 1] + 1;
                }
                else{
                    cur[j] = max(cur[j - 1], prev[j]);
                }
            }

            prev = cur;
        }

        return (n - prev[n]);
    }
};