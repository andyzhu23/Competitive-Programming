#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
using ll = long long;
int n, m, k;
ll e[N][N], mn[N];
int last[N];
bitset<N> vis;

bool bfs() {
    vis.reset();
    memset(mn, 0x3f, sizeof(mn));
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        if(u == n + m + 1) break;
        for(int v = 0;v<=n + m + 1;++v) if(e[u][v] != 0 && !vis[v]) {
            mn[v] = min(mn[u], e[u][v]);
            vis[v] = 1;
            last[v] = u;
            q.push(v);
        }
    }
    return vis[n + m + 1];
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>k>>m>>n;
    for(int i = 1;i<=k;++i) {
        int u, v;
        cin>>u>>v;
        e[u][v + m] += 1;
    }
    for(int i = 1;i<=m;++i) e[0][i] = 1;
    for(int i = m + 1;i<=n + m;++i) e[i][n + m + 1] = 1;
    ll ans = 0;
    while(bfs()) {
        int u = n + m + 1;
        while(u != 0) {
            e[u][last[u]] += mn[n + m + 1];
            e[last[u]][u] -= mn[n + m + 1];
            u = last[u];
        }
        ans += mn[n + m + 1];
    }
    cout<<ans<<'\n';
    return 0;
}
