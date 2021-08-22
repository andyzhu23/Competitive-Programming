/*
 * Author: Andy Zhu
 * @date    2021-08-21 20:19:21
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

#define id(x, y) ((x - 1) * m + y)
const int N = 1e3 + 10;
const int NN = N * N;
char a[N][N];
char b[NN];
int ans = 0;
int n, m;

struct dsu {
    int n;
    vi f;
    dsu(int n) :n(n) {
        f = vi(n + 10);
        for(int i = 1;i<=n;i++) f[i] = i;
    }
    int Find(int x) {return f[x] == x ? x : f[x] = Find(f[x]);}
    bool merge(int u, int v) {
        int fu = Find(u);
        int fv = Find(v);
        if(fu == fv) return 0;
        f[fv] = fu;
        return 1;
    }
};

void hor(dsu& f) {
    for(int k = 1;k<=n;k++) {
        int pre = 1;
        for(int i = 1;i<=m;i++) {
            if(a[k][i] == '#') {
                i--;
                for(int l = pre, r = i;l <= r;l ++, r--) {
                    int x = id(k, l);
                    int y = id(k, r);
                    if(b[f.Find(x)] != '.') f.merge(x, y);
                    else f.merge(y, x);
                }
                i ++;
                pre = i + 1;
            }
        }
        if(pre == m) continue;
        for(int l = pre, r = m;l <= r;l ++, r--) {
            int x = id(k, l);
            int y = id(k, r);
            if(b[f.Find(x)] != '.') f.merge(x, y);
            else f.merge(y, x);
        }
    }
}

void ver(dsu& f) {
    for(int k = 1;k<=m;k++) {
        int pre = 1;
        for(int i = 1;i<=n;i++) {
            if(a[i][k] == '#') {
                i--;
                for(int l = pre, r = i;l <= r;l ++, r--) {
                    int x = id(l, k);
                    int y = id(r, k);
                    if(b[f.Find(x)] != '.') f.merge(x, y);
                    else f.merge(y, x);
                }
                i ++;
                pre = i + 1;
            }
        }
        if(pre == n) continue;
        for(int l = pre, r = n;l <= r;l ++, r--) {
            int x = id(l, k);
            int y = id(r, k);
            if(b[f.Find(x)] != '.') f.merge(x, y);
            else f.merge(y, x);
        }
    }
}

inline void solve(){
    dsu f(NN);
    cin>>n>>m;
    memset(a, 0, sizeof(a));
    ans = 0;
    for(int i = 1;i<=n;i++) {
        string s; cin>>s;
        for(int j = 1;j<=m;j++) {
            a[i][j] = s[j - 1];
            b[id(i, j)] = a[i][j];
        }
    }
    hor(f);
    ver(f);
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=m;j++) {
            if(b[id(i, j)] != b[f.Find(id(i, j))]) {
                ans++;
                a[i][j] = b[f.Find(id(i, j))];
            }
        }
    }
    cout<<ans<<'\n';
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=m;j++) {
            cout<<a[i][j];
        }
        cout<<'\n';
    }

}


//---------------------  end of program  ---------------------


#define doCase 1
#define config 0
#define kickstart 1
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
    * correct elements
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/
