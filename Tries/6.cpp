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
    int findMaximumXOR(vector<int>& nums) {
        Trie T;

        for(int i = 0; i < nums.size(); i++){
            T.insert(nums[i]);
        }

        int mx = 0;

        for(int i = 0; i < nums.size(); i++){
            mx = max(mx, T.getMax(nums[i]));
        }

        return mx;
    }
};