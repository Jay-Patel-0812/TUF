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
// SC: O(H) * 2

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTiterator{
private:
    stack<TreeNode*> st1;
    // stack<TreeNode*> st2;
public:
    BSTiterator(TreeNode* root) {
        TreeNode* cur = root;
        while(cur){
            st1.push(cur);
            cur = cur->left;
        }

    }
    
    int next() {
        if(st1.empty()){
            return 0;
        }
        else{ 
            TreeNode* temp = st1.top();
            st1.pop();
            int value = temp->val;
            if(temp->right){
                temp = temp->right;
                while(temp){
                    st1.push(temp);
                    temp = temp->left;
                }
            }
            return value;
        }
    }
    
    bool hasNext() {
        return !st1.empty();
    }

};

class BSTRiterator{
private:
    // stack<TreeNode*> st1;
    stack<TreeNode*> st2;
public:
    BSTRiterator(TreeNode* root) {
        TreeNode* cur = root;
        while(cur){
            st2.push(cur);
            cur = cur->right;
        }
    }

    int previous(){
        if(st2.empty()){
            return 0;
        }
        else{
            TreeNode* temp = st2.top();
            st2.pop();
            int value = temp->val;
            if(temp->left){
                temp = temp->left;
                while(temp){
                    st2.push(temp);
                    temp = temp->right;
                }
            }
            return value;
        }
    }

    bool hasPrevious(){
        return !st2.empty();
    }

};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTiterator* obj = new BSTiterator(root);
        BSTRiterator* obj1 = new BSTRiterator(root);

        int t1 = 0, t2 = 0;
        if(obj->hasNext()){
            t1 = obj->next();
        }
        if(obj1->hasPrevious()){
            t2 = obj1->previous();
        }
        
        while(1){
            if(t1 == t2){
                return 0;
            }
            else if(t1 + t2 == k){
                return 1;
            }
            else if(t1 + t2 > k){
                if(obj1->hasPrevious()){
                    t2 = obj1->previous();
                }
                else{
                    return 0;
                }
            }
            else{
                if(obj->hasNext()){
                    t1 = obj->next();
                }
                else{
                    return 0;
                }
            }
        }
        return 0;
    }
};


class BSTIterator {
    stack<TreeNode *> myStack;
    bool reverse = true; 
public:
    BSTIterator(TreeNode *root, bool isReverse) {
        reverse = isReverse; 
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !myStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        if(!reverse) pushAll(tmpNode->right);
        else pushAll(tmpNode->left);
        return tmpNode->val;
    }

private:
    void pushAll(TreeNode *node) {
        for(;node != NULL; ) {
             myStack.push(node);
             if(reverse == true) {
                 node = node->right; 
             } else {
                 node = node->left; 
             }
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false; 
        BSTIterator l(root, false); 
        BSTIterator r(root, true); 
        
        int i = l.next(); 
        int j = r.next(); 
        while(i<j) {
            if(i + j == k) return true; 
            else if(i + j < k) i = l.next(); 
            else j = r.next(); 
        }
        return false; 
    }
};