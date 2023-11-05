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
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int> > dp(N, vector<int> (N, 0));
        // int ans = solve(N, arr, 1, N - 1, dp);
        int temp, t;
        for(int i = N - 1; i > 0; i--){
            for(int j = i + 1; j < N; j++){
                temp = 0, t = INT_MAX;
                for(int k = i; k < j; k++){
                    temp = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                    if(temp < t){
                        t = temp;
                    }
                }
                dp[i][j] = t;
            }
        }
        
        return dp[1][N - 1];
    }
};


int solve(int& N, int arr[], int i, int j, vector<vector<int> >& dp){
    if(i >= j){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    
    int t = INT_MAX, temp = 0;
    
    for(int k = i; k < j; k++){
        temp = solve(N, arr, i, k, dp) + solve(N, arr, k + 1, j, dp) + arr[i - 1] * arr[k] * arr[j]; ;
        if(temp < t){
            t = temp;
        }
    }
    
    dp[i][j] = t;
    return dp[i][j];
}

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int> > dp(N, vector<int> (N, -1));
        int ans = solve(N, arr, 1, N - 1, dp);
        
        return ans;
    }
};