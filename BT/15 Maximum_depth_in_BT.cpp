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

int M(TreeNode* t, int x){
    int m = x, t1 = 0, t2 = 0;
    if(t->left){
        t1 = M(t->left, x + 1);
    }
    if(t->right){
        t2 = M(t->right, x + 1);
    }
    m = max(t1, m);
    m = max(t2, m);
    
    return m;
}

class Solution {
public:
    // int maxi = 0;
    int maxDepth(TreeNode* root) {
        // int max = 0;
        if(!root){
            return 0;
        }
        
        int m = M(root, 1);
        return m;
        
    }
};









class Solution{
    public:
        int maxDepth(TreeNode* root){
            if(!root){
                return 0;
            }
            
            int lh = maxDepth(root->left);
            int rh = maxDepth(root->right);
            
            return 1 + max(lh, rh);
        }
};
