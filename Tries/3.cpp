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
#define ll  long long

struct Node{
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void setEnd(){
        flag = 1;
    }

    bool isEnd(){
        return flag;
    }
};


class Trie {
private: 
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;

        for(int i =0 ; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }

        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;

        for(int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node = node->get(word[i]);
        }

        return node->isEnd();
    }

    bool completeString(string word){
        Node* node = root;

        for(int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node = node->get(word[i]);
            if(!node->isEnd()){
                return 0;
            }
        }

        return 1;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;

        for(int i = 0; i < prefix.size(); i++){
            if(!node->containsKey(prefix[i])){
                return 0;
            }
            node = node->get(prefix[i]);
        }
        
        return 1;
        // return node->flag;
    }
};

string mn(string a, string b){
    for(int i = 0; i < a.size(); i++){
        if(a[i] < b[i]){
            return a;
        }
        else if(b[i] < a[i]){
            return b;
        }
    }
    return a;
}


string completeString(int n, vector<string> &a){
    Trie T;
    for(int i = 0; i< n; i++){
        T.insert(a[i]);
    }

    string ans = "";

    for(int i =0 ; i < n; i++){
        if(T.completeString(a[i])){
            if(a[i].size() == ans.size()){
                ans = mn(ans, a[i]);
            }
            if(a[i].size() > ans.size()){
                ans = a[i];
            }
        }
    }
    if(!ans.size()) return "None";

    return ans;
}