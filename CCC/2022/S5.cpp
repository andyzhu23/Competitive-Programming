#include <bits/stdc++.h>
using namespace std;
#define pb push_back
using ll = long long;
const int N = 2e5 + 5;
const ll inf = 0x3f3f3f3f;
// 0, from father
// 1, from child
// 2, self is Y

int n, a[N];
ll dp[N][5][5];
char c[N];
vector<int> e[N];

void dfs(int u = 1, int fa = 0) {
    dp[u][0][1] = a[u];
    dp[u][1][1] = a[u];
    dp[u][2][1] = a[u];
    bool flag = 0;
    ll dif = inf;
    ll diff = inf;
    for(int v : e[u]) if(v != fa) {
        dfs(v, u);
        dp[u][0][1] += min({
            dp[v][0][1], dp[v][0][0],
            dp[v][1][1], dp[v][1][0],
            dp[v][2][1], dp[v][2][0],
        });
        dp[u][2][1] += min({
            dp[v][0][1], dp[v][0][0],
            dp[v][1][1], dp[v][1][0],
            dp[v][2][1], dp[v][2][0],
        });
        ll tmp = min({
            dp[v][0][1], dp[v][0][0],
            dp[v][1][1], dp[v][1][0],
            dp[v][2][1], dp[v][2][0],
        });
        if(dp[v][1][1] == tmp || dp[v][2][1] == tmp) flag = 1;
        dif = min(dif, min(dp[v][1][1], dp[v][2][1]) - tmp);
        dp[u][1][1] += tmp;

        dp[u][0][0] += min({
            dp[v][1][1], dp[v][1][0],
            dp[v][2][1], dp[v][2][0],
        });
        dp[u][2][0] += min({
            dp[v][1][1], dp[v][1][0],
            dp[v][2][1], dp[v][2][0],
        });
        tmp = min({
            dp[v][1][1], dp[v][1][0],
            dp[v][2][1], dp[v][2][0],
        });
        diff = min(diff, min(dp[v][1][1], dp[v][2][1]) - tmp);
        dp[u][1][0] += tmp;
    }
    if(!flag) {
        dp[u][1][1] += dif;
        dp[u][1][0] += diff;
    }
    if(c[u] == 'N') {
        dp[u][2][0] = dp[u][2][1] = inf;
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for(int i = 1;i<n;++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].pb(v);
        e[v].pb(u);
    }
    scanf("%s", c + 1);
    for(int i = 1;i<=n;++i) scanf("%d", a + i);
    dfs();
    printf("%lld\n", min({
        dp[1][1][0], dp[1][1][1], 
        dp[1][2][0], dp[1][2][1],
    }));
    return 0;
}
