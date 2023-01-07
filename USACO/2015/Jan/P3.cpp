#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 2e5 + 5;
int n, m;
vector<int> ee[N], e[N], stk;

int dfn[N], low[N], tot, color, c[N], sz[N], dp[N];
bitset<N> vis;

void tarjan(int u) {
    dfn[u] = low[u] = ++tot;
    vis[u] = 1;
    stk.pb(u);
    for(int v : ee[u]) {
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[v], low[u]);
        } else if(vis[v]) low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u]) {
        ++color;
        while(stk.back() != u) {
            c[stk.back()] = color;
            vis[stk.back()] = 0;
            stk.pop_back();
            ++sz[color];
        }
        c[stk.back()] = color;
        vis[stk.back()] = 0;
        stk.pop_back();
        ++sz[color];
    }
}

int dfs(int u) {
    if(vis[u]) return dp[u];
    vis[u] = 1;
    for(int v : e[u]) dp[u] = max(dp[u], dfs(v));
    dp[u] += sz[u];
    return dp[u];
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    // freopen("grass.in", "r", stdin);
    // freopen("grass.out", "w", stdout);
    cin>>n>>m;
    while(m--) {
        int u, v;
        cin>>u>>v;
        ee[u].pb(v);
        ee[u + n].pb(v + n);
        ee[v].pb(u + n);
    }
    for(int i = 1;i<=n * 2;++i) if(!dfn[i]) tarjan(i);
    for(int u = 1;u<=n * 2;++u) {
        for(int v : ee[u]) if(c[u] != c[v]) {
            e[c[v]].pb(c[u]);
        }
    }
    memset(dp, -0x3f, sizeof dp);
    dp[c[1]] = 0;
    vis[c[1]] = 1;
    cout<<dfs(c[n + 1])<<'\n';
    return 0;
}
