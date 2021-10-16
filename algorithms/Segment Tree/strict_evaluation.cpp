#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

struct segtree {
    using ll = long long;
    ll st[N << 2], lazy1[N << 2], lazy2[N << 2];
    int tot1 = 0, tot2 = 0;
#define lc (rt << 1)
#define rc (rt << 1 | 1)
    void push_up(int rt) {
        st[rt] = min(st[lc], st[rc]);
    }
    void push_down(int rt) {
        if(lazy2[rt]) {
            lazy1[lc] = lazy1[rc] = 0;
            lazy2[lc] = lazy2[rc] = lazy2[rt];
            st[lc] = st[rc] = lazy2[rt];
        }
        if(lazy1[rt]) {
            lazy1[lc] += lazy1[rt];
            lazy1[rc] += lazy1[rt];
            st[lc] += lazy1[rt];
            st[rc] += lazy1[rt];
        }
        lazy1[rt] = lazy2[rt] = 0;
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
    void update1(int rt, int l, int r, int x, int y, int val) {
        if(l == x && y == r) {
            st[rt] += val;
            lazy1[rt] += val;
            return;
        }
        int mid = (l + r) >> 1;
        push_down(rt);
        if(y <= mid) update1(lc, l, mid, x, y, val);
        else if(x > mid) update1(rc, mid + 1, r, x, y, val);
        else update1(lc, l, mid, x, mid, val), update1(rc, mid + 1, r, mid + 1, y, val);
        push_up(rt);
    }
    void update2(int rt, int l, int r, int x, int y, int val) {
        if(l == x && y == r) {
            st[rt] = val;
            lazy2[rt] = val;
            lazy1[rt] = 0;
            return;
        }
        int mid = (l + r) >> 1;
        push_down(rt);
        if(y <= mid) update2(lc, l, mid, x, y, val);
        else if(x > mid) update2(rc, mid + 1, r, x, y, val);
        else update2(lc, l, mid, x, mid, val), update2(rc, mid + 1, r, mid + 1, y, val);
        push_up(rt);
    }
    ll query(int rt, int l, int r, int x, int y) {
        if(x == l && y == r) return st[rt];
        int mid = (l + r) >> 1;
        push_down(rt);
        if(y <= mid) return query(lc, l, mid, x, y);
        else if(x > mid) return query(rc, mid + 1, r, x, y);
        else return min(query(lc, l, mid, x, mid), query(rc, mid + 1, r, mid + 1, y));
    }
} st;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin>>n>>q;
    st.build(1, 1, n);
    while(q--) {
        int opt, l, r, v;
        cin>>opt;
        switch(opt) {
        case 1:
            cin>>l>>r>>v;
            st.update1(1, 1, n, l, r, v);
        break;
        case 2:
            cin>>l>>r>>v;
            st.update2(1, 1, n, l, r, v);
        break;
        case 3:
            cin>>l>>r;
            cout<<st.query(1, 1, n, l, r)<<'\n';
        break;
        }
    }
    return 0;
}
