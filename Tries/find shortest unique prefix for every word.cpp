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

class trieNode{
  private:
  trieNode* links[26]; //to store next pointing node
  int prefix; //to store number of words start with this char
  public:
  
  trieNode()
  {
      for(int i=0;i<26;i++) links[i]=NULL;
      prefix=0;
  }
  
  bool find(char ch)
  {
      return links[ch-'a']!=NULL;
  }
  
  void put(char ch,trieNode* node)
  {
      links[ch-'a']=node;
  }
  
  trieNode* next(char ch)
  {
      return links[ch-'a'];
  }
  
  void increasePrefix() {
      prefix++;
  }
  
  int getPrefix() {
      return prefix;
  }
};


class Trie{
  private:
    trieNode* root;
  public:
    Trie()
    {
        root = new trieNode();
    }
    
    void insert(string word){
        auto node = root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->find(word[i])) node->put(word[i], new trieNode());
            node = node->next(word[i]);
            node->increasePrefix();
        }
    }
    
    int startsWith(string word)
    {
        auto node = root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->find(word[i])) return 0;
            node = node->next(word[i]);
        }
        
        return node->getPrefix();
    }
};

class Solution
{
    public:
    vector<string> findPrefixes(string arr[], int n)
    {
        //code here
        vector<string> ans;
        Trie* obj = new Trie();
        
        for(int i=0;i<n;i++) obj->insert(arr[i]);
        
        for(int i=0;i<n;i++)
        {
            string word = arr[i];
            string temp = ""; 
            for(int j=0;j<word.size();j++)
            {
                temp+=word[j];
                if(obj->startsWith(temp)==1) {
                    ans.push_back(temp);
                    break;
                }
            }
        }
        
        return ans;
    }
    
};