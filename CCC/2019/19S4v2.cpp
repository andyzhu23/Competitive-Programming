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
using ll = __int128;
const int N = 1e6 + 5;
const ll INF = 1e15;
const ll LLINF = 1e30;
int n, k;
ll a[N];
vector<int> stk;

struct node {
    ll dp, mx;
    bool operator<(const node& other) const {
        return dp + mx < other.dp + other.mx;
    }
};

struct segtree {
#define lc (rt << 1)
#define rc (rt << 1 | 1)
    node st[N << 2];
    ll mn[N << 2], lazy[N << 2];
    bool flag[N << 2];
    void push_down(int rt) {
        if(flag[rt]) {
            lazy[lc] = lazy[rc] = lazy[rt];
            st[lc].dp = mn[lc];
            st[rc].dp = mn[rc];
            st[lc].mx = st[rc].mx = lazy[rt];
            flag[lc] = flag[rc] = 1;
            flag[rt] = 0;
        }
    }
    void push_up(int rt) {
        st[rt] = max(st[lc], st[rc]);
        mn[rt] = max(mn[lc], mn[rc]);
    }
    void build(int rt, int l, int r) {
        if(l == r) {
            st[rt].dp = st[rt].mx = -LLINF;
            mn[rt] = -LLINF;
            return;
        }
        int mid = l + r >> 1;
        build(lc, l, mid);
        build(rc, mid + 1, r);
        push_up(rt);
    }
    void update(int rt, int l, int r, int pos, ll val) {
        if(l == r) {
            st[rt].dp = mn[rt] = val;
            return;
        }
        int mid = l + r >> 1;
        push_down(rt);
        if(pos <= mid) update(lc, l, mid, pos, val);
        else update(rc, mid + 1, r, pos, val);
        push_up(rt);
    }
    void update(int rt, int l, int r, int x, int y, ll val) {
        if(l == x && y == r) {
            st[rt].dp = mn[rt];
            st[rt].mx = val;
            flag[rt] = 1;
            lazy[rt] = val;
            return;
        }
        int mid = l + r >> 1;
        push_down(rt);
        if(y <= mid) update(lc, l, mid, x, y, val);
        else if(x > mid) update(rc, mid + 1, r, x, y, val);
        else update(lc, l, mid, x, mid, val), update(rc, mid + 1, r, mid + 1, y, val);
        push_up(rt);
    }
    node query(int rt, int l, int r, int x, int y) {
        if(l == x && y == r) return st[rt];
        int mid = l + r >> 1;
        push_down(rt);
        if(y <= mid) return query(lc, l, mid, x, y);
        else if(x > mid) return query(rc, mid + 1, r, x, y);
        else return max(query(lc, l, mid, x, mid), query(rc, mid + 1, r, mid + 1, y));
    }
} st;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(n), read(k);
    st.build(1, 0, n);
    st.update(1, 0, n, 0, 0);
    for(int i = 1;i<=n;++i) {
        a[i] = read() - INF;
        while(!stk.empty() && a[stk.back()] < a[i]) stk.pop_back();
        int mx = stk.empty() ? 0 : stk.back();
        st.update(1, 0, n, mx, i - 1, a[i]);
        node dp = st.query(1, 0, n, max(0, i - k), i - 1);
        st.update(1, 0, n, i, dp.dp + dp.mx);
        stk.push_back(i);
    }
    ll day = (n - 1) / k + 1;
    print(st.query(1, 0, n, n, n).dp + day * INF, '\n');
    return 0;
}
