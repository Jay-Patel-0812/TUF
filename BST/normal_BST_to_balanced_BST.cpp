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

Node* builder(vector<Node*> V, int start, int end){
    if(start == end){
        return V[start];
    }
    if(start > end){
        return NULL;
    }
    
    int mid = (start + end)/2;
    Node* root = V[mid];
    
    root->left = builder(V, start, mid - 1);
    root->right = builder(V, mid + 1, end);
    
    return root;
}

Node* buildBalancedTree(Node* root)
{
	vector<Node*> V;
	if(!root)   return NULL;
	
	inOrder(root, V);
	
	for(int i = 0; i < V.size(); i++){
	    V[i]->left  = NULL;
	    V[i]->right = NULL;
	}
	
	root = builder(V, 0, V.size() - 1);
	
	return root;
}
