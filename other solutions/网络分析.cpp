#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
#define pb push_back
int n, m;

struct DSU {
    vi f, f2, val, vis, dp;
    int n;
    DSU(int n) :n(n) {
        for(int i = 0;i<=n;i++) {
            f.pb(i);
            f2.pb(i);
            val.pb(0);
            vis.pb(0);
            dp.pb(0);
        }
    }
    int Find(int x) {return f[x] == x ? x : f[x] = Find(f[x]);}
    bool merge(int u, int v) {
        int fu = Find(u);
        int fv = Find(v);
        if(fu == fv) return 0;
        f.pb(++n);
        f2.pb(n);
        val.pb(0);
        dp.pb(0);
        vis.pb(0);
        f2[Find(fu)] = f2[Find(fv)] = n;
        f[fu] = f[fv] = n;
        return 1;
    }

    int dfs(int u) {
        if(f2[u] == u) return val[u];
        if(!vis[f2[u]]) {
            vis[f2[u]] = 1;
            dp[f2[u]] = dfs(f2[u]);
        }
        return val[u] + dp[f2[u]];
    }

};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    DSU dsu(n + 1);
    for(int i = 1;i<=m;i++) {
        int opt, a, b;
        cin>>opt>>a>>b;
        if(opt == 1) dsu.merge(a, b);
        else dsu.val[dsu.Find(a)] += b;
    }
    for(int i = 1;i<n;i++)
        cout<<dsu.dfs(i)<<' ';
    cout<<dsu.dfs(n)<<'\n';
    return 0;
}
