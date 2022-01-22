#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, k, f[N][22], dep[N], lazy[N];
#define pb push_back
struct edge {
    int u, v, cnt;
    bool operator<(const edge& other) const {
        return cnt > other.cnt;
    }
};
vector<edge> lft, e;
vector<int> mst[N];

class DSU {
private: 
    int f[N], n;
public:
    DSU(int n) :n(n) { iota(f + 1, f + n + 1, 1); }
    int Find(int x) { return x == f[x] ? x : f[x] = Find(f[x]); }
    bool merge(int u, int v) {
        int fu = Find(u);
        int fv = Find(v);
        if(fu == fv) return 0;
        f[fu] = fv;
        return 1;
    }
};

void dfs(int u = 1, int fa = 0) {
    lazy[u] = lazy[fa] + (u <= k);
    dep[u] = dep[fa] + 1;
    f[u][0] = fa;
    for(int i = 1;i<=21;++i) f[u][i] = f[f[u][i - 1]][i - 1];
    for(int v : mst[u]) {
        if(v == fa) continue;
        dfs(v, u);
    }
}

int LCA(int u, int v) {
    if(dep[u] < dep[v]) swap(u, v);
    for(int i = 21;i>=0;--i) {
        if(dep[f[u][i]] >= dep[v]) u = f[u][i];
        if(u == v) return u;
    }
    for(int i = 21;i>=0;--i) {
        if(f[u][i] != f[v][i]) {
            u = f[u][i];
            v = f[v][i];
        }
    }
    return f[u][0];
}


int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>m>>k;
    DSU dsu(n);
    for(int i = 1;i<=m;++i) {
        int u, v, cnt; cin>>u>>v;
        cnt = (u > k) + (v > k);
        e.pb({u, v, cnt});
    }
    sort(e.begin(), e.end());
    for(int i = 1;i<=m;++i) {
        int u = e[i - 1].u, v = e[i - 1].v;
        if(dsu.merge(u, v)) {
            mst[u].pb(v);
            mst[v].pb(u);
        } else lft.pb({u, v});
    }
    for(int i = 1;i<=n;++i) 
        if(!dep[i]) dfs(i);
    int ans = 0;
    for(auto x : lft) {
        int lca = LCA(x.u, x.v);
        if(lca == 0) continue;
        int tot = lazy[x.u] + lazy[x.v] - (lazy[lca] << 1) + (lca <= k);
        ans += tot != 0;
    }
    cout<<ans<<'\n';
    return 0;
}
