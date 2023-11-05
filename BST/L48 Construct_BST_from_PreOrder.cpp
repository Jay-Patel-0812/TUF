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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bst(preorder, 0, preorder.size() - 1);
    }
    TreeNode* bst(vector<int>& preorder, int s, int e){
        if(e < s){
            return NULL;
        }
        int value = preorder[s];
        TreeNode* root = new TreeNode(value);
        int k = s + 1;
        while(k <= e && preorder[k] < value){
            k++;
        }
        root->left = bst(preorder, s + 1, k - 1);
        root->right = bst(preorder, k, e);

        return root;
    }
};

// TC: O(N)
// SC: O(1)

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& A) {
        int i = 0;
        return build(A, i, INT_MAX);
    }

    TreeNode* build(vector<int>& A, int& i, int bound) {
        if (i == A.size() || A[i] > bound) return NULL;
        TreeNode* root = new TreeNode(A[i++]);
        root->left = build(A, i, root->val);
        root->right = build(A, i, bound);
        return root;
    }
};