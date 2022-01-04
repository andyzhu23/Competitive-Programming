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
using pii = pair<int, int>;
const int N = 1e5 + 10;
#define fir first
#define sec second
int n, dp[N], mx;
pii a[N];

template <typename T> void ckmax(T& a, T b) {a = max(a, b);}

struct segtree {
#define lc (rt << 1)
#define rc (rt << 1 | 1)
    int st[N << 2];
    void update(int rt, int l, int r, int pos, int val) {
        if(l == r) {
            ckmax(st[rt], val);
            return;
        }
        int mid = l + r >> 1;
        if(pos <= mid) update(lc, l, mid, pos, val);
        else update(rc, mid + 1, r, pos, val);
        st[rt] = max(st[lc], st[rc]);
    }
    int query(int rt, int l, int r, int x, int y) {
        if(l == x && y == r) return st[rt];
        int mid = l + r >> 1;
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
    n = read();
    for(int i = 1;i<=n;++i) {
        int x = read(), y = read();
        a[i] = {x, y};
        ckmax(mx, y);
    }
    ++mx;
    sort(a + 1, a + n + 1, greater<pii>());
    int l = 0, ans = 0;
    for(int i = 1;i<=n;++i) {
        while(a[l + 1].fir != a[i].fir) ++l, st.update(1, 1, mx, a[l].sec, dp[l]);
        dp[i] = st.query(1, 1, mx, a[i].sec + 1, mx) + 1;
        ckmax(ans, dp[i]);
    }
    print(ans, '\n');
    return 0;
}
