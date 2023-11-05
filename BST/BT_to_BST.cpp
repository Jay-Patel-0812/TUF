#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<unordered_map>
#include<set>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<list>
#include<numeric>
#include<string>
#include<sstream>


using namespace std;
#define ll  long long int

#define ll long long

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void inOrder(Node* root, vector<Node*>& V){
    if(root->left)  inOrder(root->left, V);
    V.push_back(root);
    if(root->right) inOrder(root->right, V);
}

class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node *binaryTreeToBST (Node *root)
    {
        vector<Node*> V;
        if(!root)   return NULL;
        
        inOrder(root, V);
        
        // mergeSort(V, 0, V.size() - 1);
        
        vector<int> b(V.size(), 0);
        
        for(ll i = 0; i < b.size(); i++){
            b[i] = V[i]->data;
        }
        
        sort(b.begin(), b.end());
        
        for(ll i = 0; i < b.size(); i++){
            V[i]->data = b[i];
        }
        
        return root;
    }
};