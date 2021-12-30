#pragma GCC optimize(2)
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
using ll = long long;
const int N = 1e6 + 10;
ll n, l[N], r[N];
int ans = 1;

struct segtree {
    ll st[N << 2], lazy[N << 2], carry[N << 2];
#define lc (rt << 1)
#define rc (rt << 1 | 1)
    void push_down(int rt) {
        if(carry[rt]) {
            lazy[lc] = max(lazy[lc], lazy[rt]);
            lazy[rc] = max(lazy[rc], lazy[rt]);
            ++carry[lc], ++carry[rc];
            st[lc] = max(st[lc], lazy[rt]);
            st[rc] = max(st[rc], lazy[rt]);
            carry[rt] = 0;
            lazy[rt] = -4485090715960753727ll;
        }
    }
    void update(int rt, int l, int r, int x, int y, ll val) {
        if(l == x && y == r) {
            st[rt] = max(st[rt], val);
            lazy[rt] = max(lazy[rt], val);
            carry[rt]++;
            return;
        }
        int mid = l + r >> 1;
        push_down(rt);
        if(y <= mid) update(lc, l, mid, x, y, val);
        else if(x > mid) update(rc, mid + 1, r, x, y, val);
        else update(lc, l, mid, x, mid, val), update(rc, mid + 1, r, mid + 1, y, val);
    }
    ll query(int rt, int l, int r, int pos) {
        if(l == r) return st[rt];
        int mid = l + r >> 1;
        push_down(rt);
        if(pos <= mid) return query(lc, l, mid, pos);
        else return query(rc, mid + 1, r, pos);
    }
} st;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    memset(st.st, -0x3f, sizeof(st.st));
    memset(st.lazy, -0x3f, sizeof(st.lazy));
    n = read();
    int pos = 1;
    for(int i = 1;i<=n;++i) {
        l[i] = read(), r[i] = read();
        st.update(1, 1, n, pos, i, l[i]);
        while(r[i] < st.query(1, 1, n, pos)) ++pos;
        ans = max(ans, i - pos + 1);
    }
    print(ans, '\n');
    return 0;
}
