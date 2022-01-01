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
const int N = 2e6 + 10;
const int INF = 0x3f3f3f3f;
int h, j, n;

template <typename T> void ckmin(T& a, T b) {a = min(a, b);}

class segtree {
#define lc (rt << 1)
#define rc (rt << 1 | 1)
private:
    int st[N << 2], lazy[N << 2];
    void push_up(int rt) {st[rt] = min(st[lc], st[rc]);}
    void push_down(int rt) {
        ckmin(st[lc], lazy[rt]);
        ckmin(st[rc], lazy[rt]);
        ckmin(lazy[lc], lazy[rt]);
        ckmin(lazy[rc], lazy[rt]);
        lazy[rt] = INF;
    }
    void update(int rt, int l, int r, int x, int y, int val) {
        if(l == x && y == r) {
            ckmin(st[rt], val);
            ckmin(lazy[rt], val);
            return;
        }
        int mid = l + r >> 1;
        push_down(rt);
        if(y <= mid) update(lc, l, mid, x, y, val);
        else if(x > mid) update(rc, mid + 1, r, x, y, val);
        else update(lc, l, mid, x, mid, val), update(rc, mid + 1, r, mid + 1, y, val);
        push_up(rt);
    }
    int query(int rt, int l, int r, int x, int y) {
        if(l == r) return st[rt];
        int mid = l + r >> 1;
        push_down(rt);
        if(y <= mid) return query(lc, l, mid, x, y);
        else if(x > mid) return query(rc, mid + 1, r, x, y);
        else return min(query(lc, l, mid, x, mid), query(rc, mid + 1, r, mid + 1, y));
    }
public:
    void build() {
        memset(st, 0x3f, sizeof(st));
        memset(lazy, 0x3f, sizeof(lazy));
    }
    void update(int x, int y, int val) {update(1, 0, h + j, x, y, val);}
    int query(int x, int y) {return query(1, 0, j + h, x, y);}
    int query(int pos) {return query(pos, pos);}
} dp;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    h = read(), j = read(), n = read();
    dp.build();
    while(n--) {
        int a = read(), b = read();
        dp.update(a, b, -1);
    }
    dp.update(0, 0, 0);
    for(int i = j;i<=h + j;++i) {
        int res = dp.query(i - j);
        if(res == -1 || dp.query(i) == -1) continue;
        dp.update(i, i, res + 1);
        dp.update(1, i, res + 2);
    }
    int ans = dp.query(h, h + j);
    print(ans == INF ? -1 : ans, '\n');
    return 0;
}
