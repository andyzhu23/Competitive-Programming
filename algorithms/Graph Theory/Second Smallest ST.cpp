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
const ll INF = 1e18;
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
const int M = 6e5 + 10;
VPI e[N], mst[N];
int n, m, F[N], dep[N], f[N][22], Max[N][22], cmax[N][22];
ll sum = 0;
struct edge{
    int u, v, w;
    bool flag;
} k[M];

inline int cmp(edge a, edge b){
    return a.w < b.w;
}

inline int Find(int x){
    return F[x] == x ? x : F[x] = Find(F[x]);
}

inline bool merge(int u, int v){
    int fu = Find(u);
    int fv = Find(v);
    if(fu == fv) return false;
    F[fu] = fv;
    return true;
}

inline void Kruskal(){
    for(int i= 1;i<=n;i++) F[i] = i;
    sort(k + 1, k + m + 1, cmp);
    for(int i = 1;i<=m;i++){
        int u = k[i].u;
        int v = k[i].v;
        int w = k[i].w;
        if(merge(u, v)){
            sum += w;
            mst[u].pb(mp(v, w));
            mst[v].pb(mp(u, w));
            k[i].flag = true;
        }
    }
}

inline void getMax(int u, int i){
    Max[u][i] = max(Max[u][i - 1], Max[f[u][i - 1]][i - 1]);
    cmax[u][i] = max(cmax[u][i - 1], cmax[f[u][i - 1]][i - 1]);
    cmax[u][i] = Max[u][i - 1] < Max[u][i] ? max(cmax[u][i], Max[u][i - 1]) : cmax[u][i];
    cmax[u][i] = Max[f[u][i - 1]][i - 1] < Max[u][i] ? max(cmax[u][i], Max[f[u][i - 1]][i - 1]) : cmax[u][i];
}

inline void dfs(int u, int fa, int d, int dist){
    dep[u] = d;
    f[u][0] = fa;
    Max[u][0] = dist;
    for(int i = 1;i<=20;i++){
        f[u][i] = f[f[u][i - 1]][i - 1];
        getMax(u, i);
    }
    for(int i = 0;i<mst[u].size();i++){
        PI v = mst[u][i];
        if(v.fir == fa) continue;
        dfs(v.fir, u, d + 1, v.sec);
    }
}
int Max1, cmax1;
inline void getMax2(int u, int i){
    int tmp = Max1;
    Max1 = max(Max1, Max[u][i]);
    cmax1 = max(cmax1, cmax[u][i]);
    cmax1 = Max1 > Max[u][i] ? max(cmax1, Max[u][i]) : cmax1;
    cmax1 = Max1 > tmp ? max(cmax1, tmp) : cmax1;
}

inline int LCA(int x, int y, int w){
    if(dep[x] < dep[y]) swap(x, y);
    for(int i = 20;i>=0;i--){
        if(dep[f[x][i]] >= dep[y]){
            getMax2(x, i);
            x = f[x][i];


        }
        if(x == y) return Max1 == w ? cmax1 : Max1;
    }
    for(int i = 20;i>=0;i--){
        if(f[x][i] != f[y][i]){
            getMax2(x, i);
            getMax2(y, i);
            x = f[x][i];
            y = f[y][i];

        }
    }
    getMax2(x, 0);
    getMax2(y, 0);
    return Max1 == w ? cmax1 : Max1;
}

int main(){
    srand(time(0));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i = 1;i<=m;i++){
        int x, y, z;
        cin>>x>>y>>z;
        e[x].pb(mp(y, z));
        e[y].pb(mp(x, z));
        k[i].u = x;
        k[i].v = y;
        k[i].w = z;
        k[i].flag = false;
    }
    Kruskal();
    dfs(1, 0, 1, -1);
    ll ans = INF;
    for(int i = 1;i<=m;i++){
        if(k[i].flag) continue;
        int u = k[i].u;
        int v = k[i].v;
        int w = k[i].w;
        ans = min(ans, sum - LCA(u, v, w) + w);
        Max1 = -2;
        cmax1 = -2;
    }
    cout<<ans<<endl;
    return 0;
}
