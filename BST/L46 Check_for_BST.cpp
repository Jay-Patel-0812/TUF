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
    bool isValidBST(TreeNode* root) {
        if(!root){
            return 1;
        }
        return isValid(root, LONG_MIN, LONG_MAX);
    }
    
    bool isValid(TreeNode* node, long min, long max){
        if(node->val > min && node->val < max){
            bool l = 1, r = 1;
            if(node->left) l = isValid(node->left, min, node->val);
            if(node->right) r = isValid(node->right, node->val, max);

            if(!l || !r){
                return 0;
            }
            return 1;
        }
        else{
            return 0;
        }
    }
};




// class Solution {
//     public boolean isValidBST(TreeNode root) {
//         return isValidBST(root, Long.MIN_VALUE, Long.MAX_VALUE);
//     }
    
//     public boolean isValidBST(TreeNode root, long minVal, long maxVal) {
//         if (root == null) return true;
//         if (root.val >= maxVal || root.val <= minVal) return false;
//         return isValidBST(root.left, minVal, root.val) && isValidBST(root.right, root.val, maxVal);
//     }
// }