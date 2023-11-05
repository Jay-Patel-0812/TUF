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

// TC: 4^(n * m)
// SC: 

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        if(m[0][0] == 0)    return ans;
        
        vector<vector<int> > vis(n, vector<int> (n, 0));
        
        string str = "";
        solve(m, vis, n, ans, 0, 0, str);
        
        return ans;
    }
    
    void solve(vector<vector<int> >& m, vector<vector<int> >& vis, int n, vector<string>& ans, int i, int j, string& str){
        if(i == n - 1 && j == n - 1){
            ans.push_back(str);
            return;
        }
        vis[i][j] = 1;
        
        if(i - 1 >= 0){
            if(!vis[i - 1][j] && m[i - 1][j]){
                str += "U";
                solve(m, vis, n, ans, i - 1, j, str);
                str = str.substr(0, str.size() - 1);
            }
        }
        if(j - 1 >= 0){
            if(!vis[i][j - 1] && m[i][j - 1]){
                str += "L";
                solve(m, vis, n, ans, i, j - 1, str);
                str = str.substr(0, str.size() - 1);
            }
        }
        
        if(i + 1 < n){
            if(!vis[i + 1][j] && m[i + 1][j]){
                str += "D";
                solve(m, vis, n, ans, i + 1, j, str);
                str = str.substr(0, str.size() - 1);
            }
        }
        
        
        if(j + 1 < n){
            if(!vis[i][j + 1] && m[i][j + 1]){
                str += "R";
                solve(m, vis, n, ans, i, j + 1, str);
                str = str.substr(0, str.size() - 1);
            }
        }
        
        vis[i][j] = 0;
        
    }
};








class Solution {
  void solve(int i, int j, vector < vector < int >> & a, int n, vector < string > & ans, string move,
    vector < vector < int >> & vis, int di[], int dj[]) {
    if (i == n - 1 && j == n - 1) {
      ans.push_back(move);
      return;
    }
    string dir = "DLRU";
    for (int ind = 0; ind < 4; ind++) {
      int nexti = i + di[ind];
      int nextj = j + dj[ind];
      if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && a[nexti][nextj] == 1) {
        vis[i][j] = 1;
        solve(nexti, nextj, a, n, ans, move + dir[ind], vis, di, dj);
        vis[i][j] = 0;
      }
    }

  }
  public:
    vector < string > findPath(vector < vector < int >> & m, int n) {
      vector < string > ans;
      vector < vector < int >> vis(n, vector < int > (n, 0));
      int di[] = {
        +1,
        0,
        0,
        -1
      };
      int dj[] = {
        0,
        -1,
        1,
        0
      };
      if (m[0][0] == 1) solve(0, 0, m, n, ans, "", vis, di, dj);
      return ans;
    }
};

int main() {
  int n = 4;

 vector < vector < int >> m = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
   
  Solution obj;
  vector < string > result = obj.findPath(m, n);
  if (result.size() == 0)
    cout << -1;
  else
    for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
  cout << endl;

  return 0;
}