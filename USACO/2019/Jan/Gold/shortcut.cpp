#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
using ll = long long;
using pll = pair<ll, ll>;
#define pb push_back
#define fir first
#define sec second
int n, m, t, c[N], fa[N];
ll dist[N], siz[N];
vector<pll> e[N];
vector<int> tr[N];

void dij() {
    priority_queue<pll, vector<pll>, greater<pll> > heap;
    heap.push({0, 1});
    memset(dist, 0x3f, sizeof(dist));
    memset(fa, 0x3f, sizeof(fa));
    fa[1] = 0;
    dist[1] = 0;
    while(!heap.empty()) {
        pll cur = heap.top(); heap.pop();
        int u = cur.sec;
        for(pll v : e[u]) {
            if (dist[v.fir] > dist[u] + v.sec) {
                fa[v.fir] = min(u, fa[v.fir]);
                dist[v.fir] = dist[u] + v.sec;
                heap.push({dist[v.fir], v.fir});
                fa[v.fir] = u;
            } else if(dist[v.fir] == dist[u] + v.sec) {
                fa[v.fir] = min(u, fa[v.fir]);
            }
        }
    }
}

ll ans = 0;

void dfs(int u = 1, int fa = 0) {
    siz[u] = c[u];
    for(int v : tr[u]) {
        if(v == fa) continue;
        dfs(v, u);
        siz[u] += siz[v];
    }
    ans = max(ans, (dist[u] - t) * siz[u]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("shortcut.in", "r", stdin);
    freopen("shortcut.out", "w", stdout);
    cin>>n>>m>>t;
    for(int i = 1;i<=n;++i) cin>>c[i];
    for(int i = 1;i<=m;++i) {
        int u, v, w;
        cin>>u>>v>>w;
        e[u].pb({v, w});
        e[v].pb({u, w});
    }
    
    dij();
    for(int i = 1;i<=n;++i) {
        tr[fa[i]].pb(i);
        tr[i].pb(fa[i]);
    }
    dfs();
    cout<<ans<<'\n';
    return 0;
}
