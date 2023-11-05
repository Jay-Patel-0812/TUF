#include<vector>
#include<iostream>
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
#define ll long long


using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
  
    void getparents(unordered_map<Node*, Node*>& parents, Node* root){
        parents[root] = NULL;
        queue<Node*> q;
        q.push(root);
        int n;
        Node* temp;
        while(!q.empty()){
            n = q.size();
            for(int i = 0; i < n; i++){
                temp = q.front();
                q.pop();
                if(temp->left){
                    parents[temp->left] = temp;
                    q.push(temp->left);
                }
                if(temp->right){
                    parents[temp->right] = temp;
                    q.push(temp->right);
                }
            }
        }
        
    }

    Node* findd(int target, Node* root){
        if(root->data == target){
            return root;
        }
        
        Node* l = NULL, *r = NULL;
        if(root->left){
            l = findd(target, root->left);
        }
        if(l){
            return l;
        }
        
        
        if(root->right){
            r = findd(target, root->right);
        }
        if(r){
            return r;
        }
        
        return NULL;
    }
    
    int minTime(Node* root, int target) {
        if(!root){
            return 0;
        }
        unordered_map<Node*, Node*> parents;
        unordered_map<Node*, bool> visited;
        getparents(parents, root);
        
        int count = -1, n;
        Node* parentt, *leftt, *rightt, *targett, *temp;
        
        targett = findd(target, root);
        
        if(!targett){
            return 0;
        }
        
        queue<Node*> q;
        q.push(targett);
        visited[targett] = 1;
        
        
        while(!q.empty()){
            count++;
            n = q.size();
            
            for(int i = 0; i < n; i++){
                temp = q.front();
                q.pop();
                leftt = temp->left;
                rightt = temp->right;
                parentt = parents[temp];
                if(leftt && !visited[leftt]){
                    visited[leftt] = 1;
                    q.push(leftt);
                }
                
                if(rightt && !visited[rightt]){
                    visited[rightt] = 1;
                    q.push(rightt);
                }
                
                if(parentt && !visited[parentt]){
                    visited[parentt] = 1;
                    q.push(parentt);
                }
            }
        }
        
        return count;
    }
};




















template<typename T>

class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };



int findMaxDistance(map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> &mpp, BinaryTreeNode<int>* target) {
    queue<BinaryTreeNode<int>*> q; 
    q.push(target); 
    map<BinaryTreeNode<int>*,int> vis; 
    vis[target] = 1;
    int maxi = 0; 
    while(!q.empty()) {
        int sz = q.size();
        int fl = 0; 
        for(int i = 0;i<sz;i++) {
            auto node = q.front();
            q.pop();
            if(node->left && !vis[node->left]) {
                fl = 1; 
                vis[node->left] = 1; 
                q.push(node->left); 
            }
            if(node->right && !vis[node->right]) {
                fl = 1; 
                vis[node->right] = 1; 
                q.push(node->right); 
            }
            
            if(mpp[node] && !vis[mpp[node]]) {
                fl = 1; 
                vis[mpp[node]] = 1; 
                q.push(mpp[node]); 
            } 
        }
        if(fl) maxi++; 
    }
    return maxi; 
}
BinaryTreeNode<int>* bfsToMapParents(BinaryTreeNode<int>* root, 
                                     map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> &mpp, int start) {
    queue<BinaryTreeNode<int>*> q; 
    q.push(root); 
    BinaryTreeNode<int>* res; 
    while(!q.empty()) {
        BinaryTreeNode<int>* node = q.front(); 
        if(node->data == start) res = node; 
        q.pop(); 
        if(node->left) {
            mpp[node->left] = node; 
            q.push(node->left); 
        }
        if(node->right) {
            mpp[node->right] = node;
            q.push(node->right); 
        }
    }
    return res; 
}
int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> mpp; 
    BinaryTreeNode<int>* target = bfsToMapParents(root, mpp, start); 
    int maxi = findMaxDistance(mpp, target); 
    return maxi; 
}
 

