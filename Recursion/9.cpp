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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());

        solve(candidates, target, 0, ans, ds);
        return ans;
    }   

    void solve(vector<int>& candidates, int target, int index, vector<vector<int> >& ans, vector<int>& ds){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        else if(index == candidates.size()){
            return;
        }

        if(candidates[index] <= target){
            target -= candidates[index];
            ds.push_back(candidates[index]);
            solve(candidates, target, index + 1, ans, ds);
            target += candidates[index];
            ds.pop_back();
            
            int t = candidates[index];
            while(index < candidates.size() && candidates[index] == t){
                index++;
            }
            solve(candidates, target, index, ans, ds);
        }
        else{
            return;
        }
    }
};







void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
  if (target == 0) {
    ans.push_back(ds);
    return;
  }
  for (int i = ind; i < arr.size(); i++) {
    if (i > ind && arr[i] == arr[i - 1]) continue;
    if (arr[i] > target) break;
    ds.push_back(arr[i]);
    findCombination(i + 1, target - arr[i], arr, ans, ds);
    ds.pop_back();
  }
}
vector < vector < int >> combinationSum2(vector < int > & candidates, int target) {
  sort(candidates.begin(), candidates.end());
  vector < vector < int >> ans;
  vector < int > ds;
  findCombination(0, target, candidates, ans, ds);
  return ans;
}
int main() {
  vector<int> v{10,1,2,7,6,1,5};
  vector < vector < int >> comb = combinationSum2(v, 8);
  cout << "[ ";
  for (int i = 0; i < comb.size(); i++) {
    cout << "[ ";
    for (int j = 0; j < comb[i].size(); j++) {
      cout << comb[i][j] << " ";
    }
    cout << "]";
  }
  cout << " ]";
}