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
#define mp make_pair
#define fir first
#define sec second
using ll = long long;
using pii = pair<int, int>;
const int N = 6e3 + 10;
int n, f[N][30], dep[N];
ll dist[N];
vector<pii> e[N];

void dfs(int u, int fa, int d) {
    f[u][0] = fa;
    dep[u] = dep[fa] + 1;
    dist[u] = dist[fa] + d;
    for(int i = 1;i<=22;++i) 
        f[u][i] = f[f[u][i - 1]][i - 1];
    for(pii v : e[u]) {
        if(v.fir == fa) continue;
        dfs(v.fir, u, v.sec);
    }
}

int lca(int u, int v) {
    if(dep[u] < dep[v]) swap(u, v);
    for(int i = 22;i>=0;--i) {
        if(dep[f[u][i]] >= dep[v]) u = f[u][i];
        if(u == v) return u;
    }
    for(int i = 22;i>=0;--i) {
        if(f[u][i] != f[v][i]) u = f[u][i], v = f[v][i];
    }
    return f[u][0];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(n);
    for(int i = 1;i<n;++i) {
        int u = read() + 1, v = read() + 1, w = read();
        e[u].pb(mp(v, w));
        e[v].pb(mp(u, w));
    }
    dfs(1, 0, 0);
    int q = read();
    while(q--) {
        int u = read() + 1, v = read() + 1;
        print(dist[u] + dist[v] - 2 * dist[lca(u, v)], '\n');
    }
    return 0;
}
