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

struct segtree {
    int st[N << 2];
#define lc (rt << 1)
#define rc (rt << 1 | 1)
    inline void reinit(int n) {
        for(int i = 1;i<=(n << 2);++i) st[i] = 0x3f3f3f3f;
    }
    inline void push_up(int rt) {
        st[rt] = min(st[lc], st[rc]);
    }
    inline void update(int rt, int l, int r, int pos, int val) {
        if(l == r) {
            st[rt] = min(st[rt], val);
            return;
        }
        int mid = (l + r) >> 1;
        if(pos <= mid) update(lc, l, mid, pos, val);
        else update(rc, mid + 1, r, pos, val);
        push_up(rt);
    }
    inline int query(int rt, int l, int r, int x, int y) {
        if(l == x && y == r) return st[rt];
        int mid = (l + r) >> 1;
        if(y <= mid) return query(lc, l, mid, x, y);
        else if(x > mid) return query(rc, mid + 1, r, x, y);
        else return min(query(lc, l, mid, x, mid), query(rc, mid + 1, r, mid + 1, y));
    }
} st;

inline void solve() {
    int n = read();
    st.reinit(100000);
    for(int i = 1;i<=n;++i) st.update(1, 1, 100000, read(), i);
    int ans = 0;
    for(int i = 1;i<=n;++i) ans = max(ans, i - st.query(1, 1, 100000, 1, read()));
    printf("The maximum distance is %d\n", ans);
    fflush(stdout);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t = read();
    for(int i = 1;i<=t;++i) solve();
    return 0;
}
