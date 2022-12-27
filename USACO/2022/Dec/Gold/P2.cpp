#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define ins insert
const int N = 2005;

int n, h[N];

struct segtree {
    int st[N << 2];
#define lc (rt << 1)
#define rc (rt << 1 | 1)
    void update(int rt, int l, int r, int pos, int val) {
        if(l == r) {
            st[rt] += val;
            return;
        }
        int mid = l + r >> 1;
        if(pos <= mid) update(lc, l, mid, pos, val);
        else update(rc, mid + 1, r, pos, val);
        st[rt] = st[lc] + st[rc];
    }
    int query(int rt, int l, int r, int x, int y) {
        if(l == x && y == r) return st[rt];
        int mid = l + r >> 1;
        if(y <= mid) return query(lc, l, mid, x, y);
        else if(x > mid) return query(rc, mid + 1, r, x, y);
        else return query(lc, l, mid, x, mid) + query(rc, mid + 1, r, mid + 1, y);
    }
    int right(int rt, int l, int r, int x, int y) {
        if(st[rt] == 0) return -1;
        if(l == r) return l;
        int mid = l + r >> 1;
        if(y <= mid) return right(lc, l, mid, x, y);
        else if(x > mid) return right(rc, mid + 1, r, x, y);
        else {
            int tmp = right(rc, mid + 1, r, mid + 1, y);
            if(tmp == -1) tmp = right(lc, l, mid, x, mid);
            return tmp;
        }
    }
    int left(int rt, int l, int r, int x, int y) {
        if(st[rt] == 0) return -1;
        if(l == r) return l;
        int mid = l + r >> 1;
        if(y <= mid) return left(lc, l, mid, x, y);
        else if(x > mid) return left(rc, mid + 1, r, x, y);
        else {
            int tmp = left(lc, l, mid, x, mid);
            if(tmp == -1) tmp = left(rc, mid + 1, r, mid + 1, y);
            return tmp;
        }
    }
    void clear() {
        memset(st, 0, sizeof st);
    }
    bool empty() {
        return query(1, 1, n, 1, n) == 0;
    }
    void insert(int i) {
        update(1, 1, n, i, 1);
    }
    void erase(int i) {
        update(1, 1, n, i, -1);
    }
    int size() {
        return query(1, 1, n, 1, n);
    }
} st[N];

int GCD(int a, int b) {
    return b == 0 ? a : GCD(b, a % b);
}

int LCM(int a, int b) {
    return a / GCD(a, b) * b;
}

bool ok(int i, int j, int k) {
    int lcm = LCM(j - i, k - i);
    return 1ll * lcm / (j - i) * (h[j] - h[i]) <= 1ll * lcm / (k - i) * (h[k] - h[i]);
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    for(int i = 1;i<=n;++i) cin>>h[i];
    for(int i = 1;i<=n;++i) {
        st[i].clear();
        for(int j = i + 1;j<=n;++j) {
            if(st[i].empty()) st[i].ins(j);
            else if(ok(i, st[i].right(1, 1, n, 1, n), j)) st[i].ins(j);
        }
    }
    int q; cin>>q;
    while(q--) {
        int x, y;
        cin>>x>>y;
        h[x] += y;
        st[x].clear();
        for(int j = x + 1;j<=n;++j) {
            if(st[x].empty()) st[x].ins(j);
            else if(ok(x, st[x].right(1, 1, n, 1, n), j)) st[x].ins(j);
        }
        for(int i = 1;i<x;++i) {
            if(st[i].query(1, 1, n, x, x)) st[i].erase(x);
            int pos = st[i].right(1, 1, n, 1, x);
            if(pos == -1 || ok(i, pos, x)) {
                pos = st[i].left(1, 1, n, x, n);
                while(pos != -1 && !ok(i, x, pos)) {
                    st[i].erase(pos);
                    pos = st[i].left(1, 1, n, x, n);
                }
                st[i].ins(x);
            }
        }
        int ans = 0;
        for(int i = 1;i<=n;++i) ans += st[i].size();
        cout<<ans<<'\n';
    }
    return 0;
}