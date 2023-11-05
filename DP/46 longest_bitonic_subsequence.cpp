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

// LeetCode:
// Minimum number of removals to make mountain array


#define ll long long
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();

        vector<int> V1(n, 1), V2(n, 1);
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    if(V1[i] < V1[j] + 1){
                        V1[i] = V1[j] + 1;
                    }
                }
            }
        }

        for(int i = n - 2; i >= 0; i--){
            for(int j = n - 1; j > i; j--){
                if(nums[i] > nums[j]){
                    if(V2[i] < V2[j] + 1){
                        V2[i] = V2[j] + 1;
                    }
                }
            }
        }

        ll max = 1;

        for(ll i = 0; i < n - 1; i++){
            for(ll j = i + 1; j < n; j++){
                if(V1[i] > 1 && nums[i] > nums[j]){
                    if(V1[i] + V2[j] > max){
                        max = V1[i] + V2[j];
                    }
                }
            }
        }

        // for(ll i = 1; i < n; i++){
        //     if(V1[i - 1] > V1[i]){
        //         V1[i] = V1[i - 1];
        //     }
        // }

        // for(ll i = n - 2; i >= 0; i--){
        //     if(V2[i + 1] > V2[i]){
        //         V2[i] = V2[i + 1];
        //     }
        // }

        // int t = 0;
        // for(ll i = 1; i < n; i++){
        //     t = V1[i - 1] + V2[i];
        //     if(t > max && nums[i - 1] != nums[i]){
        //         max = t;
        //     }
        // }

        return (n - max);
    }

};