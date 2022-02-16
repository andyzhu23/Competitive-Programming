#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, q;

#define lc (rt << 1)
#define rc (rt << 1 | 1)

struct node {
    int l, r;
} st[N << 2], lazy[N << 2];

void build(int rt, int l, int r) {
    if(l == r) {
        st[rt] = {1, n};
        return;
    }
    int mid = l + r >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
}

void push_down(int rt) {
    if(!(lazy[rt].l == lazy[rt].r && lazy[rt].l == 0)) {
        st[lc] = st[rc] = lazy[rt];
        lazy[lc] = lazy[rc] = lazy[rt];
        lazy[rt] = {0, 0};
    }
}

void update(int rt, int l, int r, int x, int y, node val) {
    if(y < x) return;
    if(l == x && y == r) {
        st[rt] = val;
        lazy[rt] = val;
        return;
    }
    int mid = l + r >> 1;
    push_down(rt);
    if(y <= mid) update(lc, l, mid, x, y, val);
    else if(x > mid) update(rc, mid + 1, r, x, y, val);
    else update(lc, l, mid, x, mid, val), update(rc, mid + 1, r, mid + 1, y, val);
}

node query(int rt, int l, int r, int pos) {
    if(l == r) return st[rt];
    int mid = l + r >> 1;
    push_down(rt);
    if(pos <= mid) return query(lc, l, mid, pos);
    else return query(rc, mid + 1, r, pos);
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
        int opt;
        cin>>opt;
        if(opt == 1) {
            int l, r, L, R;
            cin>>l>>r;
            if(l == 1) L = 1;
            else L = query(1, 1, n, l - 1).l;
            if(L == -1) L = l;
            if(r == n) R = n;
            else R = query(1, 1, n, r + 1).r;
            if(R == -1) R = r;
            update(1, 1, n, l, r, {-1, -1});
            if(l > 1) update(1, 1, n, L, l - 1, {L, l - 1});
            if(r < n) update(1, 1, n, r + 1, R, {r + 1, R});
        } else if(opt == 2) {
            int l, r, L, R;
            cin>>l>>r;
            if(l == 1) L = 1;
            else L = query(1, 1, n, l - 1).l;
            if(L == -1) L = l;
            if(r == n) R = n;
            else R = query(1, 1, n, r + 1).r;
            if(R == -1) R = r;
            update(1, 1, n, L, R, {L, R});
        } else {
            int x; cin>>x;
            auto[l, r] = query(1, 1, n, x);
            if(l == 1 || r == n) cout<<"INF\n";
            else if(l == -1 || r == -1) cout<<"0\n";
            else cout<<r - l + 1<<'\n';
        }
    }
    return 0;
}
