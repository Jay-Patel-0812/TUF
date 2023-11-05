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

class Solution{
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        solve(arr, N, 0, ans, 0);
        sort(ans.begin(), ans.end());
        
        return ans;
    }
    
    void solve(vector<int>& arr, int N, int index, vector<int>& ans, int sum){
        if(index == N){
            ans.push_back(sum);
            return;
        }
        
        solve(arr, N, index + 1, ans, sum + arr[index]);
        solve(arr, N, index + 1, ans, sum);
        
    }
};