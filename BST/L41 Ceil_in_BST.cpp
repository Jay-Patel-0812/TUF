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

class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

int findCeil(BinaryTreeNode<int> *node, int x){
    BinaryTreeNode<int>* temp = node;
    
    int ceil = -1;
    while(temp){
        if(temp->data == x){
            ceil = x;
            break;
        }
        else if(temp->data > x){
            ceil = temp->data;
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
    }
    
    return ceil;
}