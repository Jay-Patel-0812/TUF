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
    int endwith = 0, prefix = 0;

    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    void addPre(int i){
        prefix += i;
    }

    void addEnd(int i){
        endwith += i;
    }

    int equalTo(){
        return endwith;
    }

    int startWith(){
        return prefix;
    }
};


class Trie{

private:

    Node* root;
    public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->addPre(1);
        }

        node->addEnd(1);
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node = node->get(word[i]);
        }

        return node->equalTo();
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node = node->get(word[i]);
        }

        return node->startWith();
    }

    void erase(string &word){
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            // if(!node->containsKey(word[i])){
            //     put(word[i], new Node());
            // }
            node = node->get(word[i]);
            node->addPre(-1);
        }

        node->addEnd(-1);
    }
};
