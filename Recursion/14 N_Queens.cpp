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

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> matrix;
        string temp(n, '.');
        for(int i = 0; i < n; i++){
            matrix.push_back(temp);
        }
        vector<vector<string> > ans;
        vector<bool> upper(2*n - 1, 0), lower(2*n - 1, 0), left(2*n - 1, 0);

        solve(0, ans, matrix, upper, lower, left, n);

        return ans;
    }

    void solve(int col, vector<vector<string> >& a, vector<string>& m, vector<bool>& u, vector<bool>& lo, vector<bool>& l, int& n){
        if(col == n){
            a.push_back(m);
            return;
        }

        for(int i = 0; i < n; i++){
            if(u[n - 1 + col - i] || lo[col + i] || l[i]){
                continue;
            }

            u[n - 1 + col - i] = 1;
            lo[col + i] = 1;
            l[i] = 1;
            m[i][col] = 'Q';

            solve(col + 1, a, m, u, lo, l, n);

            u[n - 1 + col - i] = 0;
            lo[col + i] = 0;
            l[i] = 0;
            m[i][col] = '.';
        }
    }
};