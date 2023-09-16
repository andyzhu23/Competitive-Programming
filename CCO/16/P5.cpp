#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 0x3f3f3f3f;
const int N = 1e4 + 5;
int n, m, k, rnk[N];

struct node {
    int r, c;
    bool operator<(const node& o) const {
        return r < o.r;
    }
} a[N];

map<int, int> mp;
map<int, vector<pair<int, int> > > b;
int tot;

struct segtree {
    int st[N << 2], lazy[N << 2];
#define lc (rt << 1)
#define rc (rt << 1 | 1)
    inline void upd(int rt, int l, int r, int x, int y, int val) {
        if(l == x && y == r) {
            lazy[rt] += val;
            if(lazy[rt]) st[rt] = rnk[r] - rnk[l - 1];
            else st[rt] = st[lc] + st[rc];
            return;
        }
        int mid = (l + r) >> 1;
        if(y <= mid) upd(lc, l, mid, x, y, val);
        else if(x > mid) upd(rc, mid + 1, r, x, y, val);
        else upd(lc, l, mid, x, mid, val), upd(rc, mid + 1, r, mid + 1, y, val);
        if(lazy[rt]) st[rt] = rnk[r] - rnk[l - 1];
        else st[rt] = st[lc] + st[rc];
    }
    inline int query(int rt, int l, int r, int x, int y) {
        if(l == x && y == r) return st[rt];
        int mid = (l + r) >> 1;
        if(y <= mid) return query(lc, l, mid, x, y);
        else if(x > mid) return query(rc, mid + 1, r, x, y);
        else return query(lc, l, mid, x, mid) + query(rc, mid + 1, r, mid + 1, y);
    }
    inline void clear() {
        memset(st, 0, sizeof st);
        memset(lazy, 0, sizeof lazy);
    }
} st;
set<int> dis;

inline ll solve(int q) {
    for(int i = 1;i<=k;++i) {
        dis.insert(max(1, a[i].c - q));
        dis.insert(min(m, a[i].c + q));
        dis.insert(max(1, a[i].c - q - 1));
        b[max(1, a[i].r - q)].push_back({a[i].c, 1});
        b[min(n, a[i].r + q) + 1].push_back({a[i].c, -1});
    }
    for(auto x : dis) mp[x] = ++tot, rnk[tot] = x;
    dis.clear();
    sort(a + 1, a + k + 1);
    ll ans = 0;
    b[n + q + 1];
    for(auto[u, v] : b) if(u < n + q + 1) {
        for(auto[x, y] : v) {
            int l = mp[max(1, x - q)];
            int r = mp[min(m, x + q)];
            st.upd(1, 1, tot, l, r, y);
        }
        ans += 1ll * st.query(1, 1, tot, 1, tot) * ((*b.upper_bound(u)).first - u);
    }
    tot = 0;
    mp.clear();
    b.clear();
    return ans;
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>m>>k;
    for(int i = 1;i<=k;++i) {
        cin>>a[i].r>>a[i].c;
    }
    int q; cin>>q;
    cout<<solve(q) - solve(q - 1)<<'\n';
    return 0;
}
