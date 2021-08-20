/*
 * Author: Andy Zhu
 * @date    2021-08-20 11:18:04
 * @version 1.0.0
 */

//include
#include <bits/stdc++.h>
using namespace std;

// define
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define fir first
#define sec second
#define lc (rt << 1)
#define rc (rt << 1 | 1)
#define eb emplace_back
#define ef emplace_front
#define pb push_back
#define pf push_front
#define mp make_pair
#define random(a, b) rand() % (b - a + 1) + a
#define log(a, b) log(a) / log(b)
#define ALL(v) v.begin(), v.end()
#define clr(x) memset(x, 0, sizeof(x))
#define setINF(x) memset(x, 63, sizeof(x))
#define setNINF(x) memset(x, -63, sizeof(x))

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

template <typename T> inline void debugArray(T *arr,int sz){cout<<"[";for(int i=0;i<sz;i++){cout<<arr[i]<<", "; } cout<<"]\n";}
template <typename T> inline void printArray(T *arr,int sz){for(int i=0;i<sz;i++){cout<<arr[i]<<" "; } cout<<"\n";}


//------------------- start of initialize -------------------
// initialize for all cases
inline void init1(){

}

// initialize for the current subcase
inline void init2(){

}

//-------------------  end of initialize  -------------------

//--------------------- start of program ---------------------

const int N = 3e5 + 10;
int k;

template <typename T1, typename T2> 
struct seg {
    // make sure it is N << 2
    T1 st[N << 2], lazy[N << 2];
    int lson[N << 2], rson[N << 2], tot, root;
    void push_up(int rt) {
        st[rt] = max(st[lson[rt]], st[rson[rt]]);
    }
    void push_down(int rt) {
        if(lazy[rt] == mp(0, 0)) return;
        if(lson[rt] == 0) lson[rt] = ++tot;
        if(rson[rt] == 0) rson[rt] = ++tot;
        st[lson[rt]] = lazy[rt];
        st[rson[rt]] = lazy[rt];
        lazy[lson[rt]] = lazy[rt];
        lazy[rson[rt]] = lazy[rt];
        lazy[rt] = mp(0, 0);
    }
    void update(int& rt, T2 l, T2 r, T2 x, T2 y, T1 val) {
        if(rt == 0) rt = ++tot;
        if(x == l && y == r) {
            st[rt] = val;
            lazy[rt] = val;
            return;
        }
        T2 mid = (l + r) >> 1;
        push_down(rt);
        if(y <= mid) update(lson[rt], l, mid, x, y, val);
        else if(x > mid) update(rson[rt], mid + 1, r, x, y, val);
        else update(lson[rt], l, mid, x, mid, val), update(rson[rt], mid + 1, r, mid + 1, y, val);
        push_up(rt);
    }
    T1 query(int& rt, T2 l, T2 r, T2 x, T2 y) {
        if(rt == 0) rt = ++tot;
        if(x == l && y == r) return st[rt];
        T2 mid = (l + r) >> 1;
        push_down(rt);
        if(y <= mid) return query(lson[rt], l, mid, x, y);
        else if(x > mid) return query(rson[rt], mid + 1, r, x, y);
        else return max(query(lson[rt], l, mid, x, mid), query(rson[rt], mid + 1, r, mid + 1, y));
    }
    T1 query(T2 x, T2 y) {
        return query(root, 1, N << 1, x, y);
    }
    void update(T2 x, T2 y, T1 val) {
        update(root, 1, N << 1, x, y, val);
    }
};

seg<pii, ll> st;

vpii v[N];
vi ans[N];
map<int, int> rnk;
os<int> id;
int n, m, pre[N];
bool vis[N];

inline void solve(){
    cin>>n>>m;
    for(int i = 1;i<=m;i++) {
        int x, l, r;
        cin>>x>>l>>r;
        v[x].pb(mp(l, r));
        id.ins(l);
        id.ins(r);
    }
    // discretization
    for(auto& x : id) {
        rnk[x] = ++k;
    }
    for(int i = 1;i<=n;i++) {
        for(pii& j : v[i]) {
            j.fir = rnk[j.fir];
            j.sec = rnk[j.sec];
        }
    }
    for(int i = 1;i<=n;i++) {
        // first is rows not deleted, second is last row
        pii Max = mp(0, 0);
        // you would want to choose the max last answer that is okay
        for(pii cur : v[i])
            Max = max(Max, st.query(cur.fir, cur.sec));
        pre[i] = Max.sec;
        // update all with max + 1
        for(pii cur : v[i]) {
            st.update(cur.fir, cur.sec, mp(Max.fir + 1, i));
        }
    }
    pii ans = st.query(1, N << 1);
    cout<<n - ans.fir<<'\n';
    int x = ans.sec;
    // going back the process
    while(x > 0) {
        vis[x] = 1;
        x = pre[x];
    }
    for(int i = 1;i<=n;i++) {
        if(vis[i]) continue;
        cout<<i<<' ';
    }
    cout<<'\n';
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
    // 84ecef820ae07338
    return 0;
}


/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/