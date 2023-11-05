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

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

// TC: O(N)
// SC: O(H), H is height of the tree

void fun(BinaryTreeNode<int>* node, int level, vector<int>& ans){
    if(!node){
        return;
    }
    if(level == ans.size()){
        ans.push_back(node->data);
    }
    
    fun(node->left, level + 1, ans);
    fun(node->right, level + 1, ans);
    
}

void printLeftView(BinaryTreeNode<int> *root)
{
    vector<int> ans;
//     queue<BinaryTreeNode<int>*> q;
    fun(root, 0, ans);
    for(int i = 0; i <ans.size(); i++){
        cout << ans[i] << " ";
    }
    
}






















// iterative level order:
// SC: more than recursive solution
// TC: O(N)


void printLeftView(BinaryTreeNode<int> *root)
{
        map<int, BinaryTreeNode<int> * > m;
        vector<int> ans;
        
        queue<BinaryTreeNode<int>*> q;
        if(root){
            q.push(root);
        }
        else{
            return;
        }
        
        int n = q.size();
        int level = 0;
        BinaryTreeNode<int>* temp;
        
        while(!q.empty()){
            n = q.size();
            
            for(int i =0; i < n; i++){
                temp = q.front();
                q.pop();
                
                if(!m.count(level)){
                    m[level] = temp;
                }
                    
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            level++;
        }
        
        for(auto i: m){
            ans.push_back(i.second->data);
        }
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
}