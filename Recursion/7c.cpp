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

ll PrintF(ll index, vector<ll> a, vector<ll>& values, ll n, ll sum, ll& req){
    ll x = 0, y = 0;
    if(index >= n){
        if(sum != req){
            return 0;
        }
        for(ll i = 0; i < a.size(); i++){
            cout << a[i] << " ";
        }
        cout << endl;
        return 1;
    }

    a.push_back(values[index]);
    sum += values[index];
    x = PrintF(index + 1, a, values, n, sum, req);
    a.pop_back();
    sum -= values[index];

    y = PrintF(index + 1, a, values, n, sum, req);

    return (x + y);
}


#include<iostream>


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll val[] = {3, 1, 2, 1};
    ll sum = 0, req = 3;
    ll n = sizeof(val)/sizeof(ll);
    vector<ll> a, values(val, val + n);

    ll ans = PrintF(0, a, values, n, sum, req);
    cout << "Count: " << ans << endl;
    return 0;
}