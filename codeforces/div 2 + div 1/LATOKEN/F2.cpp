/*
 * Author: Andy Zhu
 * @date    2021-08-30 09:54:23
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

#define id(x, y) ((x - 1) * m + y)
const int N = 4e5 + 10;
int n, m, last[N], a[N];
bool special[N], need[N], cancel[N], sand[N], vis[N];
vi e[N], e2[N], e3[N];
vec<string> board;
vi hit[N], top, bonny;
vpii path;
pii dp[N];
int dfn[N], low[N], tot, color, colid[N], in[N], val[N];
bool instk[N];
stack<int> stk;
int Map[N];

bool cmp(pii a, pii b) {
    return a.sec < b.sec;
}

bool cmp2(int a, int b) {
    return val[a] < val[b];
}

void tarjan(int u) {
    low[u] = dfn[u] = ++tot;
    stk.push(u);
    instk[u] = 1;
    for(int v : e[u]) {
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[v], low[u]);
        } else if(instk[v]) low[u] = min(dfn[v], low[u]);
    }
    if(low[u] == dfn[u]) {
        color++;
        while(stk.top() != u) {
            colid[stk.top()] = color;
            need[color] |= special[stk.top()];
            instk[stk.top()] = 0;
            stk.pop();
        }
        val[color] = stk.top() % m;
        if(val[color] == 0) val[color] = m;
        colid[stk.top()] = color;
        need[color] |= special[stk.top()];
        instk[stk.top()] = 0;
        stk.pop();
    }
}

void dfs1(int u) {
    if(vis[u]) return;
    vis[u] = 1;
    if(need[u]) cancel[u] = 1;
    for(int v : e2[u]) {
        if(vis[v]) continue;
        dfs1(v);
    }
}

bool vis2[N];

void dfs2(int u) {
    if(cancel[u] || vis2[u]) return;
    vis2[u] = 1;
    if(in[u] == 0) {
        dp[u].fir = dp[u].sec = Map[u];
        return;
    }
    for(int v : e3[u]) {
        if(cancel[v]) continue;
        if(!vis2[v]) dfs2(v);
        dp[u].fir = min(dp[u].fir, dp[v].fir);
        if(dp[u].fir == 0) dp[u].fir = dp[v].fir;
        dp[u].sec = max(dp[u].sec, dp[v].sec);
    }
}

inline void solve(){
    cin>>n>>m;
    // turn grid into graph
    for(int i = 1;i<=n;i++) {
        string s; cin>>s;
        board.pb(s);
        for(int j = 1;j<=m;j++) {
            if(s[j - 1] == '#') {
                sand[id(i, j)] = 1;
                // top
                if(last[j]) {
                    e[last[j]].pb(id(i, j));
                    if(i > 1 && last[j] == id(i - 1, j))
                        e[id(i, j)].pb(last[j]);
                } 
                // left
                if(j > 1 && last[j - 1]) {
                    e[last[j - 1]].pb(id(i, j));
                    if(last[j - 1] == id(i, j - 1)) 
                        e[id(i, j)].pb(last[j - 1]);
                }
                // right
                if(j < m && last[j + 1]) 
                    e[last[j + 1]].pb(id(i, j));

                last[j] = id(i, j);
            } 
        }
    }

    // assign special nodes
    for(int j = 1;j<=m;j++) {
        cin>>a[j];
        int i = n;
        for(int cnt = 0;i > 0 && cnt < a[j];i--) {
            if(board[i - 1][j - 1] == '#') {
                special[id(i, j)] = 1;
                ++cnt;
            }
        }
        
    }
    
    // run tarjan
    for(int i = 1;i<=n * m;i++) 
        if(!dfn[i] && sand[i]) tarjan(i);

    // build new DAG graph
    for(int i = 1;i<=n * m;i++) {
        if(e[i].empty()) continue;
        for(int v : e[i]) {
            if(colid[i] == colid[v]) continue;
            e2[colid[i]].pb(colid[v]);
            e3[colid[v]].pb(colid[i]);
            in[colid[v]] ++;
        }
    }

    // cancel nodes that are needed but don't need direct push
    for(int i = 1;i<=color;i++) {
        if(in[i] == 0) top.pb(i);
        if(need[i]) 
            for(int v : e2[i]) 
                if(!vis[v]) dfs1(v);
    }

    sort(all(top), cmp2);
    int cnt = 0;
    for(int i : top) Map[i] = ++cnt;
    
    // calculate interval
    for(int i = 1;i<=color;i++) {
        if(need[i] && !cancel[i]) bonny.pb(i);
        dfs2(i);
    }
    
    for(int i : bonny) path.pb(dp[i]);

    // gassing bonny
    sort(all(path), cmp);
    int ans = 0, lastkill = 0;
    for(pii i : path) {
        if(i.fir > lastkill) {
            ans ++;
            lastkill = i.sec;
        }
    }
    cout<<ans<<'\n';
}


//---------------------  end of program  ---------------------


#define doCase 0
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
