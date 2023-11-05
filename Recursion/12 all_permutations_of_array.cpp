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

// TC: O(N! * N)
// SC: O(N)

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<bool> B(nums.size(), 1);
        vector<int> ds;
        solve(ans, nums, B, 0, nums.size(), ds);
        return ans;
    }

    void solve(vector<vector<int>>& ans, vector<int>& nums, vector<bool>& B, int index, int N, vector<int>& ds){
        if(index == N){
            ans.push_back(ds);
            return;
        }
        for(int i = 0; i < N; i++){
            if(B[i]){
                B[i] = 0;
                ds.push_back(nums[i]);
                solve(ans, nums, B, index + 1, N, ds);
                ds.pop_back();
                B[i] = 1;
            }
        }
    }
};