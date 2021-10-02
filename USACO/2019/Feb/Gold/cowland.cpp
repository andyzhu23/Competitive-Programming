#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
#define pb push_back
int n, w[N]; 
vector<int> e[N];

struct segtree {
    #define lc (rt << 1)
    #define rc (rt << 1 | 1)
    int st[N << 2];
    void update(int rt, int l, int r, int pos, int val) {
        if(l == r) {
            st[rt] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if(pos <= mid) update(lc, l, mid, pos, val);
        else update(rc, mid + 1, r, pos, val);
        st[rt] = st[lc] ^ st[rc];
    }
    int query(int rt, int l, int r, int x, int y) {
        if(l == x && y == r) return st[rt];
        int mid = (l + r) >> 1;
        if(y <= mid) return query(lc, l, mid, x, y);
        else if(x > mid) return query(rc, mid + 1, r, x, y);
        else return query(lc, l, mid, x, mid) ^ query(rc, mid + 1, r, mid + 1, y);
    }

} st;

struct HLD {
    int dep[N], fa[N], hson[N], siz[N], dfn[N], rnk[N], top[N], tot;

    void dfs1(int u, int f) {
        fa[u] = f;
        dep[u] = dep[f] + 1;
        siz[u] = 1;
        for(int v : e[u]) {
            if(v == f) continue;
            dfs1(v, u);
            if(siz[hson[u]] <= siz[v]) hson[u] = v;
            siz[u] += siz[v];
        }
    }

    void dfs2(int u, int f, int tp) {
        top[u] = tp;
        dfn[u] = ++tot;
        rnk[tot] = u;
        st.update(1, 1, n, tot, w[u]);
        if(hson[u] == 0) return;
        dfs2(hson[u], u, tp);
        for(int v : e[u]) {
            if(f == v || v == hson[u]) continue;
            dfs2(v, u, v);
        }
    }

    int query(int u, int v) {
        int ans = 0;
        while(top[u] != top[v]) {
            if(dep[top[u]] < dep[top[v]]) swap(u, v);
            ans ^= st.query(1, 1, n, dfn[top[u]], dfn[u]);
            u = fa[top[u]];
        }
        return ans ^ st.query(1, 1, n, min(dfn[u], dfn[v]), max(dfn[u], dfn[v]));
    }

    void update(int u, int val) {
        w[u] = val;
        st.update(1, 1, n, dfn[u], val);
    }

} hld;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("cowland.in", "r", stdin);
    freopen("cowland.out", "w", stdout);
    int q;
    cin>>n>>q;
    for(int i = 1;i<=n;++i) cin>>w[i];
    for(int i = 1;i<n;++i) {
        int u, v;
        cin>>u>>v;
        e[u].pb(v);
        e[v].pb(u);
    }
    hld.dfs1(1, 0);
    hld.dfs2(1, 0, 1);
    while(q--) {
        int opt, i, j;
        cin>>opt>>i>>j;
        if(opt == 1) hld.update(i, j);
        else cout<<hld.query(i, j)<<'\n';
    }
    return 0;
}
