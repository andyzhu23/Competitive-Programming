/*
 * Author: Andy Zhu
 * @date    2022-12-03 19:15:53
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
// template <typename T>
// using ordered_multiset = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

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
    template <typename T> inline T gcd(T a, T b){if(b == 0) return a; return gcd(b, a % b);}
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
    template<typename T> T read(T& x) {x = 0; int f = 0; char ch = getchar();while (!isdigit(ch)) f |= ch == '-', ch = getchar();while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();x = f ? -x : x; return x;}
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
const int MX = 1e9;
int n, x, a[N];

struct node {
    int l, r, val;
};

struct segtree {
    node st[5000000];
    int tot = 0, root;
    void update(int& rt, int l, int r, int pos, int val) {
        if(!rt) {
            rt = ++tot;
            st[rt].l = st[rt].r = st[rt].val = 0;
        }
        if(l == r) {
            st[rt].val = val;
            return;
        }
        int mid = l + r >> 1;
        if(pos <= mid) update(st[rt].l, l, mid, pos, val);
        else update(st[rt].r, mid + 1, r, pos, val);
        st[rt].val = max(st[st[rt].l].val, st[st[rt].r].val);
    }
    int query(int& rt, int l, int r, int x, int y) {
        if(!rt) return 0;
        if(l == x && y == r) return st[rt].val;
        int mid = l + r >> 1;
        if(y <= mid) return query(st[rt].l, l, mid, x, y);
        else if(x > mid) return query(st[rt].r, mid + 1, r, x, y);
        else return max(query(st[rt].l, l, mid, x, mid), query(st[rt].r, mid + 1, r, mid + 1, y));
    }
} st1, st2, st3;

int dp1[N], dp2[N];

um<int, multiset<int> > mp;

inline void solve(){
    read(n), read(x);
    for(int i = 1;i<=n;++i) read(a[i]);
    for(int i = 1;i<=n;++i) {
        dp1[i] = 1;
        if(a[i] != 1) dp1[i] += st1.query(st1.root, 1, MX, 1, a[i] - 1);
        st1.update(st1.root, 1, MX, a[i], dp1[i]);
    }
    for(int i = n;i;--i) {
        dp2[i] = 1;
        if(a[i] != MX) dp2[i] += st2.query(st2.root, 1, MX, a[i] + 1, MX);
        st2.update(st2.root, 1, MX, a[i], dp2[i]);
        mp[a[i]].insert(dp2[i]);
        st3.update(st3.root, 1, MX, a[i], dp2[i]);
    }
    int ans = 0;
    for(int i = 1;i<=n;++i) {
        mp[a[i]].erase(mp[a[i]].lb(dp2[i]));
        st3.update(st3.root, 1, MX, a[i], mp[a[i]].empty() ? 0 : *mp[a[i]].rbegin());
        ckmax(ans, dp1[i] + st3.query(st3.root, 1, MX, max(1, a[i] + 1 - x), MX));
    }
    print(ans, '\n');
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
