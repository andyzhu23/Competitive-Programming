#include <bits/stdc++.h>
using namespace std;
#define lc (rt << 1)
#define rc (rt << 1 | 1)
const int N = 1e5 + 5;
using ll = long long;
ll st[N << 2], lazy[N << 2];
int n, q;

void build(int rt, int l, int r) {
    if(l == r) {
        cin>>st[rt];
        return;
    }
    int mid = l + r >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    st[rt] = st[lc] + st[rc];
}

void update(int rt, int l, int r, int x, int y, int val) {
    st[rt] += (y - x + 1) * val;
    if(l == x && y == r) {
        lazy[rt] += val;
        return;
    }
    int mid = l + r >> 1;
    if(y <= mid) update(lc, l, mid, x, y, val);
    else if(x > mid) update(rc, mid + 1, r, x, y, val);
    else update(lc, l, mid, x, mid, val), update(rc, mid + 1, r, mid + 1, y, val);
}

ll query(int rt, int l, int r, int x, int y) {
    if(l == x && y == r) return st[rt];
    int mid = l + r >> 1;
    if(y <= mid) return query(lc, l, mid, x, y) + lazy[rt] * (y - x + 1);
    else if(x > mid) return query(rc, mid + 1, r, x, y) + lazy[rt] * (y - x + 1);
    else return query(lc, l, mid, x, mid) + query(rc, mid + 1, r, mid + 1, y) + lazy[rt] * (y - x + 1);
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>q;
    build(1, 1, n);
    while(q--) {
        char c;
        int a, b, d;
        cin>>c;
        if(c == 'C') {
            cin>>a>>b>>d;
            update(1, 1, n, a, b, d);
        } else {
            cin>>a>>b;
            cout<<query(1, 1, n, a, b)<<'\n';
        }
    }
    return 0;
}
