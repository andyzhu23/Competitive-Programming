#include <bits/stdc++.h>
using namespace std;
const int N = 205;
using ll = long long;
int n, m, s, t;
ll e[N][N], mn[N];
int last[N];
bitset<N> vis;

bool bfs() {
    vis.reset();
    memset(mn, 0x3f, sizeof(mn));
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        if(u == t) break;
        for(int v = 1;v<=n;++v) if(e[u][v] != 0 && !vis[v]) {
            mn[v] = min(mn[u], e[u][v]);
            vis[v] = 1;
            last[v] = u;
            q.push(v);
        }
    }
    return vis[t];
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>m>>s>>t;
    for(int i = 1;i<=m;++i) {
        int u, v, w;
        cin>>u>>v>>w;
        e[u][v] += w;
    }
    ll ans = 0;
    while(bfs()) {
        int u = t;
        while(u != s) {
            e[u][last[u]] += mn[t];
            e[last[u]][u] -= mn[t];
            u = last[u];
        }
        ans += mn[t];
    }
    cout<<ans<<'\n';
    return 0;
}
