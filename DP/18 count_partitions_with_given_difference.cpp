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


using namespace std;

int mod =(int)1e9+7;

int findWays(vector<int> &num, int tar){
     int n = num.size();

    vector<int> prev(tar+1,0);
    
    if(num[0] == 0) prev[0] =2;  // 2 cases -pick and not pick
    else prev[0] = 1;  // 1 case - not pick
    
    if(num[0]!=0 && num[0]<=tar) prev[num[0]] = 1;  // 1 case -pick
    
    for(int ind = 1; ind<n; ind++){
        vector<int> cur(tar+1,0);
        for(int target= 0; target<=tar; target++){
            int notTaken = prev[target];
    
            int taken = 0;
                if(num[ind]<=target)
                    taken = prev[target-num[ind]];
        
            cur[target]= (notTaken + taken)%mod;
        }
        prev = cur;
    }
    return prev[tar];
}

int countPartitions(int n, int d, vector<int>& arr){
    int totSum = 0;
    for(int i=0; i<n;i++){
        totSum += arr[i];
    }
    
    //Checking for edge cases
    if(totSum-d <0 || (totSum-d)%2 ) return 0;
    
    return findWays(arr,(totSum-d)/2);
}
  

int main() {

  vector<int> arr = {5,2,6,4};
  int n = arr.size();
  int d=3;
                                 
  cout<<"The number of subsets found are " <<countPartitions(n,d,arr);
}







int mod = 1e9 + 7;

class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
        }
        if((sum - d) % 2 || sum < d)   return 0;
        int target = (sum - d) / 2;
        
        vector<int> prev(target + 1, 0);
        if(!arr[0]) prev[0] = 2;
        else        prev[0] = 1;
        
        
        
        if(arr[0] != 0 && arr[0] <= target)     prev[arr[0]] = 1;
        
        int pick, notpick;
        for(int i = 1; i < n; i++){
            vector<int> cur(target + 1, 0);
            
            for(int j = 0; j < target + 1; j++){
                pick = 0, notpick = 0;
                notpick = prev[j];
                
                if(j >= arr[i])
                    pick = prev[j - arr[i]];
                cur[j] = (notpick + pick)% mod;
            }
            prev = cur;
        }
        
        return prev[target];
        
    }
};