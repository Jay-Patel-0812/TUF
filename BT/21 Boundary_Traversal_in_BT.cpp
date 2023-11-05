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

struct Node
{
    int data;
    Node* left, * right;
}; 

class Solution {
public:
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        
        Node* cur = root;
        
        if(!cur->left && !cur->right){
            ans.push_back(cur->data);
            return ans;
        }
        
        ans.push_back(cur->data);
        if(cur->left){
            cur = cur->left;
        }
        else{
            cur = NULL;
        }
        
        while(cur){
            if(cur->left || cur->right){
                ans.push_back(cur->data);
                if(cur->left){
                    cur = cur->left;
                }
                else{
                    cur = cur->right;
                }
            }
            else{
                break;
            }
        }
        
        cur = root;
        
        Node* temp;
        stack<Node*> st;
        
        st.push(root);
        while(!st.empty()){
            temp = st.top();
            st.pop();
            if(!temp->left && !temp->right){
                ans.push_back(temp->data);
            }
            if(temp->right){
                st.push(temp->right);
            }
            if(temp->left){
                st.push(temp->left);
            }
        }
        
        
        cur = root->right;
        
        stack<int> st1;
        while(cur){
            if(cur->left || cur->right){
                st1.push(cur->data);
                if(cur->right){
                    cur = cur->right;
                }
                else{
                    cur = cur->left;
                }
            }
            else{
                break;
            }
        }
        
        int t1;
        while(!st1.empty()){
            t1 = st1.top();
            st1.pop();
            ans.push_back(t1);
        }
        
        return ans;
    }
};









struct node {
  int data;
  struct node * left, * right;
};

bool isLeaf(node * root) {
  return !root -> left && !root -> right;
}

void addLeftBoundary(node * root, vector < int > & res) {
  node * cur = root -> left;
  while (cur) {
    if (!isLeaf(cur)) res.push_back(cur -> data);
    if (cur -> left) cur = cur -> left;
    else cur = cur -> right;
  }
}
void addRightBoundary(node * root, vector < int > & res) {
  node * cur = root -> right;
  vector < int > tmp;
  while (cur) {
    if (!isLeaf(cur)) tmp.push_back(cur -> data);
    if (cur -> right) cur = cur -> right;
    else cur = cur -> left;
  }
  for (int i = tmp.size() - 1; i >= 0; --i) {
    res.push_back(tmp[i]);
  }
}

void addLeaves(node * root, vector < int > & res) {
  if (isLeaf(root)) {
    res.push_back(root -> data);
    return;
  }
  if (root -> left) addLeaves(root -> left, res);
  if (root -> right) addLeaves(root -> right, res);
}

vector < int > printBoundary(node * root) {
  vector < int > res;
  if (!root) return res;

  if (!isLeaf(root)) res.push_back(root -> data);

  addLeftBoundary(root, res);

  // add leaf nodes
  addLeaves(root, res);

  addRightBoundary(root, res);
  return res;
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
  root -> left = newNode(2);
  root -> left -> left = newNode(3);
  root -> left -> left -> right = newNode(4);
  root -> left -> left -> right -> left = newNode(5);
  root -> left -> left -> right -> right = newNode(6);
  root -> right = newNode(7);
  root -> right -> right = newNode(8);
  root -> right -> right -> left = newNode(9);
  root -> right -> right -> left -> left = newNode(10);
  root -> right -> right -> left -> right = newNode(11);

  vector < int > boundaryTraversal;
  boundaryTraversal = printBoundary(root);

  cout << "The Boundary Traversal is : ";
  for (int i = 0; i < boundaryTraversal.size(); i++) {
    cout << boundaryTraversal[i] << " ";
  }
  return 0;
}