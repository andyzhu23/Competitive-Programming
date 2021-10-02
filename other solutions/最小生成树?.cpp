#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define mp make_pair
#define pb push_back
const int N = 3e5 + 10;
int n, m, root, dep[N], f[N][25], ans[N], tot = 0;
vector<int> mst[N];
vector<int> r;
set<pii> vis;
bool isr[N];
struct edge {
    int u, v, id;
};
vector<edge> e;
int gofa[N];
map<pii, int> findID;

void dfs(int u, int fa) {
    dep[u] = dep[fa] + 1;
    f[u][0] = fa;
    gofa[u] = findID[mp(min(u, fa), max(fa, u))];
    for(int i = 1;i<=22;++i) {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }
    for(int v : mst[u]) {
        if(v == fa) continue;
        dfs(v, u);
    }
}

int LCA(int u, int v) {
    if(dep[v] > dep[u]) swap(u, v);
    for(int i = 22;i>=0;--i) {
        if(dep[f[u][i]] >= dep[v]) u = f[u][i];
        if(u == v) return u;
    }
    for(int i = 22;i>=0;--i) {
        if(f[u][i] != f[v][i]) {
            u = f[u][i];
            v = f[v][i];
        }
    }
    return f[u][0];
}

void setAns(int u, int v, int goal) {
    set<int> edges;
    while(u != goal) {
        if(!ans[gofa[u]])
            edges.insert(gofa[u]);
        u = f[u][0];
    }
    while(v != goal) {
        if(!ans[gofa[v]])
            edges.insert(gofa[v]);
        v = f[v][0];
    }
    for(auto& x : edges) ans[x] = ++tot;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    // clock_t tStart = clock();
    cin>>n>>m;
    for(int i = 1;i<=m;++i) {
        int u, v;
        cin>>u>>v;
        e.pb({u, v, i - 1});
    }
    for(int i = 1;i<n;++i) {
        int x; cin>>x;
        r.pb(x - 1);
        int& u = e[x - 1].u;
        int& v = e[x - 1].v;
        root = u;
        findID[mp(min(u, v), max(u, v))] = e[x - 1].id;
        mst[u].pb(v);
        mst[v].pb(u);
        isr[x - 1] = 1;
    }
    dfs(root, 0);
    for(int i = 0;i<m;++i) {
        if(ans[i]) continue;
        if(isr[i]) {
            ans[i] = ++tot;
            continue;
        }
        int& u = e[i].u;
        int& v = e[i].v;
        if(vis.count(mp(min(u, v), max(u, v)))) {
            vis.insert(mp(min(u, v), max(u, v)));
            ans[i] = ++tot;
        }
        else {
            int lca = LCA(u, v);
            setAns(u, v, lca);
            ans[i] = ++tot;
        }
    }
    for(int i = 0;i<m - 1;++i) cout<<ans[i]<<' ';
    cout<<ans[m - 1]<<'\n';
    // cout<<(double)(clock() - tStart)/CLOCKS_PER_SEC<<'\n';
    return 0;
}
