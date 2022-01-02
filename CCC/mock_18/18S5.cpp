#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

namespace fast_io {
    inline int read() {
        int x = 0, f = 0; char ch = getchar();
        while (!isdigit(ch)) f |= ch == '-', ch = getchar();
        while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
        return f ? -x : x;
    }
    inline long long readLL() {
        long long x = 0, f = 0; char ch = getchar();
        while (!isdigit(ch)) f |= ch == '-', ch = getchar();
        while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
        return f ? -x : x;
    }
    inline void read(int& x) {x = read();}
    inline void read(long long& x) {x = readLL();}
    inline void read(string& s) {
        s = ""; char c;
        c = getchar();
        while(!isalpha(c)) c = getchar();
        while(isalpha(c)) s += c, c = getchar();
    }
    template<typename T> inline void print(T x) {
        if (x < 0) putchar('-'), x = -x;
        if (x >= 10) print(x / 10);
        putchar(x % 10 + '0');
    }
    template<typename T> inline void print(T x, char let) {
        print(x), putchar(let);
    }
}
using namespace fast_io;
using ll = long long;
const int N = 2e6 + 10;

class segtree {
#define lc (rt << 1)
#define rc (rt << 1 | 1)
private:
    int n = 2e6;
    ll st[N << 2], lazy[N << 2], price[N << 2];
    bool clear[N << 2];
    inline ll get(ll l, ll r) {
        return (r * (r + 1) >> 1) - (l * (l - 1) >> 1);
    }
    inline void push_up(int rt) {
        st[rt] = st[lc] + st[rc];
        price[rt] = price[lc] + price[rc];
    }
    inline void push_down(int rt, int l, int r, int mid) {
        if(clear[rt]) {
            st[lc] = st[rc] = price[lc] = price[rc] = lazy[lc] = lazy[rc] = 0;
            clear[lc] = clear[rc] = 1;
            clear[rt] = 0;
        }
        st[lc] += lazy[rt] * (mid - l + 1);
        st[rc] += lazy[rt] * (r - mid);
        price[lc] += lazy[rt] * get(l, mid);
        price[rc] += lazy[rt] * get(mid + 1, r);
        lazy[lc] += lazy[rt];
        lazy[rc] += lazy[rt];
        lazy[rt] = 0;
    }
    inline void update(int rt, int l, int r, int x, int y, ll val) {
        if(l == x && y == r) {
            st[rt] += (r - l + 1) * val;
            price[rt] += get(l, r) * val;
            lazy[rt] += val;
            return;
        }
        int mid = l + r >> 1;
        push_down(rt, l, r, mid);
        if(y <= mid) update(lc, l, mid, x, y, val);
        else if(x > mid) update(rc, mid + 1, r, x, y, val);
        else update(lc, l, mid, x, mid, val), update(rc, mid + 1, r, mid + 1, y, val);
        push_up(rt);
    }
    inline ll queryQ(int rt, int l, int r, ll val) {
        if(l == r) {
            st[rt] -= val / l;
            price[rt] -= val / r * r;
            return val / l;
        }
        int mid = l + r >> 1;
        push_down(rt, l, r, mid);
        ll res;
        if(price[rt] <= val) {
            res = st[rt];
            st[rt] = price[rt] = lazy[rt] = 0;
            clear[rt] = 1;
            push_down(rt, l, r, mid);
        } else if(price[lc] >= val) res = queryQ(lc, l, mid, val);
        else {
            res = st[lc];
            ll tmp = price[lc];
            st[lc] = price[lc] = lazy[lc] = 0;
            clear[lc] = 1;
            res += queryQ(rc, mid + 1, r, val - tmp);
        }
        push_up(rt);
        return res;
    }
    inline ll querylow(int rt, int l, int r, ll val) {
        if(l == r) {
            st[rt] -= val;
            price[rt] -= val * l;
            return val * l;
        }
        int mid = l + r >> 1;
        push_down(rt, l, r, mid);
        ll res;
        if(st[rt] <= val) {
            res = price[rt];
            price[rt] = st[rt] = lazy[rt] = 0;
            clear[rt] = 1;
            push_down(rt, l, r, mid);
        }
        else if(st[lc] >= val) res = querylow(lc, l, mid, val);
        else {
            res = price[lc];
            ll tmp = st[lc];
            price[lc] = st[lc] = lazy[lc] = 0;
            clear[lc] = 1;
            res += querylow(rc, mid + 1, r, val - tmp);
        }
        push_up(rt);
        return res;
    }
    inline ll queryhigh(int rt, int l, int r, ll val) {
        if(l == r) {
            st[rt] -= val;
            price[rt] -= val * l;
            return val * l;
        }
        int mid = l + r >> 1;
        push_down(rt, l, r, mid);
        ll res;
        if(st[rt] <= val) {
            res = price[rt];
            price[rt] = st[rt] = lazy[rt] = 0;
            clear[rt] = 1;
            push_down(rt, l, r, mid);
        }
        else if(st[rc] >= val) res = queryhigh(rc, mid + 1, r, val);
        else {
            res = price[rc];
            ll tmp = st[rc];
            price[rc] = st[rc] = lazy[rc] = 0;
            clear[rc] = 1;
            res += queryhigh(lc, l, mid, val - tmp);
        }
        push_up(rt);
        return res;
    }
    inline ll querycost(int rt, int l, int r, ll pos) {
        if(l == r) return l;
        int mid = l + r >> 1;
        push_down(rt, l, r, mid);
        if(st[rt] < pos) return -1;
        if(st[lc] >= pos) return querycost(lc, l, mid, pos);
        else return querycost(rc, mid + 1, r, pos - st[lc]);
    }
public:
    inline void add(int k, int p) {update(1, 1, n, p, p, k);}
    inline void addrange(int a, int b) {update(1, 1, n, a, b, 1);}
    inline void buyamt(ll q) {print(queryQ(1, 1, n, q), '\n');}
    inline void buylow(ll l) {print(querylow(1, 1, n, l), '\n');}
    inline void buyhigh(ll l) {print(queryhigh(1, 1, n, l), '\n');}
    inline void cost(ll l) {print(querycost(1, 1, n, l), '\n');}
    inline void numcones() {print(st[1], '\n');}
    inline void totalcost() {print(price[1], '\n');}
} st;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n = read();
    string opt;
    while(n--) {
        read(opt);
        if(opt == "ADD") {
            int a = read(), b = read();
            st.add(a, b);
        } else if(opt == "ADDRANGE") {
            int a = read(), b = read();
            st.addrange(a, b);
        } else if(opt == "BUYAMT") st.buyamt(readLL());
        else if(opt == "BUYLOW") st.buylow(readLL());
        else if(opt == "BUYHIGH") st.buyhigh(readLL());
        else if(opt == "COST") st.cost(readLL());
        else if(opt == "NUMCONES") st.numcones();
        else if(opt == "TOTALCOST") st.totalcost();
    }
    return 0;
}
