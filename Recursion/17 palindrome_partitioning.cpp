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
    bool is_pal(string s){
        if(!s.size()){
            return 1;
        }
        int n = s.size(), t = n/2;

        for(int i = 0; i < t; i++){
            if(s[i] != s[n - i - 1]){
                return 0;
            }
        }
        return 1;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string> > ans;
        vector<string> t;
        solve(ans, s, t);

        return ans;
    }

    void solve(vector<vector<string> >& ans, string s, vector<string>& t){
        // if(s == ""){
        //     ans.push_back(t);
        //     return;
        // }

        for(int i = 1; i <= s.size(); i++){
            if(is_pal(s.substr(0, i))){
                t.push_back(s.substr(0, i));
                if(i == s.size()){
                    ans.push_back(t);
                }
                else{
                    solve(ans, s.substr(i), t);
                }
                t.pop_back();
            }
        }
    }
};









class Solution {
  public:
    vector < vector < string >> partition(string s) {
      vector < vector < string > > res;
      vector < string > path;
      partitionHelper(0, s, path, res);
      return res;
    }

  void partitionHelper(int index, string s, vector < string > & path,
    vector < vector < string > > & res) {
    if (index == s.size()) {
      res.push_back(path);
      return;
    }
    for (int i = index; i < s.size(); ++i) {
      if (isPalindrome(s, index, i)) {
        path.push_back(s.substr(index, i - index + 1));
        partitionHelper(i + 1, s, path, res);
        path.pop_back();
      }
    }
  }

  bool isPalindrome(string s, int start, int end) {
    while (start <= end) {
      if (s[start++] != s[end--])
        return false;
    }
    return true;
  }
};
int main() {
  string s = "aabb";
  Solution obj;
  vector < vector < string >> ans = obj.partition(s);
  int n = ans.size();
  cout << "The Palindromic partitions are :-" << endl;
  cout << " [ ";
  for (auto i: ans) {
    cout << "[ ";
    for (auto j: i) {
      cout << j << " ";
    }
    cout << "] ";
  }
  cout << "]";

  return 0;

}