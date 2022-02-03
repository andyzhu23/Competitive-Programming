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
using pii = pair<int, int>;
const int N = 1e6 + 5;
int n, m, k, v[N], ans[N], cnt, f[N];
bool vis[N];
pii e[N];
vector<int> e2[N];

int Find(int x) {return f[x] == x ? x : f[x] = Find(f[x]);}
bool merge(pii x) {
    int u = x.first;
    int v = x.second;
    int fu = Find(u);
    int fv = Find(v);
    if(fu == fv) return 0;
    --cnt;
    f[fu] = fv;
    return 1;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(n), read(m);
    cnt = n;
    iota(f, f + n + 1, 0);
    for(int i = 1;i<=m;++i) {
        int u = read(), v = read();
        e[i] = {u, v};
        e2[u].pb(v);
        e2[v].pb(u);
    }
    k = read();
    for(int i = 1;i<=k;++i) {
        v[i] = read();
        vis[v[i]] = 1;
    }
    for(int i = 1;i<=m;++i) if(!vis[e[i].first] && !vis[e[i].second]) {
        merge(e[i]);
    }
    for(int i = k;i;--i) {
        ans[i] = cnt - i;
        for(auto u : e2[v[i]]) if(!vis[u]) {
            merge({v[i], u});
        }
        vis[v[i]] = 0;
    }
    ans[0] = cnt;
    for(int i = 0;i<=k;++i) print(ans[i], '\n');
    return 0;
}
