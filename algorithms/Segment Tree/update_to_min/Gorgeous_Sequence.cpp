#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
namespace fast_io {
    int read() {
        int x = 0, f = 0; char ch = getchar();
        while (!isdigit(ch)) f |= ch == '-', ch = getchar();
        while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
            return f ? -x : x;
    }
    void read(int& x) {x = read();}
    template<typename T> void print(T x) {
        if (x < 0) putchar('-'), x = -x;
        if (x >= 10) print(x / 10);
            putchar(x % 10 + '0');
    }
    template<typename T> void print(T x, char let) {
        print(x), putchar(let);
    }
}
using namespace fast_io;
struct node {
    ll mx, smx, cnt, sum;
    node operator+(const node& other) const {
        node ans;
        ans.sum = sum + other.sum;
        if(mx == other.mx) {
            ans.mx = mx;
            ans.cnt = cnt + other.cnt;
            ans.smx = max(smx, other.smx);
        } else if(mx > other.mx) {
            ans.mx = mx;
            ans.cnt = cnt;
            ans.smx = max(smx, other.mx);
        } else {
            ans.mx = other.mx;
            ans.cnt = other.cnt;
            ans.smx = max(mx, other.smx);
        }
        return ans;
    }
};
const int N = 1e6 + 5;
struct segtree {
    node st[N << 2];
    int lazy[N << 2];
#define lc (rt << 1)
#define rc (rt << 1 | 1)
    void build(int rt, int l, int r) {
        lazy[rt] = -1;
        if(l == r) {
            int x = read();
            st[rt] = {x, -1, 1, x};
            return;
        }
        int mid = l + r >> 1;
        build(lc, l, mid);
        build(rc, mid + 1, r);
        st[rt] = st[lc] + st[rc];
    }
    void push_tag(int rt, int val) {
        if(st[rt].mx <= val) return;
        st[rt].sum -= (st[rt].mx - val) * st[rt].cnt;
        st[rt].mx = val;
        lazy[rt] = val;
    }
    void push_down(int rt, int l, int r, int mid) {
        if(~lazy[rt]) {
            push_tag(lc, lazy[rt]);
            push_tag(rc, lazy[rt]);
            lazy[rt] = -1;
        }
    }
    void update(int rt, int l, int r, int x, int y, int val) {
        if(st[rt].mx <= val) return;
        if(l == x && y == r && st[rt].smx < val) {
            if(st[rt].mx > val) push_tag(rt, val);
            return;
        }
        if(l == r) return;
        int mid = l + r >> 1;
        push_down(rt, l, r, mid);
        if(y <= mid) update(lc, l, mid, x, y, val);
        else if(x > mid) update(rc, mid + 1, r, x, y, val);
        else update(lc, l, mid, x, mid, val), update(rc, mid + 1, r, mid + 1, y, val);
        st[rt] = st[lc] + st[rc];
    }
    ll qsum(int rt, int l, int r, int x, int y) {
        if(l == x && y == r) return st[rt].sum;
        int mid = l + r >> 1;
        push_down(rt, l, r, mid);
        if(y <= mid) return qsum(lc, l, mid, x, y);
        else if(x > mid) return qsum(rc, mid + 1, r, x, y);
        else return qsum(lc, l, mid, x, mid) + qsum(rc, mid + 1, r, mid + 1, y);
    }
    ll qmx(int rt, int l, int r, int x, int y) {
        if(l == x && y == r) return st[rt].mx;
        int mid = l + r >> 1;
        push_down(rt, l, r, mid);
        if(y <= mid) return qmx(lc, l, mid, x, y);
        else if(x > mid) return qmx(rc, mid + 1, r, x, y);
        else return max(qmx(lc, l, mid, x, mid), qmx(rc, mid + 1, r, mid + 1, y));
    }
} st;

void solve() {
    int n = read(), q = read(); 
    st.build(1, 1, n);
    while(q--) {
        int opt = read();
        if(opt == 0) {
            int u = read(), v = read(), t = read();
            st.update(1, 1, n, u, v, t);
        } else if(opt == 1) {
            int u = read(), v = read();
            print(st.qmx(1, 1, n, u, v), '\n');
        } else {
            int u = read(), v = read();
            print(st.qsum(1, 1, n, u, v), '\n');
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t = read();
    while(t--) solve();
    return 0;
}

