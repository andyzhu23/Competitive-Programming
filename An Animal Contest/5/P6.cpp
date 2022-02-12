/*
 * Author: Andy Zhu
 * @date    2022-02-11 07:42:47
 * @version 1.0.0
 */

// optimize
#pragma GCC optimize(2)
#pragma GCC optimize(3)

//include
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <ctype.h>
// #include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// template <typename T>
// using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// define
// #define OJ ONLINE_JUDGE
// #define endl "\n"
// #define rint registered int

// pairs
#define fir first
#define sec second
// #define mp make_pair

// segment tree
// #define lc (rt << 1)
// #define rc (rt << 1 | 1)

// STL Data Structures
#define eb emplace_back
// #define ef emplace_front
// #define pb push_back
// #define pf push_front
#define all(v) v.begin(), v.end()
// #define ins insert
// #define lb lower_bound
// #define ub upper_bound

// math
// #define log(a, b) log(a) / log(b)

// memset
// #define mset(x, y) memset(x, y, sizeof(x))

// random
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// #define random(a, b) rng() % (b - a + 1) + a

// Data Structure Shorten
using ll = long long;
// using ull = unsigned long long;
// using ld = long double;
// using db = double;
using pii = pair<int, int>;
// using pll = pair<long long, long long>;
// using qi = queue<int>;
// using stki = stack<int>;
// template <typename T> using vec = vector<T>;
// template <typename T> using us = unordered_set<T>;
// template <typename T> using os = set<T>;
// template <typename T> using ms = multiset<T>;
// template <typename T1, typename T2> using um = unordered_map<T1, T2>;
// template <typename T1, typename T2> using om = map<T1, T2>;
// template <typename T> using pq = priority_queue<T>;
// template <typename T> using pqg = priority_queue<T, vector<T>, greater<T> >;
// using vi = vector<int>;
// using vpii = vector<pair<int, int> >;
// using vll = vector<long long>;
// using vpll = vector<pair<long long, long long> >;
// using vb = vector<bool>;

// loops!
// #define FOR(i, a, b) for(int i = (a); i < (b); ++i)

// common variables
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1e9 + 7;
// const int dir[8][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {-1, 1}, {1, -1}, {-1, -1}, {1, 1}};
// struct Edge {int u, v, w;};
// struct pair_hash {
//     template <class T1, class T2>
//     std::size_t operator() (const std::pair<T1, T2> &pair) const {
//         return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
//     }
// };

// common functions

namespace comfun {
    template <typename T> inline void ckmax(T& u, T v) { u = max(u, v); }
    template <typename T> inline void ckmin(T& u, T v) { u = min(u, v); }
    // template <typename T> inline T lowbit(T x){return x & (- x);}
    // template <typename T> inline T gcd(T a, T b){if(a == 0) return b; if(b == 0) return a; return gcd(b, a % b);}
    // template <typename T> inline T lcm(T a, T b){return a / gcd(a, b) * b;}
    // template <typename T1, typename T2> inline T1 fp(T1 a, T2 b) {T1 c = 1;while(b) {if(b & 1) c *= a;b >>= 1;a = a * a;}return c;}
    // template <typename T1, typename T2, typename T3> inline T1 fp(T1 a, T2 b, T3 mod)
    // {T1 c = 1;while(b) {if(b & 1) c = c * a % mod;b >>= 1;a = a * a % mod;}return c;}
    // template <typename T> inline bool is_prime(T x){if(x == 1) return false; for(T i = 2; i * i <= x;i++) if(x % i == 0) return false; return true;}
}
// namespace debug {
//     template <typename T> inline void debugArray(T *arr,int sz){cout<<"[";for(int i=0;i<sz;i++){cout<<arr[i]<<", "; } cout<<"]\n";}
//     template <typename T> inline void printArray(T *arr,int sz){for(int i=0;i<sz;i++){cout<<arr[i]<<" "; } cout<<"\n";}
// }
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
// using namespace debug;
using namespace fast_io;

//------------------- start of initialize -------------------
// // initialize for all cases
// inline void init1(){

// }

// // initialize for the current subcase
// inline void init2(){

// }

//-------------------  end of initialize  -------------------

//--------------------- start of program ---------------------
const int N = 2e5 + 5;
int a[N], n, d, dep[N], f[N][19], root;
vector<int> e[N];

inline void dfs(int u = 1, int fa = 0) {
    dep[u] = dep[fa] + 1;
    f[u][0] = fa;
    for(int i = 1;i<19;++i) f[u][i] = f[f[u][i - 1]][i - 1];
    for(int v : e[u]) if(v != fa) {
        dfs(v, u);
    }
}

inline int LCA(int u, int v) {
    if(dep[u] < dep[v]) swap(u, v);
    for(int i = 18;i>=0;--i) {
        if(dep[f[u][i]] >= dep[v]) u = f[u][i];
        if(u == v) return u;
    }
    for(int i = 18;i>=0;--i) {
        if(f[u][i] != f[v][i]) {
            u = f[u][i];
            v = f[v][i];
        }
    }
    return f[u][0];
}

inline int get(int u, int v) {
    int lca = LCA(u, v);
    return dep[u] + dep[v] - (dep[lca] << 1);
}

int sz[N], mn;
bool vis2[N];

inline void getroot(int u, int fa, int sum) {
    sz[u] = 1;
    int mx = 0;
    for(int v : e[u]) if(!vis2[v] && v != fa) {
        getroot(v, u, sum);
        ckmax(mx, sz[v]);
        sz[u] += sz[v];
    }
    ckmax(mx, sum - mx);
    if(mx < mn) mn = mx, root = u;
}

int dist2[N], fa[N], cur;

vector<pii> reach[N];

inline void bfs(int x, int fa) {
    queue<pii> q;
    q.push({x, fa});
    dist2[x] = 0;
    while(!q.empty()) {
        pii u = q.front(); q.pop();
        for(int v : e[u.fir]) if(!vis2[v] && v != u.sec) {
            dist2[v] = dist2[u.fir] + 1;
            reach[cur].eb((pii){v, dist2[v]});
            if(dist2[v] < d) q.push({v, u.fir});
        }
    }
}

int siz[N];

inline void dfs2(int u, int all) {
    vis2[u] = 1;
    cur = u;
    dist2[u] = 0;
    bfs(u, 0);
    siz[u] = reach[u].size();
    sort(all(reach[u]), [&](pii& a, pii& b) {
        return a.sec > b.sec;
    });
    for(int v : e[u]) if(!vis2[v]) {
        int s = sz[v] > sz[u] ? all - sz[u] : sz[v];
        root = 0, mn = INF;
        getroot(v, u, s);
        if(!fa[root]) fa[root] = u;
        dfs2(root, s);
    }
}
ll dist[N];
bool vis[N];
struct cmp {
    inline bool operator() (const int& a, const int& b) {
        return dist[a] > dist[b];
    }
};

priority_queue<int, vector<int>, cmp> heap;

inline void solve(){
    read(n), read(d);
    for(int i = 1;i<=n;++i) read(a[i]);
    for(int i = 1;i<n;++i) {
        int u = read(), v = read();
        e[u].eb(v);
        e[v].eb(u);
    }
    dfs();
    mn = INF;
    getroot(n, 0, n);
    dfs2(root, n);
    memset(dist, 0x3f, sizeof(dist));
    heap.push(1);
    dist[1] = 0;
    while(!heap.empty()) {
        int u = heap.top(); heap.pop();
        vis[u] = 1;
        while(siz[u]) {
            int v = reach[u][siz[u] - 1].fir; --siz[u];
            if(vis[v]) continue;
            vis[v] = 1;
            ckmin(dist[v], dist[u] + a[v]);
            heap.push(v);
        }
        int tot, ou = u;
        while(fa[u]) {
            u = fa[u];
            tot = d - get(u, ou);
            if(tot < 0) continue;
            if(!vis[u]) {
                vis[u] = 1;
                ckmin(dist[u], a[u] + dist[ou]);
                heap.push(u);
            }
            while(siz[u] && reach[u][siz[u] - 1].sec <= tot) {
                if(vis[reach[u][siz[u] - 1].fir]) {
                    --siz[u];
                    continue;
                }
                ckmin(dist[reach[u][siz[u] - 1].fir], dist[ou] + a[reach[u][siz[u] - 1].fir]);
                vis[reach[u][siz[u] - 1].fir] = 1;
                heap.push(reach[u][siz[u] - 1].fir);
                --siz[u];
            }
        }
    }
    for(int i = 1;i<=n;++i) print(dist[i], i == n ? '\n' : ' ');
}


//---------------------  end of program  ---------------------


// #define doCase 0
#define config LOCAL
// #define kickstart 0
// #define unsync 0

inline void setIO() {
#if config
    // configuration here
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
// #if unsync
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
// #endif
}

int main(){
    setIO();
    // init1();
    // srand(time(0));
// #if doCase
//     int t; t = read();
//     for(int i = 1;i<=t;i++) {
//         if(kickstart) cout<<"Case #"<< i<<": ";
//         init2();
//         solve();
//     }
// #else
    solve();
// #endif
//     string jack = "Jack is always within you";
    return 0;
}


/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/
