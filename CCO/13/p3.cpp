#include <bits/stdc++.h>

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
using namespace std;
#define pb push_back
using ll = long long;
const int N = 4e5 + 10;
int n, start, finish, dist[N], Max;
vector<int> e[N];

void dfs1(int u, int fa) {
    dist[u] = dist[fa] + 1;
    if(dist[u] >= Max) {
        Max = dist[u];
        start = u;
    }
    for(int v : e[u]) {
        if(v == fa) continue;
        dfs1(v, u);
    }
}

void dfs2(int u, int fa) {
    dist[u] = dist[fa] + 1;
    if(dist[u] >= Max) {
        Max = dist[u];
        finish = u;
    }
    for(int v : e[u]) {
        if(v == fa) continue;
        dfs2(v, u);
    }
}
bool flag = 0;
int root, root2, dp[N];
void dfs3(int u, int fa) {
    if(u == finish) flag = 1;
    for(int v : e[u]) {
        if(flag || v == fa) continue;
        dfs3(v, u);
    }
    if(flag) {
        if(dist[u] == Max / 2 + 1) root = u;
        else if((Max & 1) == 0 && dist[u] == Max / 2) root2 = u;
    }
}

void dfs4(int u, int fa, int target) {
    dist[u] = dist[fa] + 1;
    if(dist[u] == target) dp[u] = 1;
    for(int v : e[u]) {
        if(v == fa) continue;
        dfs4(v, u, target);
        dp[u] += dp[v];
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(n);
    for(int i = 1;i<n;++i) {
        int u = read(), v = read();
        e[u].pb(v);
        e[v].pb(u);
    }
    // find primeter
    dfs1(1, 0);
    Max = 0;
    memset(dist, 0, sizeof(dist));
    dfs2(start, 0);
    dfs3(start, 0);
    memset(dist, 0, sizeof(dist));
    ll ans = 0;
    if(Max & 1) {
        dfs4(root, 0, Max / 2 + 1);
        for(int v : e[root]) ans += 1ll * dp[v] * (dp[root] - dp[v]);
        ans >>= 1;
    } else {
        dfs4(root, 0, Max / 2 + 1);
        ans = dp[root];
        memset(dp, 0, sizeof(dp));
        memset(dist, 0, sizeof(dist));
        dfs4(root2, 0, Max / 2 + 1);
        ans *= dp[root2];
    }
    print(Max, ' ');
    print(ans, '\n');
    return 0;
}
