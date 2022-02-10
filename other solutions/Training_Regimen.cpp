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
const int N = 2e5 + 5;
#define pb push_back
using ll = long long;
int n, m, t[N];

struct edge {
    int u, v, w;
    bool operator<(const edge& other) const {
        return w < other.w;
    }
};
vector<edge> e;

struct DSU {
    int f[N], n;
    DSU(int n) :n(n) {
        iota(f, f + n + 1, 0);
    }
    int Find(int x) {return f[x] == x ? x : f[x] = Find(f[x]);}
    bool same(int u, int v) {
        int fu = Find(u);
        int fv = Find(v);
        return fu == fv;
    }
    void merge(int u, int v) {
        int fu = Find(u);
        int fv = Find(v);
        f[fu] = fv;
        t[fv] = min(t[fv], t[fu]);
    }
};

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(n), read(m);
    DSU dsu(n);
    for(int i = 1;i<=n;++i) read(t[i]);
    for(int i = 1;i<=m;++i) {
        int u = read(), v = read(), w = read();
        e.pb({u, v, w});
    }
    sort(e.begin(), e.end());
    int level = 1;
    ll ans = 0;
    for(auto x : e) {
        ans += (ll)(x.w - level) * t[dsu.Find(1)];
        level = x.w;
        dsu.merge(x.u, x.v);
        if(dsu.same(1, n)) break;
    }
    print(dsu.same(1, n) ? ans : -1, '\n');
    return 0;
}
