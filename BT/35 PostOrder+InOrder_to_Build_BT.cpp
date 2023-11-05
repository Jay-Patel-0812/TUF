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


TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
        if(inorder.size() != postorder.size()){
            return NULL;
        }
        map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        int s = inorder.size() - 1;

        TreeNode* root = builder(inorder, 0, s, postorder, 0, s, mp);
        return root;

    }

    TreeNode* builder(vector<int>& inorder, int si, int ei, vector<int>& postorder, int sp, int ep, map<int, int>& mp){
        if(si > ei || sp > ep)
            return NULL;
        TreeNode* node = new TreeNode(postorder[ep]);
        int i = mp[postorder[ep]];
        int n = i - si;
        TreeNode* leftt = builder(inorder, si, i - 1,postorder,sp, sp + n - 1, mp);
        TreeNode* rightt = builder(inorder, i + 1, ei, postorder, sp + n, ep - 1, mp);

        node->left = leftt;
        node->right = rightt;

        return node;
    }
    












class Solution {

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         if (inorder.size() != postorder.size())
            return NULL;
        map<int,int> hm;
        for (int i=0;i<inorder.size();++i)
            hm[inorder[i]] = i;
        return buildTreePostIn(inorder, 0, inorder.size()-1, postorder, 0, 
                              postorder.size()-1,hm);
    }
    TreeNode* buildTreePostIn(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe, 
                                     map<int,int> &hm){
        if (ps>pe || is>ie) return NULL;
        TreeNode* root = new TreeNode(postorder[pe]);
        int ri = hm[postorder[pe]];
        TreeNode* leftchild = buildTreePostIn(inorder, is, ri-1, postorder, ps, ps+ri-is-1, hm);
        TreeNode* rightchild = buildTreePostIn(inorder,ri+1, ie, postorder, ps+ri-is, pe-1, hm);
        root->left = leftchild;
        root->right = rightchild;
        return root;
    }
};