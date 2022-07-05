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
#define all(v) v.begin(), v.end()
#define fir first
#define sec second
using ll = long long;
using pll = pair<ll, ll>;
const int N = 1e5 + 5;
int n, ans[N], tot, x[N], y[N];
set<pll> bst;
struct triple {ll u, v; int id;};
vector<triple> a;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(n);
    for(int i = 1;i<=n;++i) {
        int u = read(), v = read();
        x[i] = u;
        y[i] = v;
        a.pb({u - v, u + v, i});
    }
    sort(all(a), [&](triple& a, triple& b) {
        if(a.u != b.u) return a.u < b.u;
        return a.v > b.v;
    });
    for(auto[u, v, id] : a) {
        auto x = bst.lower_bound({v, 0});
        if(x == bst.end()) ans[id] = ++tot;
        else {
            ans[id] = ans[(*x).sec];
            bst.erase(x);
        }
        bst.insert({v, id});
    }
    print(tot, '\n');
    for(int i = 1;i<=n;++i) {
        print(x[i], ' ');
        print(y[i], ' ');
        print(ans[i], '\n');
    }
    return 0;
}
