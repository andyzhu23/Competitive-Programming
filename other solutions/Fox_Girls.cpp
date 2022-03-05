/*
 * Author: Andy Zhu
 * @date    2022-03-04 12:15:21
 * @version 1.0.0
 */

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
#define ins insert
#define pb push_back
#define all(v) v.begin(), v.end()
using ll = long long;
template <typename T> inline void ckmin(T& a, T b) {a = min(a, b);}
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5 + 5;
int n, w[N];
ll dp[N][3]; // 0 protected by son, 1 by self, 2 by father
int cycle, root, flag = 1;
vector<int> e[N];
bool vis[N], mode;

void findcyc(int u, int fa = 0) {
    vis[u] = 1;
    for(int v : e[u]) if(v != fa) {
        if(vis[v]) {
            if(flag) {
                cycle = u;
                root = v;
                flag = 0;
            }
        } else findcyc(v, u);
    }
}

void dfs(int u, int fa = 0) {
    dp[u][0] = dp[u][2] = 0;
    dp[u][1] = w[u];
    ll mn = 0x3f3f3f3f3f3f3f3f;
    bool flag = 1;
    if(e[u].size() == 1 && u != root) dp[u][0] = LLINF, flag = 0;
    if(mode && u == cycle) dp[u][0] = 0, flag = 0;
    for(int v : e[u]) if(v != fa){
        dfs(v, u);
        dp[u][1] += min({dp[v][0], dp[v][1], dp[v][2]});
        dp[u][2] += min(dp[v][0], dp[v][1]);
        if(dp[v][1] <= dp[v][0]) flag = 0;
        ckmin(mn, dp[v][1] - dp[v][0]);
        dp[u][0] += min(dp[v][0], dp[v][1]);
    }
    if(flag) dp[u][0] += mn;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(n);
    for(int i = 1;i<=n;++i) read(w[i]);
    for(int i = 1;i<=n;++i) {
        int x = read();
        e[x].pb(i);
        e[i].pb(x);
    }
    for(int i = 1;i<=n;++i) sort(all(e[i]));
    ll ans = 0;
    for(int i = 1;i<=n;++i) if(!vis[i]) {
        flag = 1;
        findcyc(i);
        e[root].erase(lower_bound(all(e[root]), cycle));
        e[cycle].erase(lower_bound(all(e[cycle]), root));
        mode = 0;
        dfs(root);
        ll tmp = dp[root][0];
        mode = 1;
        dfs(root);
        ckmin(tmp, dp[root][1]);
        swap(root, cycle);
        dfs(root);
        ckmin(tmp, dp[root][1]);
        ans += min(tmp, dp[root][1]);
    }
    print(ans, '\n');
    return 0;
}

