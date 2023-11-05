#include<vector>
#include<iostream>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<cstring>

// TC: O(N^3)

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
        long long n = nums.size();
        vector<long long> a;
        for(int i = 0; i < nums.size(); i++) a.push_back(nums[i]);
        vector<vector<long long> > V;
        sort(a.begin(), a.end());
        long long r, l, temp;
        for(long long i = 0;i < n - 3;i++){
            for(long long j = i + 1; j < n - 2; j++){
                l = j + 1;
                r = n - 1;

                while(l < r){
                    temp = a[i] + a[j] + a[r] + a[l];
                    if(temp == target){
                        vector<long long> V1;
                        V1.push_back(a[i]);
                        V1.push_back(a[j]);
                        V1.push_back(a[l]);
                        V1.push_back(a[r]);
                        V.push_back(V1);

                        while(l < n - 1 && a[l] == a[l + 1]){
                            l++;
                        }
                        l++;
                        while(0 < r && a[r] == a[r - 1]){
                            r--;
                        }
                        r--;
                    }
                    else if(temp < target){
                        while(l < n - 1 && a[l] == a[l + 1]){
                            l++;
                        }
                        l++;
                    }
                    else{
                        while(0 < r && a[r] == a[r - 1]){
                            r--;
                        }
                        r--;
                    }
                }
                while(j < n - 1 && a[j] == a[j + 1]){
                    j++;
                }
            }

            while(i < n - 1 && a[i] == a[i + 1]){
                i++;
            }
        }
        
        
        vector<vector<int> > x;

        for(int i = 0; i < V.size(); i++){
            vector<int> y;
            for(int j = 0; j < V[i].size(); j++){
                y.push_back(V[i][j]);
            }
            x.push_back(y);
        }
        return x;
    }