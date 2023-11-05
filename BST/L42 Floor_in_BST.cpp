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


int floorInBST(TreeNode<int> * root, int X)
{
    int floor = -1;
    TreeNode<int>* temp;
    temp = root;
    
    while(temp){
        if(temp->val == X){
            return X;
        }
        else if(temp->val > X){
            temp = temp->left;
        }
        else{
            floor = temp->val;
            temp = temp->right;
        }
    }
    
    return floor;
}