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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int> > > nodes;
        queue<pair< TreeNode*, pair<int, int> > > q;
        
        q.push({root, {0, 0}});
        
        pair<TreeNode*, pair<int, int > > temp;
        TreeNode* n1;
        int value, vo, level;
        
        while(!q.empty()){
            temp = q.front();
            q.pop();
            n1 = temp.first;
            value = temp.first->val;
            vo = temp.second.first;
            level = temp.second.second;
            nodes[vo][level].insert(value);
            
            if(n1->left){
                q.push({n1->left, {vo - 1, level + 1}});
            }
            if(n1->right){
                q.push({n1->right, {vo + 1, level + 1}});
            }
        }
        
        vector<vector<int> > ans;

        for (auto p: nodes) {
            vector < int > col;
            for (auto t: p.second) {
                col.insert(col.end(), t.second.begin(), t.second.end());
            }
            ans.push_back(col);
        }
             
        return ans;
    }
};