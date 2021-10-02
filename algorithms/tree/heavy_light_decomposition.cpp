#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 3e4 + 10;
const int INF = 0x3f3f3f3f;
vector<int> e[N];
int n;

template <typename T>
struct segtree {
    T sum[N << 2], Max[N << 2];
    #define lc (rt << 1)
    #define rc (rt << 1 | 1)
    void update(int rt, int l, int r, int pos, T val) {
        if(l == r) {
            sum[rt] = Max[rt] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if(pos <= mid) update(lc, l, mid, pos, val);
        else update(rc, mid + 1, r, pos, val);
        sum[rt] = sum[lc] + sum[rc];
        Max[rt] = max(Max[lc], Max[rc]);
    }
    T querySum(int rt, int l, int r, int x, int y) {
        if(l == x && y == r) return sum[rt];
        int mid = (l + r) >> 1;
        if(y <= mid) return querySum(lc, l, mid, x, y);
        else if(x > mid) return querySum(rc, mid + 1, r, x, y);
        else return querySum(lc, l, mid, x, mid) + querySum(rc, mid + 1, r, mid + 1, y);
    }
    T queryMax(int rt, int l, int r, int x, int y) {
        if(l == x && y == r) return Max[rt];
        int mid = (l + r) >> 1;
        if(y <= mid) return queryMax(lc, l, mid, x, y);
        else if(x > mid) return queryMax(rc, mid + 1, r, x, y);
        else return max(queryMax(lc, l, mid, x, mid), queryMax(rc, mid + 1, r, mid + 1, y));
    }
};

struct HLD {
    using ll = long long;
    int top[N], siz[N], dfn[N], rnk[N], hson[N], dep[N], w[N], f[N];
    int tot;
    segtree<ll> st;
    void dfs1(int u, int fa) {
        f[u] = fa;
        dep[u] = dep[fa] + 1;
        siz[u] = 1;
        for(int v : e[u]) {
            if(v == fa) continue;
            dfs1(v, u);
            siz[u] += siz[v];
            if(siz[hson[u]] <= siz[v]) hson[u] = v;
        }
    }
    void dfs2(int u, int fa, int tp) {
        dfn[u] = ++tot;
        rnk[tot] = u;
        st.update(1, 1, n, tot, w[u]);
        top[u] = tp;
        if(hson[u] == 0) return;
        dfs2(hson[u], u, tp);
        for(int v : e[u]) {
            if(v == fa || v == hson[u]) continue;
            dfs2(v, u, v);
        }
    }
    void update(int pos, int val) {
        w[pos] = val;
        pos = dfn[pos];
        st.update(1, 1, n, pos, val);
    }
    ll querySum(int u, int v) {
        ll ans = 0;
        while(top[u] != top[v]) {
            if(dep[top[u]] < dep[top[v]]) swap(u, v);
            ans += st.querySum(1, 1, n, dfn[top[u]], dfn[u]);
            u = f[top[u]];
        }
        return ans + st.querySum(1, 1, n, min(dfn[u], dfn[v]), max(dfn[u], dfn[v]));
    }
    ll queryMax(int u, int v) {
        ll ans = -INF;
        while(top[u] != top[v]) {
            if(dep[top[u]] < dep[top[v]]) swap(u, v);
            ans = max(ans, st.queryMax(1, 1, n, dfn[top[u]], dfn[u]));
            u = f[top[u]];
        }
        return max(ans, st.queryMax(1, 1, n, min(dfn[u], dfn[v]), max(dfn[u], dfn[v])));
    }
} hld;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    cin>>n;
    for(int i = 1;i<n; ++i) {
        int u, v;
        cin>>u>>v;
        e[u].pb(v);
        e[v].pb(u);
    }
    for(int i = 1;i<=n;++i) {
        cin>>hld.w[i];
    }
    hld.dfs1(1, 0);
    hld.dfs2(1, 0, 1);
    int q; cin>>q;
    while(q--) {
        string s;
        int u, v;
        cin>>s>>u>>v;
        if(s == "QMAX") {
            cout<<hld.queryMax(u, v)<<'\n';
        } else if(s == "QSUM") {
            cout<<hld.querySum(u, v)<<'\n';
        } else if(s == "CHANGE") {
            hld.update(u, v);
        }
    }
    return 0;
}
