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



int max(int a, int b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int l1 = str1.size();
        int l2 = str2.size();
        
        int t[l1 + 1][l2 + 1];
        for(int i = 0; i < l1 + 1; i++){
            t[i][0] = 0;
        }
        
        for(int i = 0; i < l2 + 1; i++){
            t[0][i] = 0;
        }
        
        for(int i = 1; i < l1 + 1; i++){
            for(int j = 1; j < l2 + 1; j++){
                if(str1[i - 1] == str2[j - 1]){
                    t[i][j] = 1 + t[i - 1][j - 1];
                }
                else{
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                }
            }
        }
        
        int i = l1;
        int j = l2;
        string str;
        
        while(i > 0 && j > 0){
            if(str1[i - 1] == str2[j - 1]){
                str.push_back(str1[i - 1]);
                i--;
                j--;
            }
            else{
                if(t[i - 1][j] > t[i][j - 1]){
                    i--;
                }
                else{
                    j--;
                }
            }
        }
        
        reverse(str.begin(), str.end());
        
        i = 0;
        j = 0;
        int k = 0;
        string ans = "";
        while(i < l1 && j < l2 && k < str.size()){
            while(str1[i] != str[k]){
                ans.push_back(str1[i]);
                i++;
            }
            while(str2[j] != str[k]){
                ans.push_back(str2[j]);
                j++;
            }
            ans.push_back(str[k]);
            i++;
            j++;
            k++;
        }
        while(i < l1){
            ans.push_back(str1[i]);
            i++;
        }
        while(j < l2){
            ans.push_back(str2[j]);
            j++;
        }
        
        return ans;
    }
    
};
