/*
 * Author: Andy Zhu
 */

#include <iostream>
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
using namespace std;
#define endl "\n"
#define lc (st << 1)
#define rc (st << 1 | 1)
#define pb push_back
#define mp make_pair
typedef long long ll;
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
const int N = 1e5 + 10;
inline int gcd(int a, int b){
    if(a == 0) return b;
    if(b == 0) return a;
    return gcd(b, a % b);
}

inline int lcm(int a, int b){
    return a * b / gcd(a, b);
}

inline int getMid(int l, int r){
    return (l + r) >> 1;
}

inline int fast_pow(ll a, ll b){
    if(b == 1) return a;
    ll tmp = fast_pow(a, b / 2);
    if(a % 2 == 1) return tmp * tmp * a;
    else return tmp * tmp;
}

VI e[N];
int n, m, block[N], id[N], len = 0;
bool vis[N];
string s;

inline void dfs(int u, int fa){
    block[u] = len;
    vis[u] = true;
    for(int i = 0;i<e[u].size();i++) {
        if(e[u][i] == fa) continue;
        if(s[e[u][i] - 1] == s[u - 1]) dfs(e[u][i], u);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("milkvisits.in", "r", stdin);
    //freopen("milkvisits.out", "w", stdout);
    cin>>n>>m;
    cin>>s;
    for(int i = 1;i<n;i++){
        int a, b;
        cin>>a>>b;
        e[a].pb(b);
        e[b].pb(a);
    }

    for(int i = 1;i<=n;i++){
        if(vis[i]) continue;
        id[++len] = s[i - 1];
        dfs(i, 0);
    }

    while(m--){
        int a, b;
        char c;
        cin>>a>>b >> c;
        if(block[a] != block[b]) cout<<1;
        else {
            if(id[block[a]] == c) cout<<1;
            else cout<<0;
        }
    }
    cout<<endl;
    return 0;
}
