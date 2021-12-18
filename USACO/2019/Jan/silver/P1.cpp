#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(v) v.begin(), v.end()
const int N = 1e5 + 10;
int n, color[N], last[N];
vector<int> e[N];
unordered_set<int> vis[N];

inline void dfs(int u, int fa = 0) {
    int c = last[fa] + 1;
    while(vis[fa].count(c)) ++c;
    vis[fa].insert(c);
    vis[u].insert(color[fa]);
    vis[u].insert(c);
    color[u] = c;
    last[fa] = c;
    for(int v : e[u]) {
        if(v == fa) continue;
        dfs(v, u);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
#endif
    cin>>n;
    for(int i = 1;i<n;++i) {
        int u, v;
        cin>>u>>v;
        e[u].pb(v);
        e[v].pb(u);
    }
    dfs(1);
    int ans = 0;
    for(int i = 1;i<=n;++i) ans = max(ans, color[i]);
    cout<<ans<<'\n';
    return 0;
}
