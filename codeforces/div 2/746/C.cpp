/*
 * Author: Andy Zhu
 * @date    2021-10-03 07:29:09
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
struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

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

const int N = 1e5 + 10;
vector<int> e[N];
int n, k, a[N], dp[N], tot;

void dfs(int u, int fa) {
    dp[u] = a[u];
    for(int v : e[u]) {
        if(v == fa) continue;
        dfs(v, u);
        dp[u] ^= dp[v];
    }
}

// check even
bool flag = 0;
void dfs1(int u, int fa) {
    if(flag) return;
    if(u != 1 && dp[u] == (dp[1] ^ dp[u])) {
        cout<<"YES"<<'\n';
        flag = 1;
        return;
    }

    for(int v : e[u]) {
        if(v == fa) continue;
        dfs1(v, u);
    }
}

// check odd
vi ans;
int ok[N];
void dfs2(int u, int fa) {
    if(ans.size() >= 2) return;
    for(int v : e[u]) {
        if(v == fa) continue;
        dfs2(v, u);
        ok[u] += ok[v];
    }
    if(!ok[u] && u != 1 && dp[u] == tot) {
        ans.pb(u);
        ok[u] = 1;
    } else if(ok[u] && u != 1 && dp[u] == 0) {
        ans.pb(u);
    }

}

inline void solve(){
    cin>>n>>k;
    for(int i = 1;i<=n;++i) e[i].clear();
    ans.clear();
    flag = 0;
    tot = 0;
    for(int i = 1;i<=n;++i) {
        ok[i] = 0;
        dp[i] = 0;
        cin>>a[i];
        tot ^= a[i];
    }
    for(int i = 1;i<n;++i) {
        int u, v;
        cin>>u>>v;
        e[u].pb(v);
        e[v].pb(u);
    }
    dfs(1, 0);
    if(tot == 0) {
        dfs1(1, 0);
        if(flag) return;
    } else {
        if(k == 2) {
            cout<<"NO"<<'\n';
            return;
        }
        dfs2(1, 0);
        if(ans.size() == 1) {
            cout<<"NO"<<'\n';
            return;
        }
        if(ok[1] == 2 && ((dp[1] ^ dp[ans[0]] ^ dp[ans[1]]) == tot)) {
            cout<<"YES"<<'\n';
            return;
        } else if(ok[1] == 1 && (dp[1] ^ dp[ans[1]]) == tot) {
            cout<<"YES"<<'\n';
            return;
        }
    }
    cout<<"NO"<<'\n';
}


//---------------------  end of program  ---------------------


#define doCase 1
#define config !OJ
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
    return 0;
}


/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/