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
const int N = 23;
const int MOD = 1e9 + 7;
using ll = long long;

int n, a[N][N];
ll dp[1 << 23];
bool vis[1 << 23];

int dfs(int u, int p) {
    if(vis[u]) return dp[u];
    vis[u] = 1;
    for(int i = 0;i<n;++i) {
        if(u & (1 << i) && a[p][i]) dp[u] = (dp[u] + dfs(u ^ (1 << i), p - 1)) % MOD;
    }
    return dp[u];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(n);
    int res = 0;
    for(int i = 0;i<n;++i) {
        for(int j = 0;j<n;++j) {
            a[i][j] = read();
        }
        res |= 1 << i;
    }
    dp[0] = 1;
    print(dfs(res, n - 1), '\n');
    return 0;
}
