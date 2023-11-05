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
    int numDistinct(string s, string t) {
        unsigned int ss = s.size(), ts = t.size();
        vector<unsigned int> prev(ss + 1, 0);

        for(unsigned int j = 1; j < ss + 1; j++){
            if(s[j - 1] == t[0]){
                prev[j] = prev[j - 1] + 1;
            }
            else{
                prev[j] = prev[j - 1];
            }
        }
        for(unsigned int i = 2; i < ts + 1; i++){
            vector<unsigned int> cur(ss + 1, 0);
            for(unsigned int j = 1; j < ss + 1; j++){
                if(t[i - 1] == s[j - 1]){
                    cur[j] = prev[j - 1] + cur[j - 1];
                }
                else{
                    cur[j] = cur[j - 1];
                }
            }
            prev = cur;
        }

        return prev[ss];
    }
};




// Not sure if the below code works, it is striver's code

int prime = 1e9+7;


int subsequenceCounting(string &s1, string &s2, int n, int m) {
    // Write your code here.
    
    vector<int> prev(m+1,0);
    
    prev[0]=1;
    
    for(int i=1;i<n+1;i++){
        for(int j=m;j>=1;j--){ // Reverse direction
            
            if(s1[i-1]==s2[j-1])
                prev[j] = (prev[j-1] + prev[j])%prime;
            else
                prev[j] = prev[j]; //can omit this statemwnt
        }
    }
    
    
    return prev[m];
} 

int main() {

  string s1 = "babgbag";
  string s2 = "bag";

  cout << "The Count of Distinct Subsequences is "<<
  subsequenceCounting(s1,s2,s1.size(),s2.size());
}