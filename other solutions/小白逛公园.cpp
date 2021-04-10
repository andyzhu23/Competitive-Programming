#include <iostream>
#define endl "\n"
using namespace std;
const int N = 1e6 + 10;
int n, m;
struct node {
    int lx, rx, mx, sum;
} st[N << 2];

inline void push_up(int rt, int l, int r, int mid) {
    st[rt].sum = st[rt << 1].sum + st[rt << 1 | 1].sum;
    st[rt].mx = max(st[rt << 1].rx + st[rt << 1 | 1].lx, max(st[rt << 1].mx, st[rt << 1 | 1].mx));
    st[rt].lx = st[rt << 1].lx;
    st[rt].rx = st[rt << 1 | 1].rx;
    st[rt].lx = max(st[rt].lx, st[rt << 1].sum + st[rt << 1 | 1].lx);
    st[rt].rx = max(st[rt].rx, st[rt << 1 | 1].sum + st[rt << 1].rx);
}

inline void build(int rt, int l, int r) {
    if (l == r) {
        cin>>st[rt].lx;
        st[rt].sum = st[rt].mx = st[rt].rx = st[rt].lx;
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    push_up(rt, l, r, mid);
}

inline void update(int rt, int l, int r, int pos, int val) {
    if (l == r) {
        st[rt].sum = st[rt].lx = st[rt].mx = st[rt].rx = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) update(rt << 1, l, mid, pos, val);
    else update(rt << 1 | 1, mid + 1, r, pos, val);
    push_up(rt, l, r, mid);
}

inline node query(int rt, int l, int r, int x, int y) {
    if (l == x && y == r) {
        return st[rt];
    }
    int mid = (l + r) >> 1;
    if (y <= mid) return query(rt << 1, l, mid, x, y);
    else if (x > mid) return query(rt << 1 | 1, mid + 1, r, x, y);
    else {
        node a = query(rt << 1, l, mid, x, mid);
        node b = query(rt << 1 | 1, mid + 1, r, mid + 1, y);
        int res = a.rx + b.lx;
        node c;
        c.mx = max(a.mx, max(b.mx, res));
        c.lx = a.lx;
        c.rx = b.rx;
        c.sum = a.sum + b.sum;
        c.lx = max(c.lx, a.sum + b.lx);
        c.rx = max(c.rx, b.sum + a.rx);
        return c;
    }
}

inline void solve() {
    int opt, x, y;
    cin >> opt >> x >> y;
    if (opt == 1) {
        if(x > y) swap(x, y);
        cout << query(1, 1, n, x, y).mx << endl;
    } else {
        update(1, 1, n, x, y);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    build(1, 1, n);
    while (m--){
        solve();
    }
    return 0;
}
