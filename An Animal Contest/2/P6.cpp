/*
 * Author: Andy Zhu
 * @date    2022-02-06 16:17:17
 * @version 1.0.0
 */

// optimize
#pragma GCC optimize(2)

//include
#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// template <typename T>
// using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// define
#define OJ ONLINE_JUDGE
#define endl "\n"
#define rint registered int

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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define random(a, b) rng() % (b - a + 1) + a

// Data Structure Shorten
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using db = double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using qi = queue<int>;
using stki = stack<int>;
template <typename T> using vec = vector<T>;
template <typename T> using us = unordered_set<T>;
template <typename T> using os = set<T>;
template <typename T> using ms = multiset<T>;
template <typename T1, typename T2> using um = unordered_map<T1, T2>;
template <typename T1, typename T2> using om = map<T1, T2>;
template <typename T> using pq = priority_queue<T>; 
template <typename T> using pqg = priority_queue<T, vector<T>, greater<T> >;
using vi = vector<int>;
using vpii = vector<pair<int, int> >;
using vll = vector<long long>;
using vpll = vector<pair<long long, long long> >;
using vb = vector<bool>;

// loops!
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)

// common variables
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const int dir[8][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {-1, 1}, {1, -1}, {-1, -1}, {1, 1}};
struct Edge {int u, v, w;};
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

// common functions

namespace comfun {
    template <typename T> inline void ckmax(T& u, T v) { u = max(u, v); }
    template <typename T> inline void ckmin(T& u, T v) { u = min(u, v); }
    template <typename T> inline T lowbit(T x){return x & (- x);}
    template <typename T> inline T gcd(T a, T b){if(a == 0) return b; if(b == 0) return a; return gcd(b, a % b);}
    template <typename T> inline T lcm(T a, T b){return a / gcd(a, b) * b;}
    template <typename T1, typename T2> inline T1 fp(T1 a, T2 b) {T1 c = 1;while(b) {if(b & 1) c *= a;b >>= 1;a = a * a;}return c;}
    template <typename T1, typename T2, typename T3> inline T1 fp(T1 a, T2 b, T3 mod) 
    {T1 c = 1;while(b) {if(b & 1) c = c * a % mod;b >>= 1;a = a * a % mod;}return c;}
    template <typename T> inline bool is_prime(T x){if(x == 1) return false; for(T i = 2; i * i <= x;i++) if(x % i == 0) return false; return true;}
}
namespace debug {
    template <typename T> inline void debugArray(T *arr,int sz){cout<<"[";for(int i=0;i<sz;i++){cout<<arr[i]<<", "; } cout<<"]\n";}
    template <typename T> inline void printArray(T *arr,int sz){for(int i=0;i<sz;i++){cout<<arr[i]<<" "; } cout<<"\n";}
}
namespace fast_io {
    int read() {
        int x = 0, f = 0; char ch = getchar();
        while (!isdigit(ch)) f |= ch == '-', ch = getchar();
        while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
            return f ? -x : x;
    }
    long long readLL() {
        long long x = 0, f = 0; char ch = getchar();
        while (!isdigit(ch)) f |= ch == '-', ch = getchar();
        while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
            return f ? -x : x;
    }
    void read(int& x) {x = read();}
    void read(long long& x) {x = readLL();}
    template<typename T> void print(T x) {
        if (x < 0) putchar('-'), x = -x;
        if (x >= 10) print(x / 10);
            putchar(x % 10 + '0');
    }
    template<typename T> void print(T x, char let) {
        print(x), putchar(let);
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

const int N = 2e5 + 10;
int n, q, a[N];
vector<int> e[N];

struct fenwick {
    ll c[N], d[N];
    void update(int pos, ll val) {
        for(int i = pos;i<=n;i+=lowbit(i)) {
            c[i] += val;
            d[i] += (pos - 1) * val;
        }
    }
    void update(int l, int r, int val) {
        update(l, val);
        update(r + 1, -val);
    }
    ll query(int a) {
        ll ans = 0;
        for(int i = a;i;i-=lowbit(i)) {
            ans += a * c[i] - d[i];
        }
        return ans;
    }
    ll query(int a, int b) {
        return query(b) - query(a - 1);
    }
};

struct HLD {
    fenwick fen;
    int hson[N], dfn[N], rnk[N], dep[N], siz[N], fa[N], top[N], tot;
    void dfs1(int u = 1, int f = 0) {
        dep[u] = dep[f] + 1;
        fa[u] = f;
        siz[u] = 1;
        for(int v : e[u]) {
            if(v == f) continue;
            dfs1(v, u);
            siz[u] += siz[v];
            if(siz[v] >= siz[hson[u]]) hson[u] = v;
        }
    }
    void dfs2(int u = 1, int f = 0, int tp = 1) {
        dfn[u] = ++tot;
        rnk[tot] = u;
        top[u] = tp;
        if(hson[u] == 0) return;
        dfs2(hson[u], u, tp);
        for(int v : e[u]) {
            if(v == f || v == hson[u]) continue;
            dfs2(v, u, v);
        }
    }
    void update(int u, int v, int val) {
        while(top[u] != top[v]) {
            if(dep[top[u]] < dep[top[v]]) swap(u, v);
            fen.update(dfn[top[u]], dfn[u], val);
            u = fa[top[u]];
        }
        fen.update(min(dfn[u], dfn[v]), max(dfn[u], dfn[v]), val);
    }
    ll query(int u, int v) {
        ll ans = 0;
        while(top[u] != top[v]) {
            if(dep[top[u]] < dep[top[v]]) swap(u, v);
            ans += fen.query(dfn[top[u]], dfn[u]);
            u = fa[top[u]];
        }
        ans += fen.query(min(dfn[u], dfn[v]), max(dfn[u], dfn[v]));
        return ans;
    }
} hld;

inline void solve(){
    read(n), read(q);
    for(int i = 1;i<n;++i) {
        int u = read(), v = read();
        e[u].pb(v);
        e[v].pb(u);
    }
    hld.dfs1();
    hld.dfs2();
    while(q--) {
        int x = read();
        ll tot = 0;
        for(int i = 1;i<=x;++i) {
            read(a[i]);
            tot += hld.dep[a[i]] - 1;
            hld.update(1, a[i], 1);
        }
        ll mx = 0;
        for(int i = 1;i<=x;++i) {
            ckmax(mx, hld.query(1, a[i]) - hld.query(1, 1));
        }
        for(int i = 1;i<=x;++i) hld.update(1, a[i], -1);
        print(tot - mx, '\n');
    }
}


//---------------------  end of program  ---------------------


#define doCase 0
#define config LOCAL
#define kickstart 0
#define unsync 0

inline void setIO() {
#if config
    // configuration here
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
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
    int t; t = read();
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
