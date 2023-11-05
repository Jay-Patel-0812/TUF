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

// TC: O((logn)^2)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int countNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        int l = leftheight(root);
        int r = rightheight(root);

        if(l == r) return (1<<l) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
}

int leftheight(TreeNode* node){
    int height = 0;
    while(node){
        height++;
        node = node->left;
    }
    return height;
}

int rightheight(TreeNode* node){
    int height = 0;
    while(node){
        height++;
        node = node->right;
    }
    return height;
}



















    
int countNodes(TreeNode* root) {
    if(root == NULL) return 0; 
    
    int lh = findHeightLeft(root); 
    int rh = findHeightRight(root); 
    
    if(lh == rh) return (1<<lh) - 1; 
    
    return 1 + countNodes(root->left) + countNodes(root->right); 
}
int findHeightLeft(TreeNode* node) {
    int hght = 0; 
    while(node) {
        hght++; 
        node = node->left; 
    }
    return hght; 
}
int findHeightRight(TreeNode* node) {
    int hght = 0; 
    while(node) {
        hght++; 
        node = node->right; 
    }
    return hght; 
}