#include<vector>
#include<iostream>
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
#define ll long long


using namespace std;

// TC: O(N^2)
// SC: O(N)

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> V;
        for(int i = 1; i <= n; i++){
            V.push_back(i);
        }
        string ans;
        int fac = 1;
        for(int i = 1; i <= n; i++){
            fac *= i;
        }
        solve(V, k - 1, 0, n, ans, fac);
        return ans;
    }

    void solve(vector<int>& V, int k, int index, int n, string& ans, int fac){
        if(index == n){
            return;
        }
        fac = fac/(n - index);

        int t = k/fac;

        string temp = to_string(V[k / fac]);
        V.erase(V.begin() + k / fac);
        ans += temp;
        k = k%fac;
        

        solve(V, k, index + 1, n, ans, fac);
    }
};

// class Solution {
// public:
//     string getPermutation(int n, int k) {
//         set<int> s;
//         for(int i = 1; i <= n; i++){
//             s.insert(i);
//         }
//         string ans;
//         int fac = 1;
//         for(int i = 1; i <= n; i++){
//             fac *= i;
//         }
//         solve(s, k - 1, 0, n, ans, fac);
//         return ans;
//     }

//     void solve(set<int>& s, int k, int index, int n, string& ans, int fac){
//         if(index == n){
//             return;
//         }
//         fac = fac/(n - index);

//         int t = k/fac;
        
//         k = k%fac;

//         set<int>::iterator it = s.begin();
//         for(int i = 0; i < t; i++)  it++;
//         string temp = to_string(*it);
//         s.erase(it);

//         ans += temp;

//         solve(s, k, index + 1, n, ans, fac);
//     }
// };









using namespace std;

class Solution {
  public:
    string getPermutation(int n, int k) {
      int fact = 1;
      vector < int > numbers;
      for (int i = 1; i < n; i++) {
        fact = fact * i;
        numbers.push_back(i);
      }
      numbers.push_back(n);
      string ans = "";
      k = k - 1;
      while (true) {
        ans = ans + to_string(numbers[k / fact]);
        numbers.erase(numbers.begin() + k / fact);
        if (numbers.size() == 0) {
          break;
        }

        k = k % fact;
        fact = fact / numbers.size();
      }
      return ans;
    }
};

int main() {
  int n = 3, k = 3;
  Solution obj;
  string ans = obj.getPermutation(n, k);
  cout << "The Kth permutation sequence is " << ans << endl;

  return 0;
}
