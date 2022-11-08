#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int NN = N * N;
const int mod = 1e9 + 7;
using ll = long long;
#define pb push_back
int n, m, to[NN];
#define id(x, y) ((x - 1) * m + y)
char c[N][N];
set<int> e[NN];
ll dp[NN];

struct DSU {
    int f[NN], n;
    DSU(int n) :n(n) {iota(f, f + n + 1, 0);}
    int Find(int x) {return f[x] == x ? x : f[x] = Find(f[x]);}
    bool merge(int u, int v) {
        int fu = Find(u);
        int fv = Find(v);
        if(fu == fv) return 0;
        f[fu] = fv;
        return 1;
    }
};

ll dfs(int u) {
    if(dp[u]) return dp[u];
    dp[u] = 1;
    for(int v : e[u]) dp[u] = dp[u] * dfs(v) % mod;
    dp[u] = (dp[u] + 1) % mod;
    return dp[u];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("cave.in", "r", stdin);
    freopen("cave.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    DSU dsu(n * m);
    for(int i = 1;i<=n;++i) {
        scanf("%s", c[i] + 1);
        for(int j = 1;j<=m;++j) if(c[i][j - 1] == '.' && c[i][j] == '.') 
            dsu.merge(id(i, j), id(i, j - 1));
    }
    for(int i = n;i;--i) {
        for(int j = 1;j<=m;++j) if(c[i][j] == '.') {
            if(c[i - 1][j] == '.') {
                if(to[dsu.Find(id(i, j))]) dsu.merge(id(i - 1, j), to[dsu.Find(id(i, j))]);
                else to[dsu.Find(id(i, j))] = dsu.Find(id(i - 1, j));
            }
        }
    }
    for(int i = 1;i<=n;++i) {
        for(int j = 1;j<=m;++j) if(c[i][j] == '.') {
            if(to[dsu.Find(id(i, j))]) 
                e[dsu.Find(to[dsu.Find(id(i, j))])].insert(dsu.Find(id(i, j)));
        }
    }
    ll ans = 1;
    for(int i = 1;i<=n;++i) {
        for(int j = 1;j<=m;++j) if(c[i][j] == '.' && dp[dsu.Find(id(i, j))] == 0) {
            ans = ans * dfs(dsu.Find(id(i, j))) % mod;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
