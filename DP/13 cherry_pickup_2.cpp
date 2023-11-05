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

// TC: O(N * M * M) * 9
// SC: O(N * M * M)

class Solution {
public:
    int solve(int j1, int j2, int i, vector<vector<int> > & grid, vector<vector<vector<int> > >& V, int c, int r){
        if(j1 < 0 || j2 < 0 || j1 >= c || j2 >= c){
            return 1e-8;
        }
        if(i == (r - 1)){
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }

        if(V[i][j1][j2] != -1){
            return V[i][j1][j2];
        }


        int maxi = 0, temp;
        for(int a = -1; a <= 1; a++){
            for(int b = -1; b <= 1; b++){
                if(j1 == j2) temp = grid[i][j1];
                else temp = grid[i][j2] + grid[i][j1];

                temp += solve(j1 + a, j2 + b, i + 1, grid, V, c, r);
                if(temp > maxi){
                    maxi = temp;
                }
            }
        }

        return V[i][j1][j2] = maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<vector<int> > > V(rows, vector<vector<int> > (cols, vector<int> (cols, -1)));

        solve(0, cols - 1, 0, grid, V, cols, rows);
        return V[0][0][cols - 1];
    }
};



// SC: O(M * M)


int maximumChocolates(int n, int m, vector < vector < int >> & grid) {
  // Write your code here.
  vector < vector < int >> front(m, vector < int > (m, 0)), cur(m, vector < int > 
  (m, 0));

  for (int j1 = 0; j1 < m; j1++) {
    for (int j2 = 0; j2 < m; j2++) {
      if (j1 == j2)
        front[j1][j2] = grid[n - 1][j1];
      else
        front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
    }
  }

  //Outer Nested Loops for travering DP Array
  for (int i = n - 2; i >= 0; i--) {
    for (int j1 = 0; j1 < m; j1++) {
      for (int j2 = 0; j2 < m; j2++) {

        int maxi = INT_MIN;

        //Inner nested loops to try out 9 options
        for (int di = -1; di <= 1; di++) {
          for (int dj = -1; dj <= 1; dj++) {

            int ans;

            if (j1 == j2)
              ans = grid[i][j1];
            else
              ans = grid[i][j1] + grid[i][j2];

            if ((j1 + di < 0 || j1 + di >= m) ||
              (j2 + dj < 0 || j2 + dj >= m))

              ans += -1e9;
            else
              ans += front[j1 + di][j2 + dj];

            maxi = max(ans, maxi);

          }
        }
        cur[j1][j2] = maxi;
      }
    }
    front = cur;
  }

  return front[0][m - 1];

}

int main() {

  vector<vector<int> > matrix{
      {2,3,1,2},
      {3,4,2,2},
      {5,6,3,5},
  };

  int n = matrix.size();
  int m = matrix[0].size();

  cout << maximumChocolates(n, m, matrix);
}