#include<bits/stdc++.h>

using namespace std;
#define ll  long long int
#define ull unsigned long long int
#define endl "\n"
#define all(v) v.begin(), v.end()
#define debug1(x) cout<<#x<<" : "<<x<<endl;
#define debug2(x,y) cout<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<"\t"<<#z<<" : "<<z<<endl;
#define debug4(x,y,z,w) cout<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<"\t"<<#z<<" : "<<z<<"\t"<<#w<<" : "<<w<<endl;
#define pb push_back
#define ff first
#define ss second
#define setbits(x) __builtin_pinxcountll(x)
#define ctz(x) __builtin_ctzll(x)
#define clz(x) __builtin_clzll(x)
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
#define pi 3.14159265358979
#define flag(A) cout << #A << endl;
#define out(x) cout << x << endl;
#define CIN(a, start, end) for(ll i = start; i < end; i++){  \
                      cin >> a[i];  \
                  }
#define COUT(a, start, end) for(int i = start; i < end; i++)    \
                    { cout << a[i] <<  " ";}   \
                    cout << endl;
ll MOD = 1e9+7;
#define INTMIN (1<<32 - 1)
#define LLMIN (1LL<<64 - 1)

 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
unsigned long long MX = 1000000007;
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(unordered_map <T, V> v);
template <class T, class V> void _print(multimap <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]"; }
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(multimap <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
bool isPowerOfTwo (ll x) {return x && (!(x & (x - 1)));}
vector<ll> sieve(int n) {int*v = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (v[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)v[j] = 1;} return vect;}
ll modI(ll a, ll m=MOD) { ll m0=m,y=0,x=1;  if(m==1) return 0;  while(a>1)  { ll q=a/m; ll t=m;  m=a%m;  a=t; t=y; y=x-q*y;  x=t; } if(x<0) x+=m0; return x;}
const int SQRT_MAX = 100005;

ll POW(ll x, ll n){
    if (n == 0) return 1;
    long long u = POW(x,n/2); 
    u = (u*u);
    if (n%2 == 1) u = (u*x);
    return u; 
}

int modpow(int x, int n, int m){ 
    if (n == 0) return 1%m;
    long long u = modpow(x,n/2,m); 
    u = (u*u)%m;
    if (n%2 == 1) u = (u*x)%m;
    return u; 
}

bool isPrime(int n) {
    if (n < 2) return false;
    for (int x = 2; x*x <= n; x++) {
        if (n%x == 0) 
            return false; 
    }
    return true; 
}

void swap(ll& a, ll& b){
    ll t = a;
    a = b;
    b = t;
}

vector<ll> power_vector(ll base, ll size){
    vector<ll> V(size);
    V[0] = 1;
    for(ll i = 1; i < size; i++){
        V[i] = base * V[i - 1];
    }
    return V;
}



// 1. Think Greedy
// 2. Think Tries
// 3. Think Brute Force
// 4. Think of reverse engineering
// 5. Think DP [ check constraints carefully ]
// 6. Check base cases for DP and prove solution for Greedy
// 7. Think Graph
// 8. Think binary search
// 9. Think brute force
// 10. Writing down a test case really helps to think better. 


// modpow, isPrime, power_vector, swap, node2, node3, primes_vector


// You have GitHub copilot + chat




// Segment Tree:
// Space C: 4N
// Build TC: O(N)
// Query TC:	O(logN)
// Update TC: O(logN)


void build(int ind, int low, int high, int arr[], ll seg[]) {
    if (low == high) {
        seg [ind] = arr[low];
        return;
    }

    int mid = (low + high) / 2;
    build(2 * ind + 1, low, mid, arr, seg) ;
    build (2 * ind + 2, mid + 1, high, arr, seg);
    seg[ind] = min(seg [2 * ind + 1], seg [2 * ind + 2]);
}

int query(int ind, int low, int high, int l, int r, ll seg[]) {
// no overlap

// Ir low high or low high 1 r

    if(r < low || high < l) return INT_MAX;

    // complete overlap
    // Il low high ri
    if(l <= low && high <= r) return seg[ind];

    int mid = (low + high) >> 1;
    int left = query(2*ind+1, low, mid, l, r, seg);
    int right = query (2*ind+2, mid+1, high,l, r, seg);
    return min(left, right);
}


void update(ll ind, ll low, ll high, ll i, ll val, ll seg[]){
    if(low == high){
        seg[ind] = val;
        return;  
    }

    ll mid = (low + high)/2, left, right;

    if(mid < i){
        update(2 * ind + 2, mid + 1, high, i, val, seg);
    }
    else{
        update(2 * ind + 1, low, mid, i, val, seg);
    }

    seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    return;
}


void solve() {

    int n;

    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) cin >> arr[i];

    ll seg[4 * n];

    build(0, 0, n - 1, arr, seg) ;

    cout << seg[0] << endl;

    int q;

    cin >> q;

    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            cout << query (0,0, n-1, l, r, seg) << endl;
        }
        else {
            int i, val;
            cin >> i >> val;
            update(0, 0, n-1, i, val, seg);
            arr[i] = val;
        }
    }
}