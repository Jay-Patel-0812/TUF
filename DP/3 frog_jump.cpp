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

// TC: O(N)
// SC: O(1)

int main() {

  vector<int> height{30,10,60,10,60,50};
  int n=height.size();
  int prev=0;
  int prev2=0;
  for(int i=1;i<n;i++){
      
      int jumpTwo = INT_MAX;
      int jumpOne= prev + abs(height[i]-height[i-1]);
      if(i>1)
        jumpTwo = prev2 + abs(height[i]-height[i-2]);
    
      int cur_i=min(jumpOne, jumpTwo);
      prev2=prev;
      prev=cur_i;
        
  }
  cout<<prev;
}

// TC: O(N)
// SC: O(N)

using namespace std;

int jump(int index, int& n,vector<int>& heights, vector<int>& dp){
    if(index == 0){
        return 0;
    }
    int one, two = INT_MAX;
    if(dp[index] != -1)
        return dp[index];

    one = jump(index - 1, n, heights, dp) + abs(heights[index] - heights[index - 1]);
    if(index > 1)
        two = jump(index - 2, n, heights, dp) + abs(heights[index] - heights[index - 2]);

    dp[index] = min(one, two);

    return dp[index];
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    int ans = jump(n - 1, n, heights, dp);

    return ans;
}




