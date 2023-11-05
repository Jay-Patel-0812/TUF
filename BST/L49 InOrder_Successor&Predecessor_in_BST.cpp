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

struct Node
{
	int key;
	struct Node *left, *right;
};

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

// Your code goes here
    int value = key;
    suc = NULL, pre = NULL;
    Node* temp = root;
    while(temp){
        if(temp->key > value){
            suc = temp;
            temp = temp->left;
        }
        else if(temp->key == value){
            temp = temp->right;
        }
        else{
            temp = temp->right;
        }
    }
    
    temp = root;
    
    while(temp){
        if(temp->key == value){
            temp = temp->left;
        }
        else if(temp->key < value){
            pre = temp;
            temp = temp->right;
        }
        else{
            temp = temp->left;
        }
    }
        
        // return succ;
}