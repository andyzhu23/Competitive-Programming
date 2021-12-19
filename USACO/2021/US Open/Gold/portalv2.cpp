#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 2e5 + 10;
int n;

struct portal {
    int m, a, b, c, d;
};

struct edge {
    int u, v, w;
    bool operator<(const edge& other) const {
        return w < other.w;
    }
};
vector<edge> e;

vector<portal> p;
vector<int> adj[N];
int color[N], tot, f[N];

void dfs(int u, int c) {
    color[u] = c;
    for(int v : adj[u]) {
        if(color[v]) continue;
        dfs(v, c);
    }
}

int Find(int x) {return f[x] == x ? x : f[x] = Find(f[x]);}
bool merge(int u, int v) {
    int fu = Find(u);
    int fv = Find(v);
    if(fu == fv) return 0;
    f[fu] = fv;
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    for(int i = 1;i<=n;++i) {
        int m, a, b, c, d;
        cin>>m>>a>>b>>c>>d;
        p.pb({m, a, b, c, d});
        adj[a].pb(b);
        adj[b].pb(a);
        adj[c].pb(d);
        adj[d].pb(c);
    }
    for(int i = 1;i<=n * 2;++i) {
        if(!color[i]) dfs(i, ++tot);
    }
    for(auto x : p) {
        e.pb({color[x.a], color[x.c], x.m});
        e.pb({color[x.b], color[x.d], x.m});
    }
    sort(e.begin(), e.end());
    for(int i = 0;i<=tot;++i) f[i] = i;
    int ans = 0;
    for(auto x : e) {
        if(merge(x.u, x.v)) {
            ans += x.w;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
