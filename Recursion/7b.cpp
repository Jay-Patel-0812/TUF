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

bool PrintF(ll index, vector<ll> a, vector<ll>& values, ll n, ll sum, ll& req){
    if(index >= n){
        if(sum != req){
            return false;
        }
        for(ll i = 0; i < a.size(); i++){
            cout << a[i] << " ";
        }
        cout << endl;
        return true;
    }

    a.push_back(values[index]);
    sum += values[index];
    if(PrintF(index + 1, a, values, n, sum, req)){
        return true;
    }
    a.pop_back();
    sum -= values[index];

    if(PrintF(index + 1, a, values, n, sum, req)){
        return true;
    }

    return false;
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

    PrintF(0, a, values, n, sum, req);
    return 0;
}