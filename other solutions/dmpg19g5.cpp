/*
 * Author: Andy Zhu
 * @date    2022-08-14 17:21:46
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

// pairs
#define fir first
#define sec second

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

// random
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define random(a, b) rng() % (b - a + 1) + a

// Data Structure Shorten
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
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

// common functions

namespace comfun {
    template <typename T1, typename T2> inline void ckmax(T1& u, T2 v) { u = max(u, v); }
    template <typename T1, typename T2> inline void ckmin(T1& u, T2 v) { u = min(u, v); }
    template <typename T> inline T lowbit(T x){return x & (- x);}
    template <typename T> inline T gcd(T a, T b){if(a == 0) return b; if(b == 0) return a; return gcd(b, a % b);}
    template <typename T> inline T lcm(T a, T b){return a / gcd(a, b) * b;}
    template <typename T1, typename T2> inline T1 fp(T1 a, T2 b) {T1 c = 1;while(b) {if(b & 1) c *= a;b >>= 1;a = a * a;}return c;}
    template <typename T1, typename T2, typename T3> inline T1 fp(T1 a, T2 b, T3 mod) 
    {T1 c = 1;while(b) {if(b & 1) c = c * a % mod;b >>= 1;a = a * a % mod;}return c;}
    template <typename T> inline bool is_prime(T x){if(x == 1) return false; for(T i = 2; i * i <= x;i++) if(x % i == 0) return false; return true;}
}

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

namespace fast_io {
    int read() {int x = 0, f = 0; char ch = getchar();while (!isdigit(ch)) f |= ch == '-', ch = getchar();while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();return f ? -x : x;}
    long long readLL() {long long x = 0, f = 0; char ch = getchar();while (!isdigit(ch)) f |= ch == '-', ch = getchar();while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();return f ? -x : x;}
    void read(int& x) {x = read();}
    void read(long long& x) {x = readLL();}
    template<typename T> void print(T x) {if (x < 0) putchar('-'), x = -x;if (x >= 10) print(x / 10);putchar(x % 10 + '0');}
    template<typename T> void print(T x, char let) {print(x), putchar(let);}
}

// using namespaces
using namespace comfun;
using namespace fast_io;

// common variables
const int inf = 0x3f3f3f3f;
const long long llinf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const int dir[8][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {-1, 1}, {1, -1}, {-1, -1}, {1, 1}};
const unordered_set<int> vowel = {'a', 'e', 'i', 'o', 'u'};

//------------------- start of initialize --------------------
// initialize for all cases
inline void init1(){

}

//-------------------  end of initialize  --------------------

//--------------------- start of program ---------------------

const int N = 2e5 + 5;
const int K = 1e6 + 5;

vpii e[N];
int n, k, sz[N], rt = 1, d[K], f[N][22], dep[N];
ll dist[N], tot, lazy[N];
bitset<N> vis;

void calc(int u = 1, int fa = 0) {
    dep[u] = dep[fa] + 1;
    f[u][0] = fa;
    for(int i = 1;i<=20;++i) f[u][i] = f[f[u][i - 1]][i - 1];
    for(auto[v, w] : e[u]) if(v != fa) {
        calc(v, u);
    }
}

int LCA(int u, int v) {
    if(dep[u] < dep[v]) swap(u, v);
    for(int i = 20;~i;--i) {
        if(dep[f[u][i]] >= dep[v]) u = f[u][i];
        if(u == v) return u;
    }
    for(int i = 20;~i;--i) {
        if(f[u][i] != f[v][i]) {
            u = f[u][i];
            v = f[v][i];
        }
    }
    return f[u][0];
}

void add(int u, int v, int val) {
    lazy[u] += val;
    lazy[v] += val;
    int lca = LCA(u, v);
    lazy[lca] -= val;
    lazy[f[lca][0]] -= val;
}

void get(int u = rt, int fa = 0, ll d = 0) {
    sz[u] = 1;
    dist[u] = d;
    for(auto[v, w] : e[u]) if(v != fa && !vis[v]) {
        get(v, u, d + w);
        sz[u] += sz[v];
    }
}

void root(int u = rt, int fa = 0, int tot = sz[rt]) {
    int mx = tot - sz[u];
    for(auto[v, w] : e[u]) if(v != fa && !vis[v]) {
        root(v, u, tot);
        ckmax(mx, sz[v]);
    }
    if(mx <= tot / 2) rt = u;
}

deque<int> q;

void gather(int u = 1, int fa = 0) {
    q.pb(u);
    for(auto[v, w] : e[u]) if(v != fa && !vis[v]) {
        gather(v, u);
    }
}

void dfs(int u = rt) {
    get(u);
    d[0] = 1;
    for(auto[v, w] : e[u]) if(!vis[v]) {
        gather(v, u);
        for(auto x : q) if(dist[x] <= k) {
            add(x, u, d[k - dist[x]]);
            tot += d[k - dist[x]];
        }
        while(!q.empty()) {
            int x = q.front(); q.pop_front();
            if(dist[x] <= k) ++d[dist[x]];
        }
    }
    for(auto[v, w] : e[u]) if(!vis[v]) {
        gather(v, u);
        while(!q.empty()) {
            int x = q.front(); q.pop_front();
            if(dist[x] <= k) --d[dist[x]];
        }
    }
    reverse(all(e[u]));
    d[0] = 0;
    for(auto[v, w] : e[u]) if(!vis[v]) {
        gather(v, u);
        for(auto x : q) if(dist[x] <= k) {
            add(x, v, d[k - dist[x]]);
        }
        while(!q.empty()) {
            int x = q.front(); q.pop_front();
            if(dist[x] <= k) ++d[dist[x]];
        }
    }
    for(auto[v, w] : e[u]) if(!vis[v]) {
        gather(v, u);
        while(!q.empty()) {
            int x = q.front(); q.pop_front();
            if(dist[x] <= k) --d[dist[x]];
        }
    }
    vis[u] = 1;
    for(auto[v, w] : e[u]) if(!vis[v]) {
        get(v);
        root(v, 0, sz[v]);
        dfs();
    }
    vis[u] = 0;
}

void getAns(int u = 1, int fa = 0) {
    for(auto[v, w] : e[u]) if(v != fa) {
        getAns(v, u);
        lazy[u] += lazy[v];
    }
}

inline void solve() {
    read(n), read(k);
    for(int i = 1;i<n;++i) {
        int u = read(), v = read(), w = read();
        e[u].pb({v, w});
        e[v].pb({u, w});
    }
    calc();
    get();
    root();
    dfs();
    getAns();
    for(int i = 1;i<=n;++i) {
        ll GCD = gcd(tot, lazy[i]);
        if(tot == 0) {
            puts("0 / 1");
            continue;
        }
        printf("%lld / %lld\n", lazy[i] / GCD, tot / GCD);
    }
}


//---------------------  end of program  ---------------------


#define doCase 0
#define config LOCAL
// #define kickstart
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

signed main(){
    setIO();
    init1();
    srand(time(0));
#if doCase
    int t; t = read();
    for(int i = 1;i<=t;i++) {
#ifdef kickstart 
        printf("Case #%d: ", i);
#endif
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
