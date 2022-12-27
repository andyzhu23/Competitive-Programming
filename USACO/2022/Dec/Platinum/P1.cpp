#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
using ll = long long;
using pii = pair<int, int>;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int N = 305;
const int NN = N * N;
int n, k, e[N][N];
pii a[NN];
ll ee[N][N], ans[NN], dp[N][N];

void dfs(int u, int cnt) {
    if(cnt >= k) return;
    for(int v = 1;v<=n;++v) {
        if(dp[v][cnt + 1] > dp[u][cnt] + ee[u][v]) {
            dp[v][cnt + 1] = dp[u][cnt] + ee[u][v];
            dfs(v, cnt + 1);
        }
    }
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>k;
    for(int i = 1;i<=n;++i) {
        for(int j = 1;j<=n;++j) {
            cin>>e[i][j];
        }
    }
    memset(ee, 0x3f, sizeof ee);
    memset(dp, 0x3f, sizeof dp);
    dp[1][0] = 0;
    for(int i = 1;i<=n * n;++i) {
        int u, v;
        cin>>u>>v;
        a[i] = {u, v};
    }
    for(int tt = n * n;tt;--tt) {
        auto[u, v] = a[tt];
        ans[tt] = dp[n][k];
        ee[u][v] = e[u][v];
        for(int i = 0;i<k;++i) {
            if(dp[v][i + 1] > dp[u][i] + ee[u][v]) {
                dp[v][i + 1] = dp[u][i] + ee[u][v];
                dfs(v, i + 1);
            }
        }
    }
    for(int i = 1;i<=n * n;++i) cout<<(ans[i] == inf ? -1 : ans[i])<<'\n';
    return 0;
}