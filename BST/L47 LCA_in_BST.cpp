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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int s = p->val, l = q->val, t;
        if(s > l){
            t = s;
            s = l;
            l = t;
        }

        TreeNode* temp = root;

        int value;
        while(temp){
            value = temp->val;
            if(value == s || value == l || (s < value && value < l)){
                return temp;
            }
            else if(s < value){
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
        }

        return temp;
        
    }
};
