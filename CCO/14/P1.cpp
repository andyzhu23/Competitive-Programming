#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
using ll = long long;
int n, dp[N][N];
char c[N][N];

int dfs(int x, int y) {
    if(c[x][y] != '#' || dp[x][y]) return dp[x][y];
    dp[x][y] = min({dfs(x + 1, y - 1), dfs(x + 1, y), dfs(x + 1, y + 1)}) + 1;
    return dp[x][y];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    ll ans = 0;
    for(int i = 1;i<=n;++i) scanf("%s", c[i] + 1);
    for(int i = 1;i<=n;++i) {
        for(int j = 1;j<=n;++j) if(c[i][j] == '#') {
            ans += dfs(i, j);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
