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

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key){
        if(!root){
            return NULL;
        }
        if(root->val == key){
            return help(root);
        }
        TreeNode* t = root;
        while(root){
            if(key < root->val){
                if(root->left && root->left->val == key){
                    root->left = help(root->left);
                    break;
                }
                else{
                    root = root->left;
                }
            }
            else if(root->val < key){
                if(root->right && root->right->val == key){
                    root->right = help(root->right);
                    break;
                }
                else{
                    root = root->right;
                }
            }
        }

        return t;
    }

    TreeNode* help(TreeNode* node){
        if(!node->left){
            return node->right;
        }
        else if(!node->right){
            return node->left;
        }
        
        TreeNode* rightchild = node->right, *temp;
        temp = rightchild;
        while(temp->left){
            temp = temp->left;
        }
        temp->left = node->left;
        return rightchild;
    }
};










class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return NULL;
        }
        if (root->val == key) {
            return helper(root);
        }
        TreeNode *dummy = root;
        while (root != NULL) {
            if (root->val > key) {
                if (root->left != NULL && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else {
                if (root->right != NULL && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }
        return dummy;
    }
    TreeNode* helper(TreeNode* root) {
            if (root->left == NULL) 
            {
                return root->right;
            } 
            else if (root->right == NULL)
            {
                return root->left;
            } 
            TreeNode* rightChild = root->right;
            TreeNode* lastRight = findLastRight(root->left);
            lastRight->right = rightChild;
            return root->left;
    }
    TreeNode* findLastRight(TreeNode* root) {
        if (root->right == NULL) {
            return root;
        }
        return findLastRight(root->right);
    }
};