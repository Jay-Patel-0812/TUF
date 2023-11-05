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

    int solve(vector<int>& arr, vector<vector<int> >& dp, int sum, int index){
        if(sum == 0){
            return 1;
        }
        if(sum < 0){
            return 0;
        }
        if(!index && sum){
            return 0;
        }
        
        if(dp[index][sum] != -1) return dp[index][sum];
        
        dp[index][sum] = solve(arr, dp, sum - arr[index - 1], index - 1) || 
                        solve(arr, dp, sum, index - 1);
                        
        return dp[index][sum];
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int> > dp(n + 1, vector<int> (sum + 1, -1));
        solve(arr, dp, sum, n);
        return dp[n][sum];
    }
};















using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr){
    vector<bool> prev(k+1,false);
    
    prev[0] = true;
    
    if(arr[0]<=k)
        prev[arr[0]] = true;
    
    for(int ind = 1; ind<n; ind++){
        vector<bool> cur(k+1,false);
        cur[0] = true;
        for(int target= 1; target<=k; target++){
            bool notTaken = prev[target];
    
            bool taken = false;
            if(arr[ind]<=target)
                taken = prev[target-arr[ind]];
        
            cur[target]= notTaken||taken;
        }
        prev = cur;
    }
    
    return prev[k];
}

int main() {

  vector<int> arr = {1,2,3,4};
  int k=4;
  int n = arr.size();
                                 
  if(subsetSumToK(n,k,arr))
    cout<<"Subset with given target found";
  else 
    cout<<"Subset with given target not found";
}