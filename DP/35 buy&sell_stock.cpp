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
    int maxProfit(vector<int>& prices) {
        int min = prices[0], ans = 0;

        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > min){
                ans = max(ans, prices[i] - min);
            }
            else{
                min = prices[i];
            }
        }
        return ans;
    }
};


int find_max(vector<int>& prices, int start, int end){
    int max = prices[start];
    int min = prices[start];
    if(start == end){
        return 0;
    }
    else if(start < end){

        
        int positionofmin = 0;
        int positionofmax = 0;
        for(int i = start; i <= end; i++){
            if(min > prices[i]){
                min = prices[i];
                positionofmin = i;
            }
            if(max < prices[i]){
                max = prices[i];
                positionofmax = i;
            }
        }
        
        if(positionofmax > positionofmin){

            return max - min;
        }
        else if(positionofmax == positionofmin){
            return 0;
        }
        else{
            int min1 = prices[start];
            for(int i = start; i < positionofmax; i++){
                if(min1 > prices[i]){
                    min1 = prices[i];
                }
            }
            int max_1 = max - min1;
            
            int max1 = min;
            for(int i = positionofmin + 1; i <= end; i++){
                if(max1 < prices[i]){
                    max1 = prices[i];
                }
            }
            int max_2 = max1 - min;
            
            int max_3 = find_max(prices, positionofmax + 1, positionofmin - 1);
            
            if(max_1 >= max_2 && max_1 >= max_3){
                return max_1;
            }
            else if(max_2 >= max_1 && max_2 >= max_3){
                return max_2;
            }
            else{
                return max_3;
            }
        }
        
    }
    else{
        return 0;
    }
    
}


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int start = 0;
        int end = prices.size() - 1;
        
        max = find_max(prices, start, end);
        
        return max;
    }
};