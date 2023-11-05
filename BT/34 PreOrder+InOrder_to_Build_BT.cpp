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

// TC: O(NlogN)
// SC: O(N )

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() != inorder.size()){
            return NULL;
        }
        map<int, int> mp;
        for(int i =0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        int s = preorder.size();

        TreeNode* root = builder(preorder,0, s - 1, inorder, 0, s - 1, mp);

        return root;
    }

    TreeNode* builder(vector<int>& preorder,int sp, int ep, vector<int>& inorder, int si, int ei, map<int, int>& mp){
        if(sp > ep || si > ei){
            return NULL;
        }
        int value = preorder[sp];
        TreeNode* node = new TreeNode(value);
        int i = mp[value];
        int n = i - si;
        TreeNode* leftt = builder(preorder, sp + 1, sp + n, inorder, si, i - 1, mp);
        TreeNode* rightt = builder(preorder, sp + n + 1, ep, inorder, i + 1, ei, mp);

        node->right = rightt;
        node->left = leftt;

        return node;
    }
};












struct node {
  int data;
  struct node * left, * right;
};

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}
node * constructTree(vector < int > & preorder, int preStart, int preEnd, vector< int > & inorder, int inStart, int inEnd, map < int, int > & mp) {
  if (preStart > preEnd || inStart > inEnd) return NULL;

  node * root = newNode(preorder[preStart]);
  int elem = mp[root -> data];
  int nElem = elem - inStart;

  root -> left = constructTree(preorder, preStart + 1, preStart + nElem, inorder, inStart, elem - 1, mp);
  root -> right = constructTree(preorder, preStart + nElem + 1, preEnd, inorder, 
  elem + 1, inEnd, mp);

  return root;
}

node * buildTree(vector < int > & preorder, vector < int > & inorder) {
  int preStart = 0, preEnd = preorder.size() - 1;
  int inStart = 0, inEnd = inorder.size() - 1;

  map < int, int > mp;
  for (int i = inStart; i <= inEnd; i++) {
    mp[inorder[i]] = i;
  }

  return constructTree(preorder, preStart, preEnd, inorder, inStart, inEnd, mp);
}

int main() {

  vector<int> preorder{10,20,40,50,30,60};
  vector<int> inorder{40,20,50,10,60,30};
  node * root = buildTree(preorder, inorder);
  return 0;
}
