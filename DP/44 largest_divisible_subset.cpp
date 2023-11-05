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
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), t;
        sort(nums.begin(), nums.end());

        vector<int> V(n, 1);

        V[0] = 1;
        int max = 1, maxindex = 0;

        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0){
                    t = V[j] + 1;
                    if(t > V[i]){
                        V[i] = t;
                        if(t > max){
                            max = t;
                            maxindex = i;
                        }
                    }
                }
            }
        }

        int i = maxindex - 1;
        vector<int> ans;
        ans.push_back(nums[maxindex]);
        t = max - 1;
        int temp = nums[maxindex];
        while(i >= 0){
            if(V[i] == t && temp % nums[i] == 0){
                t--;
                ans.push_back(nums[i]);
                temp = nums[i];
                i--;
            }
            else{
                i--;
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};




vector<int> divisibleSet(vector<int>& arr){

    int n = arr.size();
    
    //sort the array
    
    sort(arr.begin(), arr.end());

    vector<int> dp(n,1);
    vector<int> hash(n,1);
    
    for(int i=0; i<=n-1; i++){
        
        hash[i] = i; // initializing with current index
        for(int prev_index = 0; prev_index <=i-1; prev_index ++){
            
            if(arr[i]%arr[prev_index] == 0 && 1 + dp[prev_index] > dp[i]){
                dp[i] = 1 + dp[prev_index];
                hash[i] = prev_index;
            }
        }
    }
    
    int ans = -1;
    int lastIndex =-1;
    
    for(int i=0; i<=n-1; i++){
        if(dp[i]> ans){
            ans = dp[i];
            lastIndex = i;
        }
    }
    
    vector<int> temp;
    temp.push_back(arr[lastIndex]);
    
    while(hash[lastIndex] != lastIndex){ // till not reach the initialization value
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);    
    }
    
    // reverse the array 
    reverse(temp.begin(),temp.end());

    
    return temp;
}

int main() {
	
	vector<int> arr = {1,16,7,8,4};
	
	vector<int> ans = divisibleSet(arr);
	
	cout<<" The longest divisible subset elements are: ";
	
	for(int i=0; i<ans.size(); i++){
	    cout<<ans[i]<<" ";
	}
}