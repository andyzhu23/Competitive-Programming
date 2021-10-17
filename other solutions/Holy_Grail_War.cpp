#include <bits/stdc++.h>
using namespace std;

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

const int N = 1e5 + 10;
using ll = long long;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;

struct node {
    ll l, r, lmx, rmx, sz, mx, sum;
    node operator+(const node& other) const {
        node ans;
        ans.mx = -LLINF;
        ans.l = l;
        ans.lmx = lmx;
        ans.r = other.r + sz;
        ans.rmx = other.rmx;
        ans.sz = sz + other.sz;
        ans.sum = sum + other.sum;
        if(ans.lmx <= sum + other.lmx) {
            ans.lmx = sum + other.lmx;
            ans.l = other.l + sz;
        }
        if(ans.rmx <= other.sum + rmx) {
            ans.rmx = other.sum + rmx;
            ans.r = r;
        }
        ans.mx = max(mx, other.mx);
        ans.mx = max(ans.mx, rmx + other.lmx);
        ans.mx = max(ans.mx, max(ans.lmx, ans.rmx));
        return ans;
    }
};

struct segtree {
    node st[N << 2];
#define lc (rt << 1)
#define rc (rt << 1 | 1)
    void push_up(int rt) {
        st[rt] = st[lc] + st[rc];
    }
    void build(int rt, int l, int r) {
        if(l == r) {
            int x = read();
            st[rt] = {1, 1, x, x, 1, x, x};
            return;
        }
        int mid = (l + r) >> 1;
        build(lc, l, mid);
        build(rc, mid + 1, r);
        push_up(rt);
    }
    void update(int rt, int l, int r, int pos, int val) {
        if(l == r) {
            st[rt] = {1, 1, val, val, 1, val, val};
            return;
        }
        int mid = (l + r) >> 1;
        if(pos <= mid) update(lc, l, mid, pos, val);
        else update(rc, mid + 1, r, pos, val);
        push_up(rt);
    }
    node query(int rt, int l, int r, int x, int y) {
        if(l == x && y == r) return st[rt];
        int mid = (l + r) >> 1;
        if(y <= mid) return query(lc, l, mid, x, y);
        else if(x > mid) return query(rc, mid + 1, r, x, y);
        else return query(lc, l, mid, x, mid) + query(rc, mid + 1, r, mid + 1, y);
    }
} st;

int main() {
    int n = read();
    int q = read();
    st.build(1, 1, n);
    while(q--) {
        char opt = getchar();
        int l, r;
        read(l), read(r);
        if(opt == 'S') st.update(1, 1, n, l, r);
        else print(st.query(1, 1, n, l, r).mx, '\n');
    }
}
