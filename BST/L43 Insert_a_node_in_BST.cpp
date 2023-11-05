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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp = root;
        TreeNode* node = new TreeNode(val);
        if(!root){
            return node;
        }

        while(temp){
            if(temp->val > val){
                if(temp->left){
                    temp = temp->left;
                }
                else{
                    temp->left = node;
                    break;
                } 
            }
            else if(temp->val < val){
                if(temp->right){
                    temp = temp->right;
                }
                else{
                    temp->right = node;
                    break;
                }
            }
        }

        return root;
    }
};