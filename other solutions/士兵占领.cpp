/*
 * Author: Andy Zhu
 * @date    2022-04-12 19:29:19
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

const int N = 105;
const int NN = N * N << 1;
int m, n, k, S, T, a[N], b[N], c[N][N], head[N << 1], tot = 1;
struct edge {int u, v, f, nxt;} e[NN];

void add(int u, int v, int f) {
    e[++tot] = {u, v, f, head[u]};
    head[u] = tot;
    e[++tot] = {v, u, 0, head[v]};
    head[v] = tot;
}

bool check() {
    bool flag = 1;
    for(int i = 1;i<=m;++i) {
        int tmp = 0;
        for(int j = 1;j<=n;++j) tmp += c[i][j] ^ 1;
        flag &= a[i] <= tmp;
    }
    for(int i = 1;i<=n;++i) {
        int tmp = 0;
        for(int j = 1;j<=m;++j) tmp += c[j][i] ^ 1;
        flag &= b[i] <= tmp;
    }
    return flag;
}

int dist[N << 1], cur[N << 1];
bitset<N * 2> inq;

bool bfs() {
    queue<int> q;
    memset(dist, 0x3f, sizeof(dist));
    inq.reset();
    dist[S] = 0;
    q.push(S);
    for(int i = 1;i<=T;++i) cur[i] = head[i];
    while(!q.empty()) {
        int u = q.front(); q.pop();
        inq[u] = 0;
        for(int i = head[u];i;i=e[i].nxt) {
            if(e[i].f && dist[e[i].v] > dist[u] + 1) {
                dist[e[i].v] = dist[u] + 1;
                if(!inq[e[i].v]) {
                    inq[e[i].v] = 1;
                    q.push(e[i].v);
                }
            }
        }
    }
    return dist[T] != INF;
}

int dfs(int u = S, int f = INF) {
    if(u == T) return f;
    inq[u] = 1;
    int ret = 0;
    for(int& i = cur[u];i;i=e[i].nxt) {
        if(!inq[e[i].v] && e[i].f && dist[e[i].v] == dist[u] + 1) {
            int tmp = dfs(e[i].v, min(f, e[i].f));
            f -= tmp;
            e[i].f -= tmp;
            e[i ^ 1].f += tmp;
            ret += tmp;
            if(f == 0) break;
        }
    }
    inq[u] = 0;
    if(ret == 0) dist[u] = 0;
    return ret;
}

int dinic() {
    int ans = 0;
    while(bfs()) ans += dfs();
    return ans;
}

inline void solve(){
    read(m), read(n), read(k);
    S = m + n + 1;
    T = m + n + 2;
    for(int i = 1;i<=m;++i) read(a[i]), add(S, i, a[i]);
    for(int i = 1;i<=n;++i) read(b[i]), add(i + m, T, b[i]);
    while(k--) {
        int x = read(), y = read();
        c[x][y] = 1;
    }
    if(!check()) {
        puts("JIONG!");
        return;
    }
    for(int i = 1;i<=m;++i) {
        for(int j = 1;j<=n;++j) if(!c[i][j]) {
            add(i, j + m, 2);
        }
    }
    int ans = dinic();
    for(int i = 2;i<=(m + n) * 2;i+=2) ans += e[i].f;
    print(ans, '\n');
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
