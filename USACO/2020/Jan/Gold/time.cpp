#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 1e3 + 10;
int n, m, c, a[N], dp[N][N];
bool vis[N][N];
vector<int> e[N];

int dfs(int t, int u) {
    if(vis[t][u]) return dp[t][u];
    vis[t][u] = 1;
    if(t == 0 && u != 1) return -1e9;
    for(int v : e[u]) {
        dp[t][u] = max(dp[t][u], dfs(t - 1, v) + a[u]);
    }
    return dp[t][u];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    cin>>n>>m>>c;
    for(int i = 1;i<=n;++i) cin>>a[i];
    for(int i = 1;i<=m;++i) {
        int u, v;
        cin>>u>>v;
        e[v].pb(u);
    }
    memset(dp, -0x3f, sizeof(dp));
    vis[0][1] = 1;
    dp[0][1] = 0;
    int ans = 0;
    for(int i = 0;i<=1e3 + 1;++i) ans = max(ans, dfs(i, 1) - i * i * c);
    cout<<ans<<'\n';
    return 0;
}
