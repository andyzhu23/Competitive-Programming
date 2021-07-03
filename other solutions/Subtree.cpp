/*
 * Author: Andy Zhu
 * @date    2021-07-02 11:34:36
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
#define clr(x) memset(x, 0, sizeof(x));
#define setINF(x) memset(x, 63, sizeof(x));

// Data Structure Shorten
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using qi = queue<int>;
using stki = stack<int>;
template <typename T> using vec = vector<T>;
template <typename T> using uset = unordered_set<T>;
template <typename T1, typename T2> using umap = unordered_map<T1, T2>;
template <typename T> using pq = priority_queue<T>;
template <typename T> using pqg = priority_queue<T, vec<T>, greater<T> >;
using vi = vec<int>;
using vpii = vec<pii>;
using vll = vec<ll>;
using vpll = vec<pll>;

// common variables
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
int MOD = 1e9 + 7;
const int dir[8][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {-1, 1}, {1, -1}, {-1, -1}, {1, 1}};
struct Edge {int u, v, w;};

// common functions
template <typename T> inline void cmax(T& u, T v) { u = max(u, v); }
template <typename T> inline void cmin(T& u, T v) { u = min(u, v); }

template <typename T> inline T lowbit(T x){return x & (- x);}
template <typename T> inline T __lcm(T a, T b){return a / __gcd(a, b) * b;}
template <typename T1, typename T2> inline T1 fast_pow(T1 a, T2 b){if(b == 1) return a; T1 tmp = fast_pow(a, b >> 1); if(b & 1) return tmp * tmp * a; else return tmp * tmp;}
template <typename T> inline bool is_prime(T x){if(x == 1) return false; for(T i = 2; i * i <= x;i++) if(x % i == 0) return false; return true;}

template <typename T> inline void debugArray(T *arr,int sz){cout<<"[";for(int i=0;i<sz;i++){cout<<arr[i]<<", "; } cout<<"]\n";}
template <typename T> inline void printArray(T *arr,int sz){for(int i=0;i<sz;i++){cout<<arr[i]<<" "; } cout<<"\n";}


//------------------- start of initialize -------------------

inline void init1(){
    // initialize for all cases

}

inline void init2(){
    // initialize for the current subcase

}

//-------------------  end of initialize  -------------------

//--------------------- start of program ---------------------

const int N = 1e5 + 10;
ll n, dp[N], dp2[N]; // dp[u] means node u is black
vi e[N];

int root = 3;

void dfs(int u, int fa) {
    for(int v : e[u]) {
        if(v == fa) continue;
        dfs(v, u);
        dp[u] *= dp[v] + 1;
        dp[u] %= MOD;
    }
}

void dfs2(int u, int fa) {
    // compute prefix-suffix
    vll pre(e[u].size() + 10), suf(e[u].size() + 10);
    pre[0] = 1, suf[e[u].size()] = 1;
    for(int i = 0;i<e[u].size();i++) {
        if(e[u][i] == fa) e[u].erase(e[u].begin() + i);
    }
    pre[0] = 1, suf[e[u].size()] = 1;
    for(int i = 0;i<e[u].size();i++) {
        pre[i + 1] = (dp[e[u][i]] + 1) * pre[i] % MOD;
    }
    for(int i = e[u].size() - 1;i>=0;i--) {
        suf[i] = (dp[e[u][i]] + 1) * suf[i + 1] % MOD;
    }
    for(int i = 0;i<e[u].size();i++) {
        if(e[u][i] == fa) continue;
        ll res = pre[i] * suf[i + 1] % MOD;
        int v = e[u][i];
        dp2[v] = 1 + dp2[u] * res % MOD;
        dfs2(v, u);
    }
}

inline void solve(){
    cin>>n>>MOD;
    root = 1;
    for(int i = 1;i<n;i++) {
        int x, y;
        cin>>x>>y;
        e[x].pb(y);
        e[y].pb(x);
    }
    for(int i = 1;i<=n;i++) dp[i] = 1;
    dfs(root, 0);
    dp2[root] = 1;
    dfs2(root, 0);
    for(int i = 1;i<=n;i++) cout<<dp2[i] * dp[i] % MOD<<endl;
}

//---------------------  end of program  ---------------------


#define doCase 0
#define config 0
#define kickstart 0

int main(){
#if config
    // configuration here
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
#endif
    srand(time(0));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init1();
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
