#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 305;
int n, d, color[N], dp[N][N << 1], tmp[N << 1];
vector<int> e[N];

void dfs(int u = 0) {
    dp[u][n + color[u]] = 0;
    for(int v : e[u]) {
        dfs(v);
        for(int y = -n;y<=n;++y) tmp[y + n] = dp[u][y + n];
        for(int x = -n;x<=n;++x) {
            int cnt = 0x3f3f3f3f;
            for(int y = min(n, x + n);y>=max(-n, x - n);--y) {
                cnt = min(cnt, tmp[y + n] + dp[v][x - y + n]);
            }
            dp[u][x + n] = cnt;
        }
    }
    dp[u][n] = min(dp[u][n], 1);
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>d;
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 1;i<=n;++i) {
        int u, c;
        cin>>u>>color[u]>>c;
        if(color[u] == 0) color[u] = -1;
        for(int j = 1;j<=c;++j) {
            int v; cin>>v;
            e[u].pb(v);
        }
    }
    dfs();
    cout<<(dp[0][d + n] == 0x3f3f3f3f ? -1 : dp[0][d + n])<<'\n';
    return 0;
}
