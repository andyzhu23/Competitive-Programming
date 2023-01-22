using ll = long long;
#define lc (rt << 1)
#define rc (rt << 1 | 1)
const int N = 1e5 + 5;
struct segtree {
    ll st[N << 2], lazy[N << 2];
    int n;
    void push_down(int rt, int l, int r, int mid) {
      st[rt << 1] += lazy[rt];
      st[rt << 1 | 1] += lazy[rt];
      lazy[rt << 1] += lazy[rt];
      lazy[rt << 1 | 1] += lazy[rt];
      lazy[rt] = 0;
    }
    void update(ll rt, ll l, ll r, ll x, ll y, ll val){
      if(l == x && y == r){
        lazy[rt] += val;
        st[rt] += val;
        return;
      }
      ll mid = (l + r) >> 1;
      push_down(rt, l, r, mid);
      if(y <= mid) update(rt << 1, l, mid, x, y, val);
      else if(x > mid) update(rt << 1 | 1, mid + 1, r , x, y, val);
      else update(rt << 1, l, mid, x, mid, val), update(rt << 1 | 1, mid + 1, r, mid + 1, y, val);
        st[rt] = max(st[lc], st[rc]);
    }
    ll query(ll rt, ll l, ll r, ll x, ll y){
      if(l == x && y == r){
        return st[rt];
      }
      ll mid = (l + r ) >> 1;
      push_down(rt, l, r, mid);
      if(y <= mid) return query(rt << 1, l, mid, x, y);
      else if( x > mid) return query(rt << 1 | 1, mid + 1, r, x, y);
      else return max(query(rt << 1, l, mid, x, mid), query(rt << 1 | 1, mid + 1, r, mid + 1, y));
    }
};

class Solution {
public:
    vector<vector<int> > e;
    vector<ll> a, dist;
    int tot = 0, N;
    vector<int> dfn, sz;
    segtree st;
    ll ans = 0;
    void dfs(int u = 0, int fa = -1) {
        dist[u] += a[u];
        dfn[u] = ++tot;
        sz[u] = 1;
        for(int v : e[u]) if(v != fa) {
            dist[v] += dist[u];
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
    void dfs2(int u = 0, int fa = -1) {
        int n = N;
        ans = max(ans, st.query(1, 1, n, 1, n));
        for(int v : e[u]) if(v != fa) {
            st.update(1, 1, n, dfn[v], dfn[v] + sz[v] - 1, - a[u] - a[v]);
            st.update(1, 1, n, 1, n, a[u]);
            dfs2(v, u);
            st.update(1, 1, n, dfn[v], dfn[v] + sz[v] - 1, a[u] + a[v]);
            st.update(1, 1, n, 1, n, - a[u]);
        }
    }
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        e.resize(n);
        N = n;
        tot = 0;
        for(auto x : edges) {
            e[x[0]].push_back(x[1]);
            e[x[1]].push_back(x[0]);
        }
        a.resize(n);
        dist.resize(n);
        dfn.resize(n);
        sz.resize(n);
        for(int i = 0;i<n;++i) a[i] = price[i];
        dfs();
        ans = 0;
        for(int i = 0;i<n;++i) st.update(1, 1, n, dfn[i], dfn[i], dist[i]);
        st.update(1, 1, n, 1, n, -a[0]);
        dfs2(0, -1);
        ll mx = 0;
        return max(mx, ans);
    }
};
