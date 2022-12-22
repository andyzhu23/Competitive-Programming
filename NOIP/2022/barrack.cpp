#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ins insert
using ll = long long;
const int N = 1e6 + 5;
const int mod = 1e9 + 7;
int n, m;
vector<int> E[N], stk;
set<int> e[N];

int dfn[N], low[N], tot, color, c[N];
bitset<N> vis;
int ee[N], sz[N];

void tarjan(int u, int fa = 0) {
    dfn[u] = low[u] = ++tot;
    stk.pb(u);
    vis[u] = 1;
    for(int v : E[u]) if(v != fa) {
        if(!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        } else if(vis[v]) low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u]) {
        ++color;
        while(stk.back() != u) {
            vis[stk.back()] = 0;
            c[stk.back()] = color;
            ++sz[color];
            stk.pop_back();
        } 
        vis[stk.back()] = 0;
        c[stk.back()] = color;
        ++sz[color];
        stk.pop_back();
    }
}

ll dp[N], p[N], ans = 0;
int cnt[N];

void dfs(int u = 1, int fa = 0) {
    cnt[u] = 1;
    dp[u] = p[sz[u]];
    for(int v : e[u]) if(v != fa) {
        dfs(v, u);
        cnt[u] += cnt[v];
        dp[u] = dp[u] * (dp[v] + p[cnt[v]]) % mod;
    }
    dp[u] = (dp[u] - p[cnt[u] - 1] + mod) % mod;
    ll tmp = dp[u];
    for(int v : e[u]) if(v != fa) {
        tmp = (tmp - dp[v] * p[cnt[u] - cnt[v] - 1] % mod + mod) % mod;
    }
    ans = (ans + tmp * p[color - cnt[u]] % mod) % mod;
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>m;
    for(int i = 1;i<=m;++i) {
        int u, v;
        cin>>u>>v;
        E[u].pb(v);
        E[v].pb(u);
    }
    for(int i = 1;i<=n;++i) if(!dfn[i]) tarjan(i);
    int ret = 0;
    for(int u = 1;u<=n;++u) {
        for(int v : E[u]) if(c[u] != c[v]) {
            e[c[u]].ins(c[v]);
        } else ee[c[u]] += u > v, ret += u > v;
    }
    p[0] = 1;
    for(int i = 1;i<N;++i) p[i] = p[i - 1] * 2 % mod;
    dfs();
    cout<<ans * p[ret] % mod<<'\n';
    return 0;
}
