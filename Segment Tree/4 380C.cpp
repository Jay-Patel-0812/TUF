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


struct Node {

// Just use normal sort function: 
// vector<Node> nodes;
// sort(nodes.begin(), nodes.end());


// I have defined this operator functions in such a way that it sorts
// key1 in ascending order
// key2 in descending order
// key3 in ascending order

    ll key1;
    ll key2;
    ll key3;
    // Add other data members if needed

    // Constructor

    Node(){}

    Node(ll k1, ll k2, ll k3) : key1(k1), key2(k2), key3(k3) {}

    // Overload the less-than operator
    bool operator<(const Node& other) const {
        if(key1 == other.key1){
            if(key2 == other.key2){
                return key3 < other.key3;
            }
            return key2 > other.key2;
        }
        
        return key1 < other.key1;
    }

    // Overload the equality operator if needed
    bool operator==(const Node& other) const {
        return key1 == other.key1 && key2 == other.key2 && key3 == other.key3;
    }
};

// // Overload the << operator to print Node objects
// std::ostream& operator<<(std::ostream& os, const Node& node) {
//     os << node.key1 << " " << node.key2 << " "<< node.key3;
//     return os;
// }

// // Overload the >> operator to read input into Node objects
// std::istream& operator>>(std::istream& is, Node& node) {
//     is >> node.key1 >> node.key2 >> node.key3;
//     return is;
// }

// // Function template to take input for a vector of any data type
// template <typename T>
// void inputVector(vector<T>& v, ll start, ll end) {
//     for (ll i = start; i < end; ++i) {
//         cin >> v[i];
//     }
// }

// template <typename T>
// void outputVector(vector<T>& v, ll start, ll end) {
//     for (ll i = start; i < end; ++i) {
//         cout << v[i] << " ";
//     }cout << endl;
// }



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
// 11. Think Segment Tree, Fenwick Tree or any other advanced data structure...


// modpow, isPrime, power_vector, swap, node2, node3, primes_vector


// You have GitHub copilot + chat

class SGTree{
public:
    vector<Node> seg;

    SGTree(ll n){
        seg.resize(4 * n + 1);
    }

    void build(ll ind, ll low, ll high, string& s){
        if(low == high){
            if(s[low] == '('){
                seg[ind] = Node(0, 1, 0);
            }
            else{
                seg[ind] = Node(0, 0, 1);
            } 
            
            return;
        }

        ll mid = (low + high) >> 1;
        build(2 * ind + 1, low, mid, s);
        build(2 * ind + 2, mid + 1, high, s);

        Node t1 = seg[2 * ind + 1], t2 = seg[2 * ind + 2];

        ll t = min(t1.key2, t2.key3);

        seg[ind] = Node(t1.key1 + t2.key1 + t, t2.key2 + t1.key2 - t, t1.key3 + t2.key3 - t);
        return;
    }

    Node query(ll ind, ll low, ll high, ll l, ll r){
        if(l <= low && high <= r){
            return seg[ind];
        }

        if(r < low || high < l){
            return Node(0, 0, 0);
        }

        ll mid = (low + high) >> 1;

        Node t1 = query(2 * ind + 1, low, mid, l, r);
        Node t2 = query(2 * ind + 2, mid + 1, high, l, r);

        ll t = min(t1.key2, t2.key3);

        return Node(t1.key1 + t2.key1 + t, t2.key2 + t1.key2 - t, t1.key3 + t2.key3 - t);
    }
};


void solve(){
    string s;
    cin >> s;
    ll n = s.size(), m, l, r;

    cin >> m;

    SGTree sg(n);

    sg.build(0, 0, n - 1, s);

    Node temp;
    while (m > 0)
    {
        cin >> l >> r;
        l--, r--;
        temp = sg.query(0, 0, n - 1, l, r);
        cout << 2 * temp.key1 << endl;
        // cout << m <<' ' << l << " "<< r << endl;
        m--;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_cases;
    // cin >> test_cases;
    test_cases = 1;
    while(test_cases > 0){
        solve();
        test_cases--;
    }
    return 0;
}