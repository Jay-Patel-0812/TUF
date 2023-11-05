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

int kthSmallest(TreeNode* root, int k) {
        int ans = 0;

        TreeNode* temp = NULL, *cur = root;
        int counter = 0;

        while(cur){
            if(cur->left){
                temp = cur->left;

                while(temp->right && temp->right != cur){
                    temp = temp->right;
                }

                if(temp->right){
                    temp->right = NULL;
                    counter++;
                    if(counter == k){
                        ans = cur->val;
                    }
                    cur = cur->right;
                }
                else{
                    temp->right = cur;
                    cur = cur->left;
                }
            }
            else{
                counter++;
                if(counter == k){
                    ans = cur->val;
                }
                cur = cur->right;    
            }
        }
        return ans;
}






class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root){
            return 0;
        }

        TreeNode* temp = NULL, *cur = root;
        vector<TreeNode*> V;
        stack<TreeNode*> st;
        while(true){
            if(cur){
                st.push(cur);
                cur = cur->left;
            }
            else{
                if(st.empty()){
                    break;
                }
                cur = st.top();
                st.pop();
                V.push_back(cur);
                if(V.size() == k){
                    break;
                }
                cur = cur->right;
            }
        }

        if(V.size() == k){
            return V[k - 1]->val;
        }
        else return 0;
    }
};





struct node{
	int data;
	node *left,*right;
	node(int val)
	{
		data=val;
		left=NULL;
		right=NULL;
	}
};

node* insertBST(node *root,int val)
{
	if(root==NULL)
	{
		return new node(val);
	}
	if(val<root->data)
	{
		root->left=insertBST(root->left,val);
	}
	else
	{
		root->right=insertBST(root->right,val);
	}
	return root;
}

node* kthlargest(node* root,int& k)
{
	if(root==NULL)
	return NULL;
	
	node* right=kthlargest(root->right,k);
	if(right!=NULL)
	return right;
	k--;
	
	if(k==0)
	return root;
	
	return kthlargest(root->left,k);
}

node* kthsmallest(node* root,int &k)
{
	if(root==NULL)
	return NULL;
	
	node* left=kthsmallest(root->left,k);
	if(left!=NULL)
	return left;
	k--;
	if(k==0)
	return root;
	
	return kthsmallest(root->right,k);
}

int main()
{
	
	int arr[]={10,40,45,20,25,30,50},i;
	
	int k=3;
	node* root=NULL;
	for(i=0;i<7;i++)
	{
		root=insertBST(root,arr[i]);
	}
	cout<<"\n";
	
	int p=k;
	node* large=kthlargest(root,k);
	k=p;
	node* small=kthsmallest(root,k);
	if(large==NULL)
	{
		cout<<"Invalid input"<<"\n";
	}
	else
	cout<<"kth largest element is  "<<large->data<<"\n";
	
	if(small==NULL)
	{
		cout<<"Invalid input"<<"\n";
	}
	else
	{
		cout<<"kth smallest element is  "<<small->data<<"\n";
	}
}