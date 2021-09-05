/*
 * Author: Andy Zhu
 * @date    2021-09-05 08:19:31
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
const int MOD = 1e9 + 7;
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
#define int long long
int n, q;
const int N = 2e5 + 10;
int a[N];
struct seg {
    struct node {
        int cnt, l, r;
        int lval, rval;
    } st[N << 2];

    void push_up(int rt, int l, int r, int mid) {
        st[rt].cnt = st[lc].cnt + st[rc].cnt;
        if(st[lc].rval <= st[rc].lval) {
            st[rt].cnt += st[lc].r * st[rc].l;
            if(st[rc].l == r - mid) {
                st[rt].r = st[rc].l + st[lc].r;
            } else {
                st[rt].r = st[rc].r;
            }
            if(st[lc].r == mid - l + 1) {
                st[rt].l = st[lc].r + st[rc].l;
            } else {
                st[rt].l = st[lc].l;
            }
        } else {
            st[rt].r = st[rc].r;
            st[rt].l = st[lc].l;
        }
        st[rt].lval = st[lc].lval;
        st[rt].rval = st[rc].rval;
    }
    void build(int rt, int l, int r) {
        if(l == r) {
            st[rt].lval = st[rt].rval = a[l];
            st[rt].cnt = st[rt].l = st[rt].r = 1;
            return;
        }
        int mid = (l + r) >> 1;
        build(lc, l, mid);
        build(rc, mid + 1, r);
        push_up(rt, l, r, mid);
    }

    void update(int rt, int l, int r, int pos, int val) {
        if(l == r) {
            st[rt].lval = st[rt].rval = val;
            return;
        }
        int mid = (l + r) >> 1;
        if(pos <= mid) update(lc, l, mid, pos, val);
        else update(rc, mid + 1, r, pos, val);
        push_up(rt, l, r, mid);
    }

    node query(int rt, int l, int r, int x, int y) {
        if(l == x && y == r) {
            return st[rt];
        }
        int mid = (l + r) >> 1;
        if(y <= mid) return query(lc, l, mid, x, y);
        else if(x > mid) return query(rc, mid + 1, r, x, y);
        else {
            node a = query(lc, l, mid, x, mid);
            node b = query(rc, mid + 1, r, mid + 1, y);
            node ans;
            ans.cnt = a.cnt + b.cnt;
            if(a.rval <= b.lval) {
                ans.cnt += a.r * b.l;
                if(b.l == r - mid) {
                    ans.r = b.l + a.r;
                } else {
                    ans.r = b.r;
                }
                if(a.r == mid - l + 1) {
                    ans.l = a.r + b.l;
                } else {
                    ans.l = a.l;
                }
            } else {
                ans.r = b.r;
                ans.l = a.l;
            }
            ans.lval = a.lval;
            ans.rval = b.rval;
            return ans;
        }
    }

} st;

inline void solve(){
    cin>>n>>q;
    for(int i = 1;i<=n;i++) cin>>a[i];
    st.build(1, 1, n);
    while(q--) {
        int opt, x, y;
        cin>>opt>>x>>y;
        if(opt == 1) {
            st.update(1, 1, n, x, y);
        } else {
            cout<<st.query(1, 1, n, x, y).cnt<<'\n';
        }
    }
}


//---------------------  end of program  ---------------------


#define doCase 0
#define config 0
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

signed main(){
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