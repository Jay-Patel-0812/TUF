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


template<typename T>

class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


vector<int> bottomView(BinaryTreeNode<int> * root){

    map<int, BinaryTreeNode<int>*> m;
    queue<pair<int, BinaryTreeNode<int>*> > q;
    pair<int, BinaryTreeNode<int>*> temp;
    q.push({0, root});
    
    if(!root){
        vector<int> ans;
        return ans;
    }
    
    int vo;
    BinaryTreeNode<int>* tnode;
    
    while(!q.empty()){
        temp = q.front();
        q.pop();
        vo = temp.first;
        tnode = temp.second;
        
        m[vo] = tnode;
        
        if(tnode->left){
            q.push({vo - 1, tnode->left});
        }
        if(tnode->right){
            q.push({vo + 1, tnode->right});
        }
    }
    
    vector<int> ans;
    
    for(auto i : m){
        ans.push_back(i.second->data);
    }
    
    return ans;
    
}


struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};


class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans; 
        if(root == NULL) return ans; 
        map<int,int> mpp; 
        queue<pair<Node*, int>> q; 
        q.push({root, 0}); 
        while(!q.empty()) {
            auto it = q.front(); 
            q.pop(); 
            Node* node = it.first; 
            int line = it.second; 
            mpp[line] = node->data; 
            
            if(node->left != NULL) {
                q.push({node->left, line-1}); 
            }
            if(node->right != NULL) {
                q.push({node->right, line + 1}); 
            }
        }
        
        for(auto it : mpp) {
            ans.push_back(it.second); 
        }
        return ans;  
    }
};