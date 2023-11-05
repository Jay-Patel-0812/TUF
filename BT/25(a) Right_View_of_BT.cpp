#include<vector>
#include<iostream>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<list>
#include<numeric>
#define ll long long


using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// TC: O(N)
// SC: O(H), H is height of the tree

void recursion(TreeNode* node, vector<int>& ans, int level){
    if(!node){
        return;
    }
    if(level == ans.size()){
        ans.push_back(node->val);
    }
    
    recursion(node->right, ans, level + 1);
    recursion(node->left, ans, level + 1);
}



class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        
        recursion(root, ans, 0);
        return ans;
    }
};










// TC: O(N)
// SC: more than the recursive solution


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        map<int, TreeNode*> m;
        vector<int> ans;
        
        queue<TreeNode*> q;
        if(root){
            q.push(root);
        }
        else{
            return ans;
        }
        
        int n = q.size();
        int level = 0;
        TreeNode* temp;
        
        while(!q.empty()){
            n = q.size();
            
            for(int i =0; i < n; i++){
                temp = q.front();
                q.pop();
                m[level] = temp;
                
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            level++;
        }
        
        for(auto i: m){
            ans.push_back(i.second->val);
        }
        
        return ans;
    }
};