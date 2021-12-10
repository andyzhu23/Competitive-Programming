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

#define pb push_back
using ll = long long;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 10;
int n, p, len = 0;
using pii = pair<int, int>;

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

unordered_map<pii, ll, pair_hash> dp;
set<int> dis;
unordered_map<int, int> Map;

struct node {
    int x, y, id, a, b;
    inline bool operator<(const node& other) const {
        return x == other.x ? y < other.y : x < other.x;
    }
};
vector<node> a;

struct segtree {
    ll st[N << 2] = {INF};
#define lc (rt << 1)
#define rc (rt << 1 | 1)
    inline void update(int pos, ll val, int rt = 1, int l = 1, int r = len) {
        if(l == r) {
            st[rt] = min(st[rt], val);
            return;
        }
        int mid = l + r >> 1;
        if(pos <= mid) update(pos, val, lc, l, mid);
        else update(pos, val, rc, mid + 1, r);
        st[rt] = min(st[lc], st[rc]);
    }
    inline ll query(int x, int y, int rt = 1, int l = 1, int r = len) {
        if(l == x && y == r) return st[rt];
        int mid = l + r >> 1;
        if(y <= mid) return query(x, y, lc, l, mid);
        else if(x > mid) return query(x, y, rc, mid + 1, r);
        else return min(query(x, mid, lc, l, mid), query(mid + 1, y, rc, mid + 1, r));
    }
} st;

int main() {
    freopen("boards.in", "r", stdin);
    freopen("boards.out", "w", stdout);
    read(n), read(p);
    for(int i = 1;i<=p;++i) {
        int x = read(), y = read(), z = read(), w = read();
        a.pb({x, y, 0});
        a.pb({z, w, 1, x, y});
        dis.insert(y);
        dis.insert(w);
    }
    dis.insert(n);
    dis.insert(0);
    for(auto x : dis) Map[x] = ++len;
    st.update(Map[0], 0);
    a.pb({n, n, 0});
    sort(a.begin(), a.end());
    for(auto& cur : a) {
        int x = cur.x, y = cur.y;
        dp[{x, y}] = INF;
        if(cur.id) dp[{x, y}] = dp[{cur.a, cur.b}], dp.erase({cur.a, cur.b});
        dp[{x, y}] = min(dp[{x, y}], st.query(1, Map[y]) + x + y);
        if(cur.id) st.update(Map[y], dp[{x, y}] - x - y);
    }
    print(dp[{n, n}], '\n');
    return 0;
}
