#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 1e5 + 10;
vector<int> e[N];
int n, q;
struct node {
    int l, r, val;
    node operator+ (const node& other) const {
        if(l == 0 || r == 0 || val == 0) return other;
        if(other.l == 0 || other.r == 0 || other.val == 0) return {l, r, val};
        node ans;
        ans.l = l;
        ans.r = other.r;
        ans.val = val + other.val - (r == other.l);
        return ans;
    }
};
struct segtree {
    node st[N << 2];
    int lazy[N << 2] = {-1};
#define lc (rt << 1)
#define rc (rt << 1 | 1)
    inline void push_up(int rt) {
        st[rt] = st[lc] + st[rc];
    }
    inline void push_down(int rt) {
        if(lazy[rt] != -1) {
            st[lc] = st[rc] = st[rt];
            lazy[lc] = lazy[rc] = lazy[rt];
        }
        lazy[rt] = -1;
    }
    inline void build(int rt, int l, int r) {
        if(l == r) {
            cin>>st[rt].r;
            st[rt].l = st[rt].r;
            st[rt].val = 1;
            return;
        }
        int mid = (l + r) >> 1;
        build(lc, l, mid);
        build(rc, mid + 1, r);
        push_up(rt);
    }
    inline void update(int rt, int l, int r, int x, int y, int val) {
        if(l == x && y == r) {
            st[rt].l = st[rt].r = val;
            lazy[rt] = val;
            st[rt].val = 1;
            return;
        }
        int mid = (l + r) >> 1;
        push_down(rt);
        if(y <= mid) update(lc, l, mid, x, y, val);
        else if(x > mid) update(rc, mid + 1, r, x, y, val);
        else update(lc, l, mid, x, mid, val), update(rc, mid + 1, r, mid + 1, y, val);
        push_up(rt);
    }
    inline node query(int rt, int l, int r, int x, int y) {
        if(l == x && y == r) return st[rt];
        int mid = (l + r) >> 1;
        push_down(rt);
        if(y <= mid) return query(lc, l, mid, x, y);
        else if(x > mid) return query(rc, mid + 1, r, x, y);
        else return query(lc, l, mid, x, mid) + query(rc, mid + 1, r, mid + 1, y);
    }
};

struct HLD {
    int dfn[N], rnk[N], top[N], dep[N], fa[N], siz[N], hson[N], tot;
    segtree st;
    inline void init(int n) {
        tot = 0;
        for(int i = 0;i<=n;++i) {
            dfn[i] = rnk[i] = top[i] = dep[i] = fa[i] = siz[i] = hson[i] = tot;
            e[i].clear();
        }
    }
    inline void dfs1(int u, int f) {
        dep[u] = dep[f] + 1;
        siz[u] = 1;
        fa[u] = f;
        for(int v : e[u]) {
            if(v == f) continue;
            dfs1(v, u);
            siz[u] += siz[v];
            if(siz[hson[u]] <= siz[v]) hson[u] = v;
        }
    }
    inline void dfs2(int u, int f, int tp) {
        top[u] = tp;
        dfn[u] = ++tot;
        rnk[tot] = u;
        st.update(1, 1, n, tot, tot, tot);
        if(hson[u] == 0) return;
        dfs2(hson[u], u, tp);
        for(int v : e[u]) {
            if(v == f || v == hson[u]) continue;
            dfs2(v, u, v);
        }
    }
    inline void update(int u, int v, int val) {
        while(top[u] != top[v]) {
            if(dep[top[u]] < dep[top[v]]) swap(u, v);
            st.update(1, 1, tot, dfn[top[u]], dfn[u], val);
            u = fa[top[u]];
        }
        st.update(1, 1, tot, min(dfn[u], dfn[v]), max(dfn[u], dfn[v]), val);
    }
    inline int query(int u, int v) {
        if(u == v) return 0;
        int cnt = 0;
        node ansu = {0, 0, 0}, ansv = {0, 0, 0};
        while(top[u] != top[v]) {
            if(dep[top[u]] < dep[top[v]]) {
                ansv = st.query(1, 1, tot, dfn[top[v]], dfn[v]) + ansv;
                cnt += dfn[v] - dfn[top[v]] + 1;
                v = fa[top[v]];
            } else {
                ansu = st.query(1, 1, tot, dfn[top[u]], dfn[u]) + ansu;
                cnt += dfn[u] - dfn[top[u]] + 1;
                u = fa[top[u]];
            }
        }
        node tmp = {0, 0, 0};
        tmp = st.query(1, 1, tot, min(dfn[u], dfn[v]), max(dfn[u], dfn[v]));
        node Min = dfn[u] > dfn[v] ? ansv : ansu;
        node Max = dfn[u] > dfn[v] ? ansu : ansv;
        swap(Min.l, Min.r);
        node res = Min + tmp + Max;
        cnt += max(dfn[u], dfn[v]) - min(dfn[u], dfn[v]) + 1;
        return cnt - res.val;
    }
} hld;


inline void solve() {
    cin>>n>>q;
    int tot = n;
    hld.init(n);
    for(int i = 1;i<n;++i) {
        int u, v;
        cin>>u>>v;
        e[u].pb(v);
        e[v].pb(u);
    }
    hld.dfs1(1, 0);
    hld.dfs2(1, 0, 1);
    while(q--) {
        int c;
        int a, b;
        cin>>c;
        switch(c) {
        case 2:
            cin>>a>>b;
            cout<<hld.query(a, b)<<'\n';
            break;
        case 1:
            cin>>a>>b;
            hld.update(a, b, ++tot);
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
   freopen(".in", "r", stdin);
   freopen(".out", "w", stdout);
#endif
    int t; cin>>t;
    while(t--) solve();
}
