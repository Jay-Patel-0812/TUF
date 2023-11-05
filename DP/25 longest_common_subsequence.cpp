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
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.size();
        int l2 = text2.size();

        if(l1 > l2){
            string temp = text2;
            int t = l2;
            text2 = text1;
            l2 = l1;
            l1  = t;
            text1 = temp;
        }

        vector<int> prev(l1 + 1, 0);

        for(int i = 1; i < l2 + 1; i++){
            vector<int> cur(l1 + 1, 0);
            for(int j = 1; j < l1 + 1; j++){
                if(text1[j - 1] == text2[i - 1]){
                    cur[j] = 1 + prev[j - 1];
                }
                else{
                    cur[j] = max(cur[j - 1], prev[j]);
                }
            }
            prev = cur;
        }

        return prev[l1];
    }
};