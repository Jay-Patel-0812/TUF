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
    int count = 1;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;

        for(int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }

        if(!node->isEnd()){
            node->setEnd();
            count++;
        }
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

int countDistinctSubstrings(string &s)
{
    Trie T;
    int n = s.size();
    string t;
    for(int i = 0; i < n; i++){
        t = "";
        for(int j = i; j < n; j++){
            t += s[j];
            T.insert(t);
        }
    }

    return T.count;
}