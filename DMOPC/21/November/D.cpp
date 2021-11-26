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

const int N = 1e6 + 10;
const int INF = 0x3f3f3f3f;
int n, k, a[N], ans[N], b[N];

struct DSU {
    int f[N], siz[N], n;
    DSU(int n) :n(n) {
        for(int i = 1;i<=n;++i) f[i] = i, siz[i] = 1;
    }
    int Find(int x) {return x == f[x] ? x : Find(f[x]);}
    bool merge(int u, int v) {
        int fu = Find(u);
        int fv = Find(v);
        if(fu == fv) return 0;
        if(fu > fv) swap(fu, fv);
        f[fu] = fv;
        siz[fv] += siz[fu];
        siz[fu] = siz[fv];
        return 1;
    }
    int get(int u) {
        return k - siz[Find(u)];
    }
};

struct segtree {
    int st[N << 2];
#define lc (rt << 1)
#define rc (rt << 1 | 1)
    void build(int rt, int l, int r) {
        if(l == r) {
            st[rt] = 1;
            return;
        }
        int mid = l + r >> 1;
        build(lc, l, mid);
        build(rc, mid + 1, r);
        st[rt] = min(st[lc], st[rc]);
    }
    void update(int rt, int l, int r, int pos, int val) {
        if(l == r) {
            st[rt] = val;
            return;
        }
        int mid = l + r >> 1;
        if(pos <= mid) update(lc, l, mid, pos, val);
        else update(rc, mid + 1, r, pos, val);
        st[rt] = min(st[lc], st[rc]);
    }
    int query(int rt, int l, int r, int val) {
        if(l == r) return l;
        int mid = l + r >> 1;
        if(st[lc] <= val) return query(lc, l, mid, val);
        else if(st[rc] <= val) return query(rc, mid + 1, r, val);
        else return INF;
    }
} st;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    n = read(), k = read();
    DSU dsu(n);
    for(int i = 1;i<=n;++i) a[i] = read(), b[a[i]] = i;
    st.build(1, 1, n);
    for(int i = 1;i<=n;++i) {
        int target = st.query(1, 1, n, dsu.get(a[i]));
        if(target > dsu.Find(a[i])) ans[i] = dsu.Find(a[i]);
        else {
            dsu.merge(a[i], target);
            ans[i] = target;
            st.update(1, 1, n, dsu.Find(a[i]), dsu.siz[dsu.Find(a[i])]);
        }
        st.update(1, 1, n, ans[i], INF);
    }
    for(int i = 1;i<n;++i) print(ans[i], ' ');
    print(ans[n], '\n');
    return 0;
}
