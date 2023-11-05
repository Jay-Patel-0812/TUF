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

int maxDepth(TreeNode* root, int& maxi){
    if(!root){
        return 0;
    }
    
    int rh = maxDepth(root->right, maxi);
    int lh = maxDepth(root->left, maxi);
    maxi = max(maxi, rh + lh);
    
    return 1 + max(lh, rh);
}

class Solution {
public:
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        int t = maxDepth(root, maxi);
        return maxi;
    }
    
};





// below code is way faster than the one written by me

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

private:
    int height(TreeNode* node, int& diameter) {

        if (!node) {
            return 0;
        }

        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);

        diameter = max(diameter, lh + rh);

        return 1 + max(lh, rh);
    }
};
