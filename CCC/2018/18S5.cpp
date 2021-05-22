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

//---------------------End of Template---------------------

const int N = 1e5 + 10;
int n, m, p, q;
VI P(N), F(N);

struct path{
    int u, v, w;
};

inline bool cmp(path a, path b){
    return a.w < b.w;
}

inline int Find(VI& f, int x){
    return f[x] == x ? x : f[x] = Find(f, f[x]);
}

inline bool merge(VI& f, int u, int v){
    int fu = Find(f, u);
    int fv = Find(f, v);
    if(fu == fv) return false;
    f[fu] = fv;
    return true;
}

int main(){
    srand(time(0));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>p>>q;
    ll sum = 0;
    vector<path> ha(q), va(p);
    for(int i = 0;i<p;i++) {
        cin >> va[i].u >> va[i].v >> va[i].w;
        sum += 1ll * va[i].w * n;
    }
    for(int i = 0;i<q;i++) {
        cin >> ha[i].u >> ha[i].v >> ha[i].w;
        sum += 1ll * ha[i].w * m;
    }
    sort(ALL(ha), cmp);
    sort(ALL(va), cmp);
    for(int i = 1;i<N;i++)
        P[i] = F[i] = i;
    int hi = 0, vi = 0, hcnt = 0, vcnt = 0;
    ll ans = 0;
    while(hi < q || vi < p){
        if(vi == p || (hi < q && ha[hi].w < va[vi].w)) {
            if(merge(P, ha[hi].u, ha[hi].v)) {
                ans += 1ll * ha[hi].w * (m - vcnt);
                hcnt++;
            }
            ++hi;
        } else {
            if(merge(F, va[vi].u, va[vi].v)) {
                ans += 1ll * va[vi].w * (n - hcnt);
                vcnt++;
            }
            ++vi;
        }
    }
    cout<<sum - ans<<endl;
    return 0;
}
