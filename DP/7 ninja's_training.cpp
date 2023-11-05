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

// Time Complexity: O(N*4*3)
// Space Complexity: O(N*4)

ll solve(vector<vector<ll> >& dp, vector<vector<int> >& points, ll index, ll act, ll n){
    if(index == n){
        return 0;
    }
    if(dp[index][act] != -1){
        return dp[index][act];
    }

    ll x1 = solve(dp, points, index + 1, (act + 1)%3, n);
    ll x2 = solve(dp, points, index + 1, (act + 2)%3, n);

    dp[index][act] = max(x1, x2) + points[index][act];

    return dp[index][act];

}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<ll> > dp(n, vector<ll> (3, -1));
    solve(dp, points, 0, 0, n);
    solve(dp, points, 0, 1, n);
    solve(dp, points, 0, 2, n);

    ll ans = max(dp[0][0], dp[0][1]);
    ans = max(dp[0][2], ans);

    return ans;
}



// Time Complexity: O(N*4*3)
// Space Complexity: O(4)


int ninjaTraining(int n, vector < vector < int > > & points) {

  vector < int > prev(4, 0);

  prev[0] = max(points[0][1], points[0][2]);
  prev[1] = max(points[0][0], points[0][2]);
  prev[2] = max(points[0][0], points[0][1]);
  prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

  for (int day = 1; day < n; day++) {

    vector < int > temp(4, 0);
    for (int last = 0; last < 4; last++) {
      temp[last] = 0;
      for (int task = 0; task <= 2; task++) {
        if (task != last) {
          temp[last] = max(temp[last], points[day][task] + prev[task]);
        }
      }
    }

    prev = temp;

  }

  return prev[3];
}

int main() {

  
  vector<vector<int> > points = {{10,40,70},
                                 {20,50,80},
                                 {30,60,90}};

  int n = points.size();
  cout << ninjaTraining(n, points);
}