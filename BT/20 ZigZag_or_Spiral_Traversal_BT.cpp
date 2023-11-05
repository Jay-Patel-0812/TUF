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

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        
        if(!root){
            return ans;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int n;
        bool leftToRight = 1;
        TreeNode* temp;
        while(!q.empty()){
            n = q.size();
            vector<int> V(n, 0);
            for(int i = 0; i < n; i++){
                temp = q.front();
                q.pop();
                
                int k = leftToRight ? i : (n - 1 - i);
                V[k] = temp->val;
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            leftToRight = !leftToRight;
            ans.push_back(V);
        }
        return ans;
    }
};



class Node {
  public:
    int val;
  Node * left, * right;
};

vector < vector < int >> zigzagLevelOrder(Node * root) {
  vector < vector < int >> result;
  if (root == NULL) {
    return result;
  }

  queue < Node * > nodesQueue;
  nodesQueue.push(root);
  bool leftToRight = true;

  while (!nodesQueue.empty()) {
    int size = nodesQueue.size();
    vector < int > row(size);
    for (int i = 0; i < size; i++) {
      Node * node = nodesQueue.front();
      nodesQueue.pop();

      // find position to fill node's value
      int index = (leftToRight) ? i : (size - 1 - i);

      row[index] = node -> val;
      if (node -> left) {
        nodesQueue.push(node -> left);
      }
      if (node -> right) {
        nodesQueue.push(node -> right);
      }
    }
    // after this level
    leftToRight = !leftToRight;
    result.push_back(row);
  }
  return result;
}