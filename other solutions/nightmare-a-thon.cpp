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
const int N = 5e5 + 10;
int n, q; 

struct node {
    int val, cnt;
    node operator+ (const node& other) const {
        if(val > other.val) return {val, cnt};
        else if(val < other.val) return other;
        return {val, cnt + other.cnt};
    }
};

struct segtree {
    node st[N << 2];
#define lc (rt << 1)
#define rc (rt << 1 | 1)
    void build(int rt, int l, int r) {
        if(l == r) {
            st[rt] = {read(), 1};
            return;
        }
        int mid = l + r >> 1;
        build(lc, l, mid);
        build(rc, mid + 1, r);
        st[rt] = st[lc] + st[rc];
    }
    node query(int rt, int l, int r, int x, int y) {
        if(l == x && y == r) return st[rt];
        int mid = l + r >> 1;
        if(y <= mid) return query(lc, l, mid, x, y);
        else if(x > mid) return query(rc, mid + 1, r, x, y);
        else return query(lc, l, mid, x, mid) + query(rc, mid + 1, r, mid + 1, y);
    }
} st;



int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(n), read(q);
    st.build(1, 1, n);
    while(q--) {
        int a = read(), b = read();
        node ans = {0, 0};
        if(a != 1) ans = ans + st.query(1, 1, n, 1, a - 1);
        if(b != n) ans = ans + st.query(1, 1, n, b + 1, n);
        print(ans.val, ' ');
        print(ans.cnt, '\n');
    }
    return 0;
}
