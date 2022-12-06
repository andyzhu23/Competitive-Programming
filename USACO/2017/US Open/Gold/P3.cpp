#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define lc (rt << 1)
#define rc (rt << 1 | 1)

const int N = 1e5 + 5;
const int inf = 0x3f3f3f3f;
int n, a[N], mx[N], mn[N], m, ans;

int nxt[N], last[N];
bitset<N> vis;

bool ok() {
    for(int i = 1;i<n;++i) nxt[i] = i + 1;
    bool flag = 1;
    for(int i = 1;i<=n;++i) {
        flag &= !vis[a[i]];
        if(last[a[i]]) {
            for(int j = nxt[last[a[i]]];j<i;j=nxt[j]) vis[a[j]] = 1;
            nxt[last[a[i]]] = i;
        }
        last[a[i]] = i;
    }
    vis.reset();
    return flag;
}


struct node {
    int l, r, id, pos;
    bool operator<(const node& other) const {
        return r < other.r;
    }
} b[N];

vector<vector<node> > e;

template <typename T> 
struct segtree {
    T st[N << 2];
    void build(int rt, int l, int r, T a[N]) {
        if(l == r) {
            st[rt] = a[l];
            return;
        }
        int mid = l + r >> 1;
        build(lc, l, mid, a);
        build(rc, mid + 1, r, a);
        st[rt] = min(st[lc], st[rc]);
    }
    void update(int rt, int l, int r, int pos, T val) {
        if(l == r) {
            st[rt] = val;
            return;
        }
        int mid = l + r >> 1;
        if(pos <= mid) update(lc, l, mid, pos, val);
        else update(rc, mid + 1, r, pos, val);
        st[rt] = min(st[lc], st[rc]);
    }
    T query(int rt, int l, int r, int x, int y) {
        if(l == x && y == r) return st[rt];
        int mid = l + r >> 1;
        if(y <= mid) return query(lc, l, mid, x, y);
        else if(x > mid) return query(rc, mid + 1, r, x, y);
        else return min(query(lc, l, mid, x, mid), query(rc, mid + 1, r, mid + 1, y));
    }
};

segtree<node> st;

bool cmp(node& a, node& b) {
    return a.l < b.l;
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("art2.in", "r", stdin);
    freopen("art2.out", "w", stdout);
#endif
    cin>>n;
    memset(mn, 0x3f, sizeof mn);
    for(int i = 1;i<=n;++i) {
        cin>>a[i];
        mx[a[i]] = max(mx[a[i]], i);
        mn[a[i]] = min(mn[a[i]], i);
    }
    if(!ok()) {
        cout<<-1<<'\n';
        return 0;
    }
    for(int i = 1;i<=n;++i) {
        if(a[i] && mx[a[i]] && !vis[a[i]]) {
            b[++m] = {mn[a[i]], mx[a[i]], a[i]};
            vis[a[i]] = 1;
        }
    }
    sort(b + 1, b + m + 1, cmp);
    for(int i = 1;i<=m;++i) b[i].pos = i;
    st.build(1, 1, m, b);
    int cnt = m;
    e.pb(vector<node>());
    int r = 0;
    while(cnt) {
        int lo = 1, hi = m, ret = -1;
        while(lo <= hi) {
            int mid = lo + hi >> 1;
            if(b[mid].l > r) hi = mid - 1, ret = mid;
            else lo = mid + 1;
        }
        if(ret == -1) {
            r = 0;
            ++ans;
            e.pb(vector<node>());
            continue;
        }
        node x = st.query(1, 1, m, ret, m);
        if(x.r == inf) {
            r = 0;
            ++ans;
            e.pb(vector<node>());
            continue;
        }
        --cnt;
        e[ans].pb(x);
        r = x.r;
        x.r = inf;
        st.update(1, 1, m, x.pos, x);
    }
    ++ans;
    cout<<ans<<'\n';
    return 0;
}
