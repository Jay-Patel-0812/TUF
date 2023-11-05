#include<vector>
#include<iostream>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<cstring>

using namespace std;

// TC: O(NlogN) + O(N)(merge operation) + O(N)(counting operation)
// SC: O(N)

void merge(vector<int>& nums, long long start, long long mid, long long end, long long& count){
    long long temp = 0;
    long long js = mid + 1;
    for(long long i = start; i <= mid; i++){
        for(long long j = js; j <= end; j++){
            if(nums[i] > 2L * nums[j]){
                temp++;
                js++;
            }
            else{
                break;
            }
        }
        count += temp;
    }
    
    vector<long long> m1;
    long long i = start;
    long long j = mid + 1;
    while(i < mid + 1 && j < end + 1){
        if(nums[i] < nums[j]){
            m1.push_back(nums[i]);
            i++;
        }
        else if(nums[i] > nums[j]){
            m1.push_back(nums[j]);
            j++;
        }
        else{
            m1.push_back(nums[i]);
            m1.push_back(nums[j]);
            i++;
            j++;
        }
    }
    
    while(i < mid + 1){
        m1.push_back(nums[i]);
        i++;
    }
    while(j < end + 1){
        m1.push_back(nums[j]);
        j++;
    }
    
    long long k = 0;
    for(long long i = start; i <= end; i++){
        nums[i] = m1[k];
        k++;
    }
}


long long mergeSort(vector<int>& nums, long long start, long long end,long long& count){
    if(start >= end){
        return 0;
    }
    
    long long mid = (start + end) / 2;
    long long c1 = mergeSort(nums, start, mid, count);
    long long c2 = mergeSort(nums, mid + 1, end, count);
    merge(nums,start, mid , end, count);
    return count;
}

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        long long count = 0;
        long long ans = mergeSort(nums, 0, nums.size() - 1, count);
        return ans;
    }
};

// class Solution {
// public:
//     int sort_and_count(vector<int>::iterator begin, vector<int>::iterator end) {
//         if (end - begin <= 1)
//             return 0;
//         auto mid = begin + (end - begin) / 2;
//         int count = sort_and_count(begin, mid) + sort_and_count(mid, end);
//         for (auto i = begin, j = mid; i != mid; ++i) {
//             while (j != end and *i > 2L * *j)
//                 ++j;
//             count += j - mid;
//         }
//         inplace_merge(begin, mid, end);
//         return count;
//     }

//     int reversePairs(vector<int>& nums) {
//         return sort_and_count(nums.begin(), nums.end());
//     }
// };