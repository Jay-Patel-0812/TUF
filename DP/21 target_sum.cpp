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

// TC: O(val * N)
// SC: O(val)

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        if((sum - target)%2){
            return 0;
        }

        int val = (sum - target)/2;
        if(val < 0) return 0;

        vector<int> prev(val + 1, 0);
        
        if(!nums[0])    prev[0] = 2;
        else            prev[0] = 1;

        if(nums[0] && nums[0] <= val)     prev[nums[0]] = 1;

        int pick, notpick;
        for(int i = 1; i < n; i++){
            vector<int> cur(val + 1, 0);
            for(int j = 0; j <= val; j++){
                pick = notpick = 0;
                notpick = prev[j];
                if(j >= nums[i])
                    pick = prev[j - nums[i]];
                cur[j] = pick + notpick;
            }
            prev = cur;
        }

        return prev[val];
    }
};