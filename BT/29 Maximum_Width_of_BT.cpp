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
    long widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        queue<pair<TreeNode*, long> > q;
        q.push({root, 0});
        long ans = 0, n, cur_node;
        TreeNode* TN;

        while(!q.empty()){
            n = q.size();
            long min = q.front().second;
            long first, last;

            for(long i = 0; i < n; i++){
                TN = q.front().first;
                cur_node = q.front().second - min;
                q.pop();

                if(i == 0)      first = cur_node;
                if(i == n - 1)  last = cur_node;

                if(TN->left){
                    q.push({TN->left, 2*cur_node + 1});
                }
                if(TN->right){
                    q.push({TN->right, 2*cur_node + 2});
                }
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};





struct node {
  int data;
  struct node * left, * right;
};

int widthOfBinaryTree(node * root) {
  if (!root)
    return 0;
  int ans = 0;
  queue < pair < node * , int >> q;
  q.push({
    root,
    0
  });
  while (!q.empty()) {
    int size = q.size();
    int curMin = q.front().second;
    int leftMost, rightMost;
    for (int i = 0; i < size; i++) {
      int cur_id = q.front().second - curMin; // subtracted to prevent integer overflow
      node * temp = q.front().first;
      q.pop();
      if (i == 0) leftMost = cur_id;
      if (i == size - 1) rightMost = cur_id;
      if (temp -> left)
        q.push({
          temp -> left,
          cur_id * 2 + 1
        });
      if (temp -> right)
        q.push({
          temp -> right,
          cur_id * 2 + 2
        });
    }
    ans = max(ans, rightMost - leftMost + 1);
  }
  return ans;
}

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  struct node * root = newNode(1);
  root -> left = newNode(3);
  root -> left -> left = newNode(5);
  root -> left -> left -> left = newNode(7);
  root -> right = newNode(2);
  root -> right -> right = newNode(4);
  root -> right -> right -> right = newNode(6);

  int maxWidth = widthOfBinaryTree(root);
  cout << "The maximum width of the Binary Tree is " << maxWidth;

  return 0;
}
