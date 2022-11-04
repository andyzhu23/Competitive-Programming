#include <bits/stdc++.h>
using namespace std;
#define pb push_back
using ll = long long;
const int N = 1e5 + 5;
vector<int> e[N];
int n, q, tot, dfn[N], sz[N];

struct segtree {
    ll st[N << 2], lazy[N << 2];
#define lc (rt << 1)
#define rc (rt << 1 | 1)
    void push_down(int rt, int l, int r, int mid) {
        st[lc] += (mid - l + 1) * lazy[rt];
        st[rc] += (r - mid) * lazy[rt];
        lazy[lc] += lazy[rt];
        lazy[rc] += lazy[rt];
        lazy[rt] = 0;
    }
    void update(int rt, int l, int r, int x, int y, int val) {
        if(l == x && y == r) {
            st[rt] += (r - l + 1) * val;
            lazy[rt] += val;
            return;
        }
        int mid = l + r >> 1;
        push_down(rt, l, r, mid);
        if(y <= mid) update(lc, l, mid, x, y, val);
        else if(x > mid) update(rc, mid + 1, r, x, y, val);
        else update(lc, l, mid, x, mid, val), update(rc, mid + 1, r, mid + 1, y, val);
        st[rt] = st[lc] + st[rc];
    }
    ll query(int rt, int l, int r, int x, int y) {
        if(l == x && y == r) return st[rt];
        int mid = l + r >> 1;
        push_down(rt, l, r, mid);
        if(y <= mid) return query(lc, l, mid, x, y);
        else if(x > mid) return query(rc, mid + 1, r, x, y);
        else return query(lc, l, mid, x, mid) + query(rc, mid + 1, r, mid + 1, y);
    }
} st;

void dfs(int u = 1, int fa = 0) {
    dfn[u] = ++tot;
    ++sz[u];
    for(int v : e[u]) if(v != fa) {
        dfs(v, u);
        sz[u] += sz[v];
    }
}

struct cmp {
    bool operator()(const int& a, const int& b) {
        return dfn[a] < dfn[b];
    }
};

unordered_map<int, set<int, cmp> > mp;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    freopen("snowcow.in", "r", stdin);
    freopen("snowcow.out", "w", stdout);
    cin>>n>>q;
    for(int i = 1;i<n;++i) {
        int u, v;
        cin>>u>>v;
        e[u].pb(v);
        e[v].pb(u);
    }
    dfs();
    while(q--) {
        int opt, x;
        cin>>opt>>x;
        if(opt == 1) {
            int c; cin>>c;
            auto& bst = mp[c];
            auto it = bst.upper_bound(x);
            if(it != bst.begin() && dfn[*prev(it)] + sz[*prev(it)] > dfn[x]) continue;
            st.update(1, 1, n, dfn[x], dfn[x] + sz[x] - 1, 1);
            while(it != bst.end() && dfn[x] + sz[x] > dfn[*it]) {
                st.update(1, 1, n, dfn[*it], dfn[*it] + sz[*it] - 1, -1);
                bst.erase(it++);
            }
            bst.insert(x);
        } else cout<<st.query(1, 1, n, dfn[x], dfn[x] + sz[x] - 1)<<'\n';
    }
    return 0;
}