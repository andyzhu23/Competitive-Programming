#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ins insert
#define all(v) v.begin(), v.end()
using pii = pair<int, int>;
const int N = 5e5 + 5;
const int inf = 0x3f3f3f3f;

int n, f[N];

int Find(int x) {return f[x] == x ? x : f[x] = Find(f[x]);}
bool merge(int u, int v) {
    int fu = Find(u);
    int fv = Find(v);
    if(fu == fv) return 0;
    f[fu] = fv;
    return 1;
}

struct coor {
    int x, y, id;
} A[N];
vector<coor> a;

struct node {
    int val, id;
    bool operator<(const node& other) const {
        return val < other.val;
    }
};

struct edge {
    int u, v;
    bool operator<(const edge& o) const {
        return abs(A[u].x - A[v].x) + abs(A[u].y - A[v].y) <
            abs(A[o.u].x - A[o.v].x) + abs(A[o.u].y - A[o.v].y);
    }
};
vector<edge> e;

struct segtree {
    node st[N << 2];
#define lc (rt << 1)
#define rc (rt << 1 | 1)
    void build(int rt, int l, int r) {
        if(l == r) {
            st[rt] = {inf, 0};
            return;
        }
        int mid = l + r >> 1;
        build(lc, l, mid);
        build(rc, mid + 1, r);
        st[rt] = min(st[lc], st[rc]);
    }
    void update(int rt, int l, int r, int pos, node val) {
        if(l == r) {
            st[rt] = min(st[rt], val);
            return;
        }
        int mid = l + r >> 1;
        if(pos <= mid) update(lc, l, mid, pos, val);
        else update(rc, mid + 1, r, pos, val);
        st[rt] = min(st[lc], st[rc]);
    }
    node query(int rt, int l, int r, int x, int y) {
        if(x > y) return {inf, 0};
        if(l == x && y == r) return st[rt];
        int mid = l + r >> 1;
        if(y <= mid) return query(lc, l, mid, x, y);
        else if(x > mid) return query(rc, mid + 1, r, x, y);
        else return min(query(lc, l, mid, x, mid), query(rc, mid + 1, r, mid + 1, y));
    }
} st;

void solve() {
    set<int> b;
    map<int, int> mp;
    int tot = 0;
    st.build(1, 1, n);
    for(auto[x, y, id] : a) b.ins(y - x);
    for(auto x : b) mp[x] = ++tot;
    for(int i = a.size() - 1;~i;--i) {
        auto[x, y, id] = a[i];
        node nd = st.query(1, 1, n, mp[y - x], n);
        if(nd.id) e.pb({id, nd.id});
        st.update(1, 1, n, mp[y - x], (node){x + y, id});
    }
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    for(int i = 1;i<=n;++i) {
        int x, y;
        cin>>x>>y;
        A[i] = {x, y, i};
        a.pb({x, y, i});
    }
    for(int i = 1;i<=4;++i) {
        if(i & 1 ^ 1) for(auto&[x, y, id] : a) swap(x, y);
        if(i == 3) for(auto&[x, y, id] : a) x = -x;
        sort(all(a), [&](const coor& a, const coor& b) {
            return a.x == b.x ? a.y < b.y : a.x < b.x;
        });
        solve();
    }
    int ans = 0;
    iota(f, f + n + 1, 0);
    sort(all(e));
    for(auto[u, v] : e) if(merge(u, v)) {
        ans += abs(A[u].x - A[v].x) + abs(A[u].y - A[v].y);
    }
    cout<<ans<<'\n';
    return 0;
}
