#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
const int V = 305;
const int inf = 0x3f3f3f3f;
int n, m, v, e, c[N], d[N], mat[V][V];
double k[N], dp[3][N][N];

template<typename T> void ckmin(T& a, T b) {a = min(a, b);}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>m>>v>>e;
    memset(mat, 0x3f, sizeof(mat));
    for(auto& x : dp) for(auto& y : x) for(auto& z : y) z = inf;
    for(int i = 1;i<=n;++i) cin>>c[i];
    for(int i = 1;i<=n;++i) cin>>d[i];
    for(int i = 1;i<=n;++i) cin>>k[i];
    for(int i = 1;i<=e;++i) {
        int u, v, w;
        cin>>u>>v>>w;
        ckmin(mat[u][v], w);
        ckmin(mat[v][u], w);
    }
    for(int i = 1;i<=v;++i) mat[i][0] = mat[0][i] = mat[i][i] = 0;
    for(int k = 1;k<=v;++k) {
        for(int i = 1;i<=v;++i) {
            for(int j = 1;j<=v;++j) {
                ckmin(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }
    dp[0][n + 1][0] = 0;
    for(int i = n;~i;--i) dp[0][i][0] = dp[0][i + 1][0] + mat[c[i + 1]][c[i]];
    for(int i = n;~i;--i) {
        for(int j = 1;j<=m;++j) {
            // go to c
            ckmin(dp[0][i][j], dp[0][i + 1][j] + mat[c[i + 1]][c[i]]);
            ckmin(dp[0][i][j], (dp[1][i + 1][j] + mat[c[i + 1]][c[i]]) * (1 - k[i + 1]) + (dp[2][i + 1][j] + mat[d[i + 1]][c[i]]) * (k[i + 1]));
            // go to d
            ckmin(dp[1][i][j], dp[0][i + 1][j - 1] + mat[c[i + 1]][c[i]]);
            ckmin(dp[2][i][j], dp[0][i + 1][j - 1] + mat[c[i + 1]][d[i]]);
            ckmin(dp[1][i][j], (dp[1][i + 1][j - 1] + mat[c[i + 1]][c[i]]) * (1 - k[i + 1]) + (dp[2][i + 1][j - 1] + mat[d[i + 1]][c[i]]) * (k[i + 1]));
            ckmin(dp[2][i][j], (dp[1][i + 1][j - 1] + mat[c[i + 1]][d[i]]) * (1 - k[i + 1]) + (dp[2][i + 1][j - 1] + mat[d[i + 1]][d[i]]) * (k[i + 1]));
        }
    }
    double ans = inf;
    for(int i = 0;i<=m;++i) ckmin(ans, dp[0][0][i]);
    printf("%.2f\n", ans);
    return 0;
}