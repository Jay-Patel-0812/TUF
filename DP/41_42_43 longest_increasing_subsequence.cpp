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

// TC: O(N * logN)
// SC: O(N)

class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        int t = 0;
        temp.push_back(nums[0]);

        vector<int>::iterator it;

        for(int i = 1; i < n; i++){
            if(nums[i] > temp[t]){
                temp.push_back(nums[i]);
                t++;
            }
            else{
                it = lower_bound(temp.begin(), temp.end(), nums[i]);
                *it = nums[i];
            }
        }

        return (t + 1);
    }
};

// TC: O(N * N)
// SC: O(N)

class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        int max = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        if(dp[i] > max){
                            max = dp[i];
                        }
                    }
                }
            }
        }

        return max;
    }
};

// TC: O(N * N)
// SC: O(N)

class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 1;
        }
        vector<int> dp(n, 0);

        dp[0] = 1;
        for(int j = 0; j < n - 1; j++){
            if(nums[n - 1] > nums[j])
                dp[j + 1] = 1;
        }
        
        int len;
        for(int i = n - 2; i >= 0; i--){
            for(int j = i; j > 0; j--){
                len = dp[j];
                if(nums[j - 1] < nums[i]){
                    len = max(len, 1 + dp[i + 1]);
                }
                dp[j] = len;
            }
            dp[0] = max(1 + dp[i + 1], dp[0]);
        }
        dp[0] = max(1 + dp[1], dp[0]);
        return dp[0];
    }
};


class Solution {
public:
    int solve(vector<vector<int> >& dp, int& n, int index, int prev_ind, vector<int>& nums){
        if(index == n){
            return 0;
        }
        if(dp[index][prev_ind + 1] != -1){
            return dp[index][prev_ind + 1];
        }
        
        int len = solve(dp, n, index + 1, prev_ind, nums);
        if(prev_ind == -1 || nums[index] > nums[prev_ind]){
            len = max(len, 1 + solve(dp, n, index + 1, index, nums));
        }

        return dp[index][prev_ind + 1] = len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> > dp(n, vector<int> (n + 1, -1));

        solve(dp, n, 0, -1, nums);
        return dp[0][0];
    }
};



class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 1;
        }
        vector<vector<int> > dp(n, vector<int> (n + 1, 0));

        // solve(dp, n, 0, -1, nums);
        dp[n - 1][0] = 1;
        for(int j = 0; j < n - 1; j++){
            if(nums[n - 1] > nums[j])
                dp[n - 1][j + 1] = 1;
        }
        for(int i = 0; i < n; i++){
            dp[i][0] = 1;
        }


        int len;
        for(int i = n - 2; i >= 0; i--){
            for(int j = i; j > 0; j--){
                len = dp[i + 1][j];
                if(nums[j - 1] < nums[i]){
                    len = max(len, 1 + dp[i + 1][i + 1]);
                }
                dp[i][j] = len;
            }
            dp[i][0] = max(1 + dp[i + 1][i + 1], dp[i + 1][0]);
        }
        dp[0][0] = max(1 + dp[1][1], dp[1][0]);
        return dp[0][0];
    }
};