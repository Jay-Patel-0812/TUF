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

// TC: O(n * sum/2)
// SC: O(sum/2)

class Solution{
public:
	int minDifference(int arr[], int n)  { 
	    int sum = 0;
	    for(int i = 0; i < n; i++){
	        sum += arr[i];
	    }
	    
	    vector<int> prev(sum/2 + 1, 0);
	    prev[0] = 1;
	    
	    for(int i = 0; i < n; i++){
	        vector<int> cur(sum/2 + 1, 0);
	        for(int j = 0; j <= sum/2; j++){
	            if(prev[j])
	                cur[j] = 1;
	            if(j - arr[i] >= 0 && prev[j - arr[i]])
	                cur[j] = 1;
	        }
	        
	        prev = cur;
	    }
	    
	    int t = 0;
	    for(int i = sum/2; i >= 0; i--){
	        if(prev[i]){
	            t = i;
	            break;
	        }
	    }
	    
	    int t1 = t, t2 = sum - t;
	    
	    return abs(t1 - t2);
	    
	} 
};