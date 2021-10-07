#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 2e5 + 10;
using ll = long long;
int n, q;
vector<int> e[N];

struct fenwick {
    ll c[N];
    int lowbit(int i) {return i & (-i);}

    void update(int a, int b) {
        for(int i = a;i<=n;i+=lowbit(i)) c[i] += b;
    }
    ll query(int a) {
        ll ans = 0;
        for(int i = a;i;i-=lowbit(i)) ans += c[i];
        return ans;
    }
    ll query(int a, int b) {
        return query(b) - query(a - 1);
    }
};

struct HLD {
    int top[N], dfn[N], rnk[N], dep[N], siz[N], fa[N], hson[N], safe[N], tot;
    fenwick fen;
    void dfs1(int u, int f) {
        dep[u] = dep[f] + 1;
        fa[u] = f;
        siz[u] = 1;
        for(int v : e[u]) {
            if(v == f) continue;
            dfs1(v, u);
            siz[u] += siz[v];
            if(siz[hson[u]] <= siz[v]) hson[u] = v;
        }
    }
    void dfs2(int u, int f, int tp) {
        top[u] = tp;
        dfn[u] = ++tot;
        rnk[tot] = u;
        if(hson[u] == 0) return;
        dfs2(hson[u], u, tp);
        for(int v : e[u]) {
            if(v == f || v == hson[u]) continue;
            dfs2(v, u, v);
        }
    }
    int LCA(int u, int v) {
        while(top[u] != top[v]) {
            if(dep[top[u]] < dep[top[v]]) swap(u, v);
            u = fa[top[u]];
        }
        return dep[u] > dep[v] ? v : u;
    }
    void update(int u) {
        if(u != 1) {
            if(safe[u]) fen.update(dfn[fa[u]], -1);
            else fen.update(dfn[fa[u]], 1);
        }
        safe[u] ^= 1;
    }
    ll query(int u, int v) {
        ll ans = 0;
        while(top[u] != top[v]) {
            if(dep[top[u]] < dep[top[v]]) swap(u, v);
            ans += fen.query(dfn[top[u]], dfn[u]);
            u = fa[top[u]];
        }
        return ans + fen.query(min(dfn[u], dfn[v]), max(dfn[u], dfn[v]));
    }
    ll actualquery(int u, int v) {
        int lca = LCA(u, v);
        return query(lca, u) + query(lca, v) - query(lca, lca) + safe[lca] + safe[fa[lca]];
    }
} hld;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
#endif
    cin>>n>>q;
    for(int i = 1;i<n;++i) {
        int u, v;
        cin>>u>>v;
        e[u].pb(v);
        e[v].pb(u);
    }
    hld.dfs1(1, 0);
    hld.dfs2(1, 0, 1);
    while(q--) {
        int opt, u, v;
        cin>>opt;
        if(opt == 1) {
            cin>>u;
            hld.update(u);
        } else {
            cin>>u>>v;
            cout<<hld.actualquery(u, v)<<'\n';
        }
    }
    return 0;
}
