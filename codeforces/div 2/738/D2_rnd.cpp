/*
 * Author: Andy Zhu
 * @date    2021-08-23 09:24:08
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
#define mset(x, y) memset(x, y, sizeof(x))

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

const int N = 1e5 + 10;
int n, m1, m2;

struct dsu {
    int n;
    vi f, node[N], com;
    dsu(int n) :n(n) {
        f = vi(n);
        for(int i = 0;i<n;i++) {
            f[i] = i;
            node[i].pb(i);
            com.pb(i);
        }
    }
    int Find(int x) {return f[x] == x ? x : f[x] = Find(f[x]);}
    bool Union(int u, int v) {
        int fu = Find(u);
        int fv = Find(v);
        if(fu == fv) return 0;
        if(fv < fu) swap(fu, fv);
        f[fv] = fu;
        merge(ALL(node[fv]), ALL(node[fu]), node[fu].begin());
        com.erase(lb(ALL(com), fv));
        return 1;
    }
    bool ok(int u, int v) {
        return Find(u) != Find(v);
    }
};

int getNode(int com, dsu& f) {
    return f.node[com][random(0, f.node[com].size() - 1)];
}

int getCom(dsu& f1, dsu& f2) {
    if(rand() & 1) {
        int rnd = random(0, f1.com.size() - 1);
        return getNode(f1.com[rnd], f1);
    } else {
        int rnd = random(0, f2.com.size() - 1);
        return getNode(f2.com[rnd], f2);
    }
}

inline void solve(){
    cin>>n>>m1>>m2;
    dsu f1(n), f2(n);
    for(int i = 1;i<=m1;i++) {
        int u, v;
        cin>>u>>v;
        u--, v--;
        f1.Union(u, v);
    }
    for(int i = 1;i<=m2;i++) {
        int u, v;
        cin>>u>>v;
        u--, v--;
        f2.Union(u, v);
    }
    int need = n - 1 - max(m1, m2);
    vpii ans;
    while(need) {
        // get 2 random node from two random component that 
        // is randomly decided from the two forests
        int a = getCom(f1, f2);
        int b = getCom(f1, f2);
        if(f1.ok(a, b) && f2.ok(a, b)) {
            f1.Union(a, b);
            f2.Union(a, b);
            ans.pb(mp(a + 1, b + 1));
            --need;
        }
    }
    cout<<ans.size()<<'\n';
    for(pii i : ans) cout<<i.fir<<" "<<i.sec<<'\n';
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
