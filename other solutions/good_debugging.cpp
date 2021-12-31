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
const int N = 1e6 + 10;
int n, m, l;

class segtree {
#define lc (rt << 1)
#define rc (rt << 1 | 1)
private:
    int st[N << 2];
    bool lazy[N << 2];
    void push_up(int rt) {st[rt] = st[lc] + st[rc];}
    void push_down(int rt, int l, int r, int mid) {
        if(lazy[rt]) {
            st[lc] = mid - l + 1 - st[lc];
            st[rc] = r - mid - st[rc];
            lazy[lc] ^= 1;
            lazy[rc] ^= 1;
            lazy[rt] = 0;
        }
    }
    void build(int rt, int l, int r) {
        if(l == r) {
            st[rt] = 1;
            return;
        }
        int mid = l + r >> 1;
        build(lc, l, mid);
        build(rc, mid + 1, r);
        push_up(rt);
    }
    void update(int rt, int l, int r, int x, int y) {
        if(l == x && y == r) {
            st[rt] = r - l + 1 - st[rt];
            lazy[rt] ^= 1;
            return;
        }
        int mid = l + r >> 1;
        push_down(rt, l, r, mid);
        if(y <= mid) update(lc, l, mid, x, y);
        else if(x > mid) update(rc, mid + 1, r, x, y);
        else update(lc, l, mid, x, mid), update(rc, mid + 1, r, mid + 1, y);
        push_up(rt);
    }
    int query(int rt, int l, int r, int val) {
        if(l == r) return l;
        int mid = l + r >> 1;
        push_down(rt, l, r, mid);
        if(val > st[rt]) return -1;
        else if(st[lc] >= val) return query(lc, l, mid, val);
        else return query(rc, mid + 1, r, val - st[lc]);
    }
public:
    void build() {build(1, 1, n);}
    void update(int x, int y) {update(1, 1, n, x, y);}
    int query(int val) {return query(1, 1, n, val);}
} st;

int main() {
#ifdef LOCAL    
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    n = read(), m = read(), l = read();
    st.build();
    while(m--) {
        int a = read(), b = read();
        st.update(a, b);
        int ans = st.query(l);
        if(ans == -1) puts("AC?");
        else print(st.query(l), '\n');
    }
    return 0;
}

