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

    void markparents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parents){
        if(!root){
            return;
        }
        parents[root] = NULL;

        queue<TreeNode*> q;
        q.push(root);
        TreeNode* temp;
        int n;
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parents;
        markparents(root, parents);

        int distance = 0;
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = 1;
        int n;
        TreeNode* temp, *lleft, *rright, *pparent;

        while(!q.empty()){
            n = q.size();
            if(distance == k){
                break;
            }
            distance++;

            for(int i = 0; i < n; i++){
                temp = q.front();
                q.pop();
                lleft = temp->left;
                rright = temp->right;
                pparent = parents[temp];
                if(rright && !visited[rright]){
                    q.push(rright);
                    visited[rright] = 1;
                }
                if(lleft && !visited[lleft]){
                    q.push(lleft);
                    visited[lleft] = 1;
                }
                if(pparent && !visited[pparent]){
                    q.push(pparent);
                    visited[pparent] = 1;
                }
            }
        }
        vector<int> V;
        while(!q.empty()){
            temp = q.front();
            V.push_back(temp->val);
            q.pop();
        }

        return V;
    }
};











class Solution {
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track, TreeNode* target) {
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()) { 
            TreeNode* current = queue.front(); 
            queue.pop();
            if(current->left) {
                parent_track[current->left] = current;
                queue.push(current->left);
            }
            if(current->right) {
                parent_track[current->right] = current;
                queue.push(current->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track; // node -> parent
        markParents(root, parent_track, target); 
        
        unordered_map<TreeNode*, bool> visited; 
        queue<TreeNode*> queue;
        queue.push(target);
        visited[target] = true;
        int curr_level = 0;
        while(!queue.empty()) { /*Second BFS to go upto K level from target node and using our hashtable info*/
            int size = queue.size();
            if(curr_level++ == k) break;
            for(int i=0; i<size; i++) {
                TreeNode* current = queue.front(); 
                queue.pop();
                if(current->left && !visited[current->left]) {
                    queue.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]) {
                    queue.push(current->right);
                    visited[current->right] = true;
                }
                if(parent_track[current] && !visited[parent_track[current]]) {
                    queue.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }
        vector<int> result;
        while(!queue.empty()) {
            TreeNode* current = queue.front(); queue.pop();
            result.push_back(current->val);
        }
        return result;
    }
};