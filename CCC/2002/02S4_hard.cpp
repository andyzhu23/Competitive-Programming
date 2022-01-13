#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
using ll = long long;
int m, n, last[N], a[N];
string s[N];
vector<int> stk;

struct node {
    int pos; ll val, mx;
    bool operator<(const node& other) const {
        return val + mx < other.val + other.mx;
    }
};

struct node2 {
    int pos; ll val;
    bool operator<(const node2& other) const {
        return val < other.val;
    }
};

struct segtree {
    node st[N << 2];
    node2 mn[N << 2];
    ll lazy[N << 2];
#define lc (rt << 1)
#define rc (rt << 1 | 1)
    void push_up(int rt) {
        st[rt] = min(st[lc], st[rc]);
        mn[rt] = min(mn[lc], mn[rc]);
    }
    void push_down(int rt) {
        if(lazy[rt]) {
            lazy[lc] = lazy[rc] = lazy[rt];
            st[lc] = {mn[lc].pos, mn[lc].val, lazy[rt]};
            st[rc] = {mn[rc].pos, mn[rc].val, lazy[rt]};
            lazy[rt] = 0;
        }
    }
    void update(int rt, int l, int r, int x, int y, ll val) {
        if(l == x && y == r) {
            st[rt] = {mn[rt].pos, mn[rt].val, val};
            lazy[rt] = val;
            return;
        }
        int mid = l + r >> 1;
        push_down(rt);
        if(y <= mid) update(lc, l, mid, x, y, val);
        else if(x > mid) update(rc, mid + 1, r, x, y, val);
        else update(lc, l, mid, x, mid, val), update(rc, mid + 1, r, mid + 1, y, val);
        push_up(rt);
    }
    void update(int rt, int l, int r, int pos, ll val) {
        if(l == r) {
            st[rt] = {pos, val, st[rt].mx};
            mn[rt] = {pos, val};
            return;
        }
        int mid = l + r >> 1;
        push_down(rt);
        if(pos <= mid) update(lc, l, mid, pos, val);
        else update(rc, mid + 1, r, pos, val);
        push_up(rt);
    }
    node query(int rt, int l, int r, int x, int y) {
        if(l == x && y == r) return st[rt];
        int mid = l + r >> 1;
        push_down(rt);
        if(y <= mid) return query(lc, l, mid, x, y);
        else if(x > mid) return query(rc, mid + 1, r, x, y);
        else return min(query(lc, l, mid, x, mid), query(rc, mid + 1, r, mid + 1, y));
    }
} st;

void dfs(int u) {
    if(u == 0) return;
    dfs(last[u]);
    for(int i = last[u] + 1;i<u;++i) cout<<s[i]<<' ';
    cout<<s[u]<<'\n';
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>m>>n;
    for(int i = 1;i<=n;++i) {
        cin>>s[i];
        cin>>a[i];
    }
    node ans;
    for(int i = 1;i<=n;++i) {
        while(!stk.empty() && a[stk.back()] < a[i]) stk.pop_back();
        int mx = stk.empty() ? 0 : stk.back();
        st.update(1, 0, n, mx, i - 1, a[i]);
        ans = st.query(1, 0, n, max(i - m, 0), i - 1);
        int j = ans.pos;
        st.update(1, 0, n, i, ans.val + ans.mx);
        last[i] = j;
        stk.push_back(i);
    }
    cout<<"Total Time: "<<ans.val + ans.mx<<'\n';
    dfs(n);
    return 0;
}
