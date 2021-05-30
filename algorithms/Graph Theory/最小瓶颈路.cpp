/*
 * Author: Andy Zhu
 * 
 * just a noob, what is coding?
 *
 * “Do we run the trails, or the trails run us? Get revenge on the trails that ran u like that” 
 * I pray the cows
 * My Dream School:
 * South Harmon Institute of Technology
 * The meaning of life is:
 * #define int long long
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <memory>
#include <string>
#include <algorithm>
#include <bitset>
#include <iterator>
#include <deque>
#include <random>
#define endl "\n"
#define l_b lower_bound
#define u_b upper_bound
#define ins insert
#define fir first
#define sec second
#define lc (rt << 1)
#define rc (rt << 1 | 1)
#define pb push_back
#define pf push_front
#define mp make_pair
#define random(a, b) rand() % (b - a + 1) + a
#define log(a, b) log(a) / log(b)
#define UM unordered_map;
#define US unordered_set;
#define V vector;
using ll = long long;
using lb = long double;
using namespace std;
typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;
typedef pair<string, string> PS;
typedef vector<int> VI;
typedef vector<PI> VPI;
typedef vector<ll> VLL;
typedef vector<PLL> VPLL;
typedef queue<int> QI;
typedef stack<int> STKI;
typedef deque<int> DQI;
typedef set<int> SI;
typedef set<ll> SLL;
typedef set<string> SS;
typedef unordered_set<int> USI;
typedef unordered_set<ll> USLL;
typedef unordered_set<string> USS;
typedef map<int, int> MI;
typedef map<ll, ll> MLL;
typedef map<string, string> MS;
typedef unordered_map<int, int> UMI;
typedef unordered_map<ll, ll> UMLL;
typedef unordered_map<string, string> UMS;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int dir[8][2] = {{0, 1}, {0, 0}, {-1, 0}, {1, 0}, {-1, 1}, {1, -1}, {-1, -1}, {1, 1}};

inline bool CMP(int a, int b){
    return a > b;
}

inline void copy(int a[], int b[], int sz){
    for(int i = 0;i<=sz;i++)
        a[i] = b[i];
}

inline int gcd(int a, int b){
    if(a == 0) return b;
    if(b == 0) return a;
    return gcd(b, a % b);
}

inline int lcm(int a, int b){
    return a / gcd(a, b) * b;
}

inline int getMid(int l, int r){
    return (l + r) >> 1;
}

inline ll fast_pow(ll a, ll b){
    if(b == 1) return a;
    ll tmp = fast_pow(a, b / 2);
    if(b % 2 == 1) return tmp * tmp * a;
    else return tmp * tmp;
}

inline bool is_prime(ll x){
    for(ll i = 2; i * i <= x;i++){
        if(x % i == 0) return false;
    }
    return true;
}

const int N = 1e5 + 10;
int n, m, k, F[N], dep[N], f[N][22], Min[N][22];
VPI e[N];
struct edge{
    int u, v, w;
} krus[N];

inline int Find(int x){
    return x == F[x] ? x : F[x] = Find(F[x]);
}

inline bool merge(int u, int v){
    int fu = Find(u);
    int fv = Find(v);
    if(fu == fv) return false;
    F[fu] = fv;
    return true;
}

inline bool cmp(edge a, edge b){
    return a.w < b.w;
}

inline void Kruskal(){
    for(int i = 1;i<=n;i++) F[i] = i;
    sort(krus + 1, krus + m + 1, cmp);
    for(int i = 1;i<=m;i++){
        int u = krus[i].u;
        int v = krus[i].v;
        int w = krus[i].w;
        if(merge(u, v)){
            e[u].pb(mp(v, w));
            e[v].pb(mp(u, w));
        }
    }
}

inline void dfs(int u, int fa, int d, int dist){
    dep[u] = d;
    f[u][0] = fa;
    Min[u][0] = dist;
    for(int i = 1;i<=20;i++){
        f[u][i] = f[f[u][i - 1]][i - 1];
        Min[u][i] = max(Min[f[u][i - 1]][i - 1], Min[u][i - 1]);
    }
    for(int i = 0;i<e[u].size();i++){
        PI v = e[u][i];
        if(v.fir == fa) continue;
        dfs(v.fir, u, d + 1, v.sec);
    }
}

inline int LCA(int x, int y){
    if(Find(x) != Find(y)) return -1;
    if(dep[x] < dep[y]) swap(x, y);
    int ans = 0;
    for(int i = 20;i>=0;i--){
        if(dep[f[x][i]] >= dep[y]){
            ans = max(Min[x][i], ans);
            x = f[x][i];
        }
        if(x == y) return ans;
    }
    for(int i = 20;i>=0;i--){
        if(f[x][i] != f[y][i]) {
            ans = max(ans, max(Min[x][i], Min[y][i]));
            x = f[x][i];
            y = f[y][i];
        }
    }
    ans = max(ans, max(Min[x][0], Min[y][0]));
    return ans;
}

int main(){
    srand(time(0));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i = 1;i<=m;i++){
        int u, v, w;
        cin>>u>>v>>w;
        krus[i].u = u;
        krus[i].v = v;
        krus[i].w = w;
    }
    Kruskal();
    dfs(1, 0, 1, 0);
    for(int i = 1;i<=k;i++){
        int s, t;
        cin>>s>>t;
        cout<<LCA(s, t)<<endl;
    }
    return 0;
}
