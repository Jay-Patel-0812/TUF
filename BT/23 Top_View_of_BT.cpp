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

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
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
            if(mpp.find(line) == mpp.end()) mpp[line] = node->data; 
            
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





    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };



vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    map<int, TreeNode<int>*> m;
    queue<pair< int, TreeNode<int>* > > q;
    pair<int, TreeNode<int>*> temp;
    if(!root){
        vector<int> ans;
        return ans;
    }
    temp = {0, root};
    q.push(temp);
    
    int vo;
    TreeNode<int>* tempnode;
    
    while(!q.empty()){
        temp = q.front();
        q.pop();
        vo = temp.first;
        tempnode = temp.second;
        
        if(m.find(vo) == m.end()){
            m[vo] = tempnode;
        }
        if(tempnode->left){
            temp.first = vo - 1;
            temp.second = tempnode->left;
            q.push(temp);
        }
        if(tempnode->right){
            temp.first = vo + 1;
            temp.second = tempnode->right;
            q.push(temp);
        }
    }
    
    vector<int> ans;
    
    for(auto i : m){
        ans.push_back(i.second->val);
    }
    
    return ans;
}