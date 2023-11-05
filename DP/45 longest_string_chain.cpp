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

#define ll long long

bool comp(string s1, string s2){
    return s1.size() < s2.size();
}

class Solution {
public:

    bool check(string s1, string s2){
        if(s1.size() != s2.size() - 1)  return 0;

        int n1 = s1.size(), n2 = s2.size(), p1 = 0, p2 = 0;

        while(p2 < n2){
            if(s1[p1] != s2[p2]){
                p2++;
            }
            else{
                p1++;
                p2++;
            }
        }

        if(p1 == n1 && p2 == n2){
            return 1;
        }

        return 0;

    }

    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp);

        int n = words.size(), max = 1;
        vector<int> V(n, 1);
        for(ll i = 1; i < n; i++){
            for(ll j = 0; j < i; j++){
                if(check(words[j], words[i])){
                    if(V[i] < V[j] + 1){
                        V[i] = V[j] + 1;
                        if(max < V[i]){
                            max = V[i];
                        }
                    }
                }
            }
        }

        return max;
    }
};