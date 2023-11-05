#include<vector>
#include<iostream>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<cstring>

#include<iostream>

// TC: O(N^2), N^2 for loops
// SC: O(M) 
// AS: O(1)

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int > a(nums);
        int n = nums.size();
        sort(a.begin(), a.end());
        vector<vector<int> > V;
        int j, k, temp;
        for(int i = 0; i < nums.size() - 2; i++){
            j = i + 1; 
            k = n - 1;
            while(j < k){
                temp = a[i] + a[j] + a[k];
                if( temp == 0){
                    vector<int> V1;
                    V1.push_back(a[i]);
                    V1.push_back(a[j]);
                    V1.push_back(a[k]);
                    V.push_back(V1);
                    
                    while(j < n - 1 && a[j] == a[j + 1]){
                        j++;
                    }
                    j++;
                    while(k > 0 && a[k] == a[k - 1]){
                        k--;
                    }
                    k--;
                }
                else if(temp > 0){
                    k--;
                }
                else{
                    j++;
                }
            }
            while(i < n - 2 && a[i] == a[i + 1]){
                i++;
            }
        }
        
        return V;
    }
};