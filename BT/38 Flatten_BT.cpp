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

// TC: O(N)
// SC: O(1)
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Morris
class Solution {
public:

    void flatten(TreeNode* root){
        TreeNode* temp = root, * prev;

        while(temp){
            if(temp->left){
                prev = temp->left;
                while(prev->right){
                    prev = prev->right;
                }
                prev->right = temp->right;

                temp->right = temp->left;

                temp->left = NULL;
            }
            temp = temp->right;
        }
    }
};







// TC: O(N)
// SC: O(N)



class Solution {
public:

    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        
        if(root){
            // prev = root->right;
            if(root->right) flatten(root->right);
            if(root->left) flatten(root->left);

            root->right = prev;
            root->left = NULL;

            prev = root;
        }
        else{
            return;
        }
    }
};


class Solution {
public:

    // TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        
        stack<TreeNode*> st;
        if(root){
            st.push(root);
        }
        else{
            return;
        }

        TreeNode* temp;

        while(!st.empty()){
            temp = st.top();
            st.pop();
            if(temp->right) st.push(temp->right);
            if(temp->left) st.push(temp->left);

            if(!st.empty()) temp->right = st.top();

            temp->left = NULL;
        }
    }
};











struct node {
  int data;
  struct node * left, * right;
};

class Solution {
  node * prev = NULL;
  public:
    void flatten(node * root) {
      if (root == NULL) return;

      flatten(root -> right);
      flatten(root -> left);

      root -> right = prev;
      root -> left = NULL;
      prev = root;
    }

};

class Solution {
  node * prev = NULL;
  public:
   void flatten(node * root) {
  if (root == NULL) return;
  stack < node * > st;
  st.push(root);
  while (!st.empty()) {
    node * cur = st.top();
    st.pop();

    if (cur -> right != NULL) {
      st.push(cur -> right);
    }
    if (cur -> left != NULL) {
      st.push(cur -> left);
    }
    if (!st.empty()) {
      cur -> right = st.top();
    }
    cur -> left = NULL;
  }

}


};

class Solution {
  node * prev = NULL;
  public:
   void flatten(node* root) {
        node* cur = root;
		while (cur)
		{
			if(cur->left)
			{
				node* pre = cur->left;
				while(pre->right)
				{
					pre = pre->right;
				}
				pre->right = cur->right;
				cur->right = cur->left;
				cur->left = NULL;
			}
			cur = cur->right;
		}
    }



};










struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> left -> left = newNode(3);
  root -> left -> right = newNode(4);
  root -> right = newNode(5);
  root -> right -> right = newNode(6);
  root -> right -> right -> left = newNode(7);

  Solution obj;

  obj.flatten(root);
  while(root->right!=NULL)
  {
      cout<<root->data<<"->";
      root=root->right;
  }
cout<<root->data;
  return 0;
}