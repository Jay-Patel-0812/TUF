#include<iostream>
#include<vector>
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


using namespace std;
#define ll  long long


struct Q{
    int val;
    int m;
    int index;
};

bool comp(struct Q t1, struct Q t2){
    return t1.m < t2.m;
}

struct Node{
    Node* links[2];
    int flag;

    bool containsKey(int bit){
        return (links[bit] != NULL);
    }

    void put(int bit, Node* node){
        links[bit] = node;
    }

    Node* get(int bit){
        return links[bit];
    }
};

class Trie{
private:
    Node* root;

public:
    Trie(){
        root = new Node();
    }
    void insert(int a){
        Node* node = root;
        for(int i = 31; i >= 0; i--){
            int bit = (a >> i) & 1;
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int x){
        Node* node = root;
        int max = 0;
        for(int i =31; i >= 0; i--){
            int bit = (x >> i) & 1;
            if(node->containsKey(1 - bit)){
                max = max | (1 << i);
                node = node->get(1 - bit);
            }
            else{
                node = node->get(bit);
            }
        }

        return max;
    }
};


class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int ns = nums.size(), qs = queries.size();
        Trie T;
        sort(nums.begin(), nums.end());

        vector<struct Q> VQ;

        for(int i = 0; i < qs; i++){
            VQ.push_back({queries[i][0], queries[i][1], i});
        }
        vector<int> ans(qs, -1);

        sort(VQ.begin(), VQ.end(), comp);

        int ind = 0, mx = 0;

        for(int i = 0; i < VQ.size(); i++){
            while(ind < ns && nums[ind] <= VQ[i].m){
                T.insert(nums[ind]);
                ind++;
            }

            if(ind == 0){
                continue;
            }
            mx = 0;
            mx = T.getMax(VQ[i].val);
            ans[VQ[i].index] = mx;
        }

        return ans;

    }
};