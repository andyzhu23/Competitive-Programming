#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 1e5 + 5;
vector<int> e[N];

struct DSU {
    int f[N], n;
    DSU(int n) :n(n) {
        iota(f, f + n + 1, 0);
    }
    int Find(int x) {return f[x] == x ? x : f[x] = Find(f[x]);}
    void merge(int u, int v) {
        int fu = Find(u);
        int fv = Find(v);
        f[fu] = fv;
    }
    bool same(int u, int v) {
        int fu = Find(u);
        int fv = Find(v);
        return fu == fv;
    }
};

int f[N][22], dep[N];

void dfs(int u = 1, int fa = 0) {
    f[u][0] = fa;
    dep[u] = dep[fa] + 1;
    for(int i = 1;i<22;++i) {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }
    for(int v : e[u]) {
        if(v == fa) continue;
        dfs(v, u);
    }
}

int LCA(int u, int v) {
    if(dep[u] < dep[v]) swap(u, v);
    for(int i = 21;i>=0;--i) {
        if(dep[f[u][i]] >= dep[v]) {
            u = f[u][i];
        }
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

int n, q;

set<pair<int, int> > vis;

struct query {
    int opt, u, v, ans;
} qs[N << 1];

int res[N];

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>q;
    DSU dsu(n);
    for(int i = 1;i<n;++i) {
        int u, v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
        vis.insert({min(u, v), max(u, v)});
    }
    dfs();
    for(int i = 1;i<=q;++i) {
        int opt, u, v, ans;
        cin>>opt>>u>>v;
        if(opt == 1) {
            ans = dep[u] + dep[v] - 2 * dep[LCA(u, v)];
        } else {
            vis.erase({min(u, v), max(u, v)});
        }
        qs[i] = {opt, u, v, ans};
    }
    for(auto[u, v] : vis) dsu.merge(u, v);
    deque<int> dq;
    for(int i = q;i;--i) {
        auto[opt, u, v, ans] = qs[i];
        if(opt == 2) {
            dsu.merge(u, v);
        } else {
            if(dsu.same(u, v)) dq.push_front(ans);
            else dq.push_front(-1);
        }
    }
    for(auto x : dq) cout<<x<<'\n';
    return 0;
}