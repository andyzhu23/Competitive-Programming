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
const int N = 1005;
int n, m, W, w[N], V[N], dp[N][N], dp2[N][N];
bool vis[N][N];
using pii = pair<int, int>;
#define pb push_back
#define fir first
#define sec second
vector<pii> e[N];

template <typename T> void ckmax(T& a, T b) {a = max(a, b);}
template <typename T> void ckmin(T& a, T b) {a = min(a, b);}

int dfs(int u, int c) {
    if(vis[u][c]) return dp[u][c];
    vis[u][c] = 1;
    for(pii v : e[u]) {
        if(c >= w[u]) {
            dfs(v.fir, c - w[u]);
            int nxt = dp[v.fir][c - w[u]] + V[u];
            int nxt2 = dp2[v.fir][c - w[u]] + (c - w[u]) * v.sec;
            if(dp[u][c] == nxt) ckmin(dp2[u][c], nxt2);
            else if(dp[u][c] < nxt) {
                dp[u][c] = nxt;
                dp2[u][c] = nxt2;
            }
        }
        dfs(v.fir, c);
        int nxt2 = dp2[v.fir][c] + c * v.sec;
        if(dp[u][c] < dp[v.fir][c]) {
            dp[u][c] = dp[v.fir][c];
            dp2[u][c] = nxt2;
        } else if(dp[u][c] == dp[v.fir][c]) ckmin(dp2[u][c], nxt2);
    }
    return dp[u][c];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(n), read(m), read(W);
    memset(dp, -0x3f, sizeof(dp));
    memset(dp2, 0x3f, sizeof(dp2));
    for(int i = 1;i<=n;++i) w[i] = read(), V[i] = read();
    dp[1][0] = 0;
    dp2[1][0] = 0;
    vis[1][0] = 1;
    dp[1][w[1]] = V[1];
    dp2[1][w[1]] = 0;
    vis[1][w[1]] = 1;
    for(int i = 1;i<=m;++i) {
        int x = read(), y = read(), z = read();
        e[y].pb({x, z});
    }
    int ans = 0, ans2 = 0;
    for(int i = 0;i<=W;++i) {
        dfs(n, i);
        if(ans == dp[n][i]) ckmin(ans2, dp2[n][i]);
        else if(ans < dp[n][i]) {
            ans = dp[n][i];
            ans2 = dp2[n][i];
        }
    }
    print(ans, ' ');
    print(ans2, '\n');
    return 0;
}

