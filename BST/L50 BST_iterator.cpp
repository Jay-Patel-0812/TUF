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

// SC: O(H)
// TC: O(1)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
    // TreeNode* cur;
    stack<TreeNode*> st;
public:

    BSTIterator(TreeNode* root) {
        TreeNode* cur = root;
        while(cur){
            st.push(cur);
            cur = cur->left;
        }
    }
    
    int next() {
        if(st.empty()){
            return 0;
        }
        else{ 
            TreeNode* temp = st.top();
            st.pop();
            int value = temp->val;
            if(temp->right){
                temp = temp->right;
                while(temp){
                    st.push(temp);
                    temp = temp->left;
                }
            }
            return value;
        }
    }
    
    bool hasNext() {
        if(st.empty()){
            return 0;
        }
        else{
            return 1;
        }
    }
};




class BSTIterator {
    stack<TreeNode *> myStack;
public:
    BSTIterator(TreeNode *root) {
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
        pushAll(tmpNode->right);
        return tmpNode->val;
    }

private:
    void pushAll(TreeNode *node) {
        for (; node != NULL; myStack.push(node), node = node->left);
    }
};