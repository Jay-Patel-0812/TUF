

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

// TC: O(N)
// SC: O(2N)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> V;
        stack<TreeNode*> st1, st2;
        if(root){
            st1.push(root);
        }
        TreeNode* temp;
        while(!st1.empty()){
            temp = st1.top();
            st1.pop();
            st2.push(temp);
            if(temp->left){
                st1.push(temp->left);
            }
            if(temp->right){
                st1.push(temp->right);
            }
        }
        
        while(!st2.empty()){
            temp = st2.top();
            st2.pop();
            V.push_back(temp->val);
        }
        
        return V;
    }
};