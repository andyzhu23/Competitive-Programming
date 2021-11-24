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
using ll = long long;
const int N = 23;
int n, a[N][N];
double dp[1 << 20];
bool vis[1 << 20];

double dfs(int mask, int u) {
    if(vis[mask]) return dp[mask];
    vis[mask] = 1;
    for(int i = 0;i<n;++i) {
        if(mask & (1 << i)) dp[mask] = max(dp[mask], dfs(mask ^ (1 << i), u - 1) * a[u][i] / 100.0);
    }
    return dp[mask];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    n = read();
    int res = 0;
    dp[0] = vis[0] = 100;
    for(int i = 0;i<n;++i) {
        for(int j = 0;j<n;++j) a[i][j] = read();
        res |= 1 << i;
    }
    printf("%.6f", dfs(res, n - 1) * 100);
    return 0;
}
