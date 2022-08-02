/*
 * Author: Andy Zhu
 * @date    2022-08-02 13:38:39
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

struct segtree {
    int st[N << 2], lazy[N << 2];
    void push_up(int rt) {
        st[rt] = st[lc] + st[rc];
    }
    void push_down(int rt, int l, int r, int mid) {
        if(~lazy[rt]) {
            st[lc] = (mid - l + 1) * lazy[rt];
            st[rc] = (r - mid) * lazy[rt];
            lazy[lc] = lazy[rc] = lazy[rt];
            lazy[rt] = -1;
        }
    } 
    void update(int rt, int l, int r, int x, int y, int val) {
        if(l == x && y == r) {
            st[rt] = val * (r - l + 1);
            lazy[rt] = val;
            return;
        }
        int mid = l + r >> 1;
        push_down(rt, l, r, mid);
        if(y <= mid) update(lc, l, mid, x, y, val);
        else if(x > mid) update(rc, mid + 1, r, x, y, val);
        else update(lc, l, mid, x, mid, val), update(rc, mid + 1, r, mid + 1, y, val);
        push_up(rt);
    }
    int query(int rt, int l, int r, int x, int y) {
        if(l == x && y == r) return st[rt];
        int mid = l + r >> 1;
        push_down(rt, l, r, mid);
        if(y <= mid) return query(lc, l, mid, x, y);
        else if(x > mid) return query(rc, mid + 1, r, x, y);
        else return query(lc, l, mid, x, mid) + query(rc, mid + 1, r, mid + 1, y);
    }
    void clear(int n) {
        update(1, 1, n, 1, n, 0);
    }
} A, AB;

int n, q, f[N][25];
vi e[N];

int fa[N], top[N], hson[N], sz[N], dfn[N], dep[N], tot;

void dfs1(int u = 1, int ff = 0) {
    fa[u] = ff;
    sz[u] = 1;
    dep[u] = dep[ff] + 1;
    f[u][0] = ff;
    for(int i = 1;i<=20;++i) {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }
    for(int v : e[u]) if(ff != v) {
        dfs1(v, u);
        sz[u] += sz[v];
        if(sz[hson[u]] < sz[v]) hson[u] = v;
    }
}

void dfs2(int u = 1, int ff = 0, int tp = 1) {
    dfn[u] = ++tot;
    top[u] = tp;
    if(hson[u]) dfs2(hson[u], u, tp);
    for(int v : e[u]) if(v != ff && v != hson[u]) {
        dfs2(v, u, v);
    }
}

void update(segtree& st, int x) {
    while(x) {
        st.update(1, 1, n, dfn[top[x]], dfn[x], 1);
        x = fa[top[x]];
    }
}

void init() {
    memset(A.lazy, -1, sizeof A.lazy);
    memset(AB.lazy, -1, sizeof AB.lazy);
    memset(A.st, 0, sizeof A.st);
    memset(AB.st, 0, sizeof AB.st);
    memset(f, 0, sizeof f);
    memset(fa, 0, sizeof fa);
    memset(top, 0, sizeof top);
    memset(hson, 0, sizeof hson);
    memset(sz, 0, sizeof sz);
    memset(dfn, 0, sizeof dfn);
    memset(dep, 0, sizeof dep);
    tot = 0;
    for(int i = 0;i<N;++i) e[i].clear();
}

inline void solve() {
    init();
    read(n), read(q);
    for(int i = 2;i<=n;++i) {
        int x = read();
        e[i].pb(x);
        e[x].pb(i);
    }
    dfs1();
    dfs2();
    while(q--) {
        A.clear(n);
        AB.clear(n);
        int a = read(), b = read(), c = read();
        for(int i = 1;i<=a;++i) {
            int x = read();
            update(A, x);
        }
        for(int i = 1;i<=b;++i) {
            int x = read();
            if(A.query(1, 1, n, dfn[x], dfn[x])) {
                update(AB, x);
                continue;
            }
            for(int j = 20;~j;--j) {
                if(f[x][j] && !A.query(1, 1, n, dfn[f[x][j]], dfn[f[x][j]])) x = f[x][j];
            }
            x = fa[x];
            update(AB, x);
        }
        int ans = 0;
        for(int i = 1;i<=c;++i) {
            int x = read();
            ans += AB.query(1, 1, n, dfn[x], dfn[x] + sz[x] - 1);
            AB.update(1, 1, n, dfn[x], dfn[x] + sz[x] - 1, 0);
        }
        print(ans, '\n');
    }
}


//---------------------  end of program  ---------------------


#define doCase 1
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