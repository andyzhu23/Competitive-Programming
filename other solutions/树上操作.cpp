#include <bits/stdc++.h>
using namespace std;
#define pb push_back
using ll = long long;
const int N = 1e5 + 10;

vector<int> e[N];
int w[N], n;

struct segtree {
    ll st[N << 2], lazy[N << 2];
#define lc (rt << 1)
#define rc (rt << 1 | 1)
    void push_up(int rt) {
        st[rt] = st[lc] + st[rc];
    }
    void push_down(int rt, int l, int r, int mid) {
        lazy[lc] += lazy[rt];
        lazy[rc] += lazy[rt];
        st[lc] += (mid - l + 1) * lazy[rt];
        st[rc] += (r - mid) * lazy[rt];
        lazy[rt] = 0;
    }
    void build(int rt, int l, int r) {
        if(l == r) {
            cin>>st[rt];
            return;
        }
        int mid = (l + r) >> 1;
        build(lc, l, mid);
        build(rc, mid + 1, r);
        push_up(rt);
    }
    void update(int rt, int l, int r, int x, int y, ll val) {
        if(l == x && y == r) {
            st[rt] += (r - l + 1) * val;
            lazy[rt] += val;
            return;
        }
        int mid = (l + r) >> 1;
        push_down(rt, l, r, mid);
        if(y <= mid) update(lc, l, mid, x, y, val);
        else if(x > mid) update(rc, mid + 1, r, x, y, val);
        else update(lc, l, mid, x, mid, val), update(rc, mid + 1, r, mid + 1, y, val);
        push_up(rt);
    }
    ll query(int rt, int l, int r, int x, int y) {
        if(l == x && y == r) return st[rt];
        int mid = (l + r) >> 1;
        push_down(rt, l, r, mid);
        if(y <= mid) return query(lc, l, mid, x, y);
        else if(x > mid) return query(rc, mid + 1, r, x, y);
        else return query(lc, l, mid, x, mid) + query(rc, mid + 1, r, mid + 1, y);
    }
};

struct HLD {
    segtree st;
    int dep[N], fa[N], siz[N], hson[N], dfn[N], rnk[N], top[N], tot;
    void dfs1(int u, int f) {
        dep[u] = dep[f] + 1;
        fa[u] = f;
        siz[u] = 1;
        for(int v : e[u]) {
            if(v == f) continue;
            dfs1(v, u);
            siz[u] += siz[v];
            if(siz[hson[u]] < siz[v]) hson[u] = v;
        }
    }
    void dfs2(int u, int f, int tp) {
        top[u] = tp;
        dfn[u] = ++tot;
        rnk[tot] = u;
        st.update(1, 1, n, dfn[u], dfn[u], w[u]);
        if(hson[u] == 0) return;
        dfs2(hson[u], u, tp);
        for(int v : e[u]) {
            if(v == f || v == hson[u]) continue;
            dfs2(v, u, v);
        }
    }
    void update1(int u, ll val) {
        st.update(1, 1, tot, dfn[u], dfn[u], val);
    }
    void update2(int u, ll val) {
        st.update(1, 1, tot, dfn[u], dfn[u] + siz[u] - 1, val);
    }
    ll query(int u, int v) {
        ll ans = 0;
        while(top[u] != top[v]) {
            if(dep[top[u]] < dep[top[v]]) swap(u, v);
            ans += st.query(1, 1, tot, dfn[top[u]], dfn[u]);
            u = fa[top[u]];
        }
        ans += st.query(1, 1, tot, min(dfn[u], dfn[v]), max(dfn[u], dfn[v]));
        return ans;
    }
} hld;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    int m;
    cin>>n>>m;
    for(int i = 1;i<=n;++i) cin>>w[i];
    for(int i = 1;i<n;++i) {
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }
    hld.dfs1(1, 0);
    hld.dfs2(1, 0, 1);
    while(m--) {
        ll opt, x, a;
        cin>>opt;
        switch (opt) {
            case 1:
                cin>>x>>a;
                hld.update1(x, a);
                break;
            case 2:
                cin>>x>>a;
                hld.update2(x, a);
                break;
            case 3:
                cin>>x;
                cout<<hld.query(1, x)<<'\n';
                break;
        }
    }
    return 0;
}