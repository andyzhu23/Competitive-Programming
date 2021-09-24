/*
 * Author: Andy Zhu
 * @date    2021-09-23 13:25:18
 * @version 1.0.0
 */

//include
#include <bits/stdc++.h>
using namespace std;

// define
#define OJ ONLINE_JUDGE
#define endl "\n"

// pairs
#define fir first
#define sec second
#define mp make_pair

// segment tree
#define lc (rt << 1)
#define rc (rt << 1 | 1)

// STL Data Structures
#define eb emplace_back
#define ef emplace_front
#define pb push_back
#define pf push_front
#define all(v) v.begin(), v.end()
#define ins insert
#define lb lower_bound
#define ub upper_bound

// math
#define log(a, b) log(a) / log(b)

// memset
#define mset(x, y) memset(x, y, sizeof(x))

// random
#define random(a, b) rand() % (b - a + 1) + a

// Data Structure Shorten
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using qi = queue<int>;
using stki = stack<int>;
template <typename T> using vec = vector<T>;
template <typename T> using us = unordered_set<T>;
template <typename T> using os = set<T>;
template <typename T> using ms = multiset<T>;
template <typename T1, typename T2> using um = unordered_map<T1, T2>;
template <typename T1, typename T2> using om = map<T1, T2>;
template <typename T> using pq = priority_queue<T>;
template <typename T> using pqg = priority_queue<T, vec<T>, greater<T> >;
using vi = vec<int>;
using vpii = vec<pii>;
using vll = vec<ll>;
using vpll = vec<pll>;
using vb = vec<bool>;

// loops!
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)

// common variables
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;
const int dir[8][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {-1, 1}, {1, -1}, {-1, -1}, {1, 1}};
struct Edge {int u, v, w;};

// common functions

namespace comfun {
    template <typename T> inline void cmax(T& u, T v) { u = max(u, v); }
    template <typename T> inline void cmin(T& u, T v) { u = min(u, v); }
    template <typename T> inline T lowbit(T x){return x & (- x);}
    template <typename T> inline T gcd(T a, T b){if(a == 0) return b; if(b == 0) return a; return gcd(b, a % b);}
    template <typename T> inline T lcm(T a, T b){return a / gcd(a, b) * b;}
    template <typename T1, typename T2> inline T1 fast_pow(T1 a, T2 b)
    {if(b == 1) return a; if(b == 0) return 1; T1 tmp = fast_pow(a, b >> 1); if(b & 1) return tmp * tmp * a; else return tmp * tmp;}
    template <typename T1, typename T2, typename T3> inline T1 fast_pow(T1 a, T2 b, T3 m)
    {if(b == 1) return a % m; if(b == 0) return 1; T1 tmp = fast_pow(a, b >> 1, m); if(b & 1) return tmp * tmp % m * a % m; else return tmp * tmp % m;}
    template <typename T> inline bool is_prime(T x){if(x == 1) return false; for(T i = 2; i * i <= x;i++) if(x % i == 0) return false; return true;}
}
namespace debug {
    template <typename T> inline void debugArray(T *arr,int sz){cout<<"[";for(int i=0;i<sz;i++){cout<<arr[i]<<", "; } cout<<"]\n";}
    template <typename T> inline void printArray(T *arr,int sz){for(int i=0;i<sz;i++){cout<<arr[i]<<" "; } cout<<"\n";}
}
namespace fast_io {
    void read(int &number) {
        bool negative = false; int c; number = 0; c = getchar();
        if (c == '-') {negative = true;c = getchar();}
        for (; (c > 47 && c < 58); c = getchar())number = number *10 + c - 48;
        if (negative) number *= -1;
    }
}

// using namespaces
using namespace comfun;
using namespace debug;
using namespace fast_io;

//------------------- start of initialize -------------------
// initialize for all cases
inline void init1(){

}

// initialize for the current subcase
inline void init2(){

}

//-------------------  end of initialize  -------------------

//--------------------- start of program ---------------------

const int N = 11;
const int M = 1e5 + 10;
const int Base = 1e9 + 7;
us<ll> hashs, vis;
vi a[N];
int n, m, b[M][N];

struct cmp {
    bool operator() (const vi& x, const vi& y) {
        ll cnt1 = 0, cnt2 = 0;
        for(int i = 1;i<=n;++i)
            cnt1 += a[i][x[i - 1]];
        for(int i = 1;i<=n;++i)
            cnt2 += a[i][y[i - 1]];
        return cnt1 < cnt2;
    }
};

priority_queue<vi, vec<vi>, cmp> heap;

ll hash_vec(vi& x) {
    ll ans = 0;
    for(auto y : x) {
        ans = (ans * Base % MOD + y) % MOD;
    }
    return ans;
}

inline void solve(){
    cin>>n;
    for(int i = 1;i<=n;++i) {
        int k; cin>>k;
        for(int j = 1;j<=k;++j) {
            int x; cin>>x;
            a[i].pb(x);
        }
    }
    cin>>m;
    for(int i = 1;i<=m;++i) {
        ll val = 0;
        for(int j = 1;j<=n;++j) {
            cin>>b[i][j];
            val = (val * Base % MOD + b[i][j] - 1) % MOD;
        }
        hashs.ins(val);
    }
    vi o;
    for(int i = 1;i<=n;++i) o.pb(a[i].size() - 1);
    heap.push(o);
    while(!heap.empty()) {
        vi cur = heap.top(); heap.pop();
        ll h = hash_vec(cur);
        if(vis.count(h)) continue;
        vis.ins(h);
        if(hashs.count(h)) {
            for(int i = 0;i<n;++i) {
                cur[i]--;
                if(cur[i] == -1) {
                    cur[i]++;
                    continue;
                }
                heap.push(cur);
                cur[i]++;
            }
        } else {
            for(auto& x : cur) cout<<++x<<' ';
            return;
        }
    }
}


//---------------------  end of program  ---------------------


#define doCase 0
#define config !OJ
#define kickstart 0
#define unsync 1

inline void setIO() {
#if config
    // configuration here
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
#endif
#if unsync
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
}

int main(){
    setIO();
    init1();
    srand(time(0));
#if doCase
    int t; cin>>t;
    for(int i = 1;i<=t;i++) {
        if(kickstart) cout<<"Case #"<< i<<": ";
        init2();
        solve();
    }
#else
    solve();
#endif
    string jack = "Jack is always within you";
    return 0;
}


/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/