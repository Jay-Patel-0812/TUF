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

struct Node
{
    int data;
    Node* left, * right;
};

void solve(Node* root, map<int, vector<int> >& m, int level){
    if(m.count(level)){
        m[level].push_back(root->data);
    }
    else{
        vector<int> temp(1, root->data);
        m[level] = temp;
    }
    
    if(root->left){
        solve(root->left, m, level + 1);
    }
    if(root->right){
        solve(root->right, m, level);
    }
    
    
}

vector<int> diagonal(Node *root)
{
   map<int, vector<int> > m;
   vector<int> V;
   if(!root)    return V;    
   
   solve(root, m, 0);
   
   map<int, vector<int> >::iterator it;
   for(it = m.begin(); it != m.end(); it++){
       V.insert(V.end(), it->second.begin(), it->second.end());
   }
   
   return V;
}
