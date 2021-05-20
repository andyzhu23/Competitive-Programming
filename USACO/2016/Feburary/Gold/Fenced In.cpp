/*
 * Author: Andy Zhu
 */

// include
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <memory>
#include <memory.h>
#include <string>
#include <algorithm>
#include <bitset>
#include <iterator>
#include <deque>
#include <random>

// define
#define endl "\n"
#define l_b lower_bound
#define u_b upper_bound
#define ins insert
#define fir first
#define sec second
#define lc (rt << 1)
#define rc (rt << 1 | 1)
#define pb push_back
#define pf push_front
#define mp make_pair
#define random(a, b) rand() % (b - a + 1) + a
#define log(a, b) log(a) / log(b)
#define UM unordered_map;
#define US unordered_set;
#define V vector;
#define ALL(v) v.begin(), v.end()

// using
using ll = long long;
using lb = long double;
using namespace std;

// typedef
typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;
typedef pair<string, string> PS;
typedef vector<int> VI;
typedef vector<PI> VPI;
typedef vector<ll> VLL;
typedef vector<PLL> VPLL;
typedef queue<int> QI;
typedef stack<int> STKI;
typedef deque<int> DQI;
typedef set<int> SI;
typedef set<ll> SLL;
typedef set<string> SS;
typedef unordered_set<int> USI;
typedef unordered_set<ll> USLL;
typedef unordered_set<string> USS;
typedef map<int, int> MI;
typedef map<ll, ll> MLL;
typedef map<string, string> MS;
typedef unordered_map<int, int> UMI;
typedef unordered_map<ll, ll> UMLL;
typedef unordered_map<string, string> UMS;

// common variables
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int dir[8][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {-1, 1}, {1, -1}, {-1, -1}, {1, 1}};

// common functions
inline int lowbit(int x){return x & (- x);}
inline bool CMP(int a, int b){return a > b;}
inline void copy(int a[], int b[], int sz){for(int i = 0;i<=sz;i++) a[i] = b[i];}
inline int gcd(int a, int b){if(a == 0) return b; if(b == 0) return a; return gcd(b, a % b);}
inline int lcm(int a, int b){return a / gcd(a, b) * b;}
inline int getMid(int l, int r){return (l + r) >> 1;}
inline ll fast_pow(ll a, ll b){if(b == 1) return a;ll tmp = fast_pow(a, b / 2);if(b % 2 == 1) return tmp * tmp * a;else return tmp * tmp;}
inline bool is_prime(ll x){for(ll i = 2; i * i <= x;i++) if(x % i == 0) return false; return true;}

//--------------------End of Template---------------------
const int N = 2e3 + 10;
int A, B, n, m, v[N], h[N], f[N * N];

inline int node(int i, int j){
    return i * m + j;
}

inline int Find(int x){
    return x == f[x] ? x : f[x] = Find(f[x]);
}

inline bool merge(int u, int v){
    int fu = Find(u);
    int fv = Find(v);
    if(fu == fv) return false;
    f[f[u]] = fv;
    return true;
}

int main(){
    srand(time(0));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("fencedin.in", "r", stdin);
    freopen("fencedin.out", "w", stdout);
    cin>>A>>B>>n>>m;
    
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    for(int i = 0;i<m;i++){
        cin >> h[i];
    }

    sort(v, v + n + 1);
    sort(h, h + m + 1);
    for(int i = 0;i<n;i++){
        v[i] = v[i + 1] - v[i];
    }
    for(int i = 0;i<m;i++){
        h[i] = h[i + 1] - h[i];
    }

    v[n] = B - v[n];
    h[m] = A - h[m];
    sort(v, v + n + 1);
    sort(h, h + m + 1);
    n++, m++;
    for(int i = 0;i<n * m;i++) f[i] = i;

    int vi = 0, hi = 0;
    ll ans = 0;
    while(vi < n || hi < m){
        if(hi == m || (vi<n && v[vi] < h[hi])){
            for(int i = 0;i + 1 <m;i++){
                if(merge(node(vi, i), node(vi, i + 1))){
                    ans += v[vi];
                }
            }
            ++vi;
        } else {
            for(int i = 0;i + 1 <n;i++){
                if(merge(node(i, hi), node(i + 1, hi))){
                    ans += h[hi];
                }
            }
            ++hi;
        }
    }
    cout<<ans<<endl;
    return 0;
}
