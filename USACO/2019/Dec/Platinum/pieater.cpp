#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N = 305;
const int M = 1e5 + 10;
using ll = long long;
int n, m, l[M], r[M];
ll dp[N][N], mx[N][N][N], w[M];

template <typename T>
inline void ckmax(T& a, T b) {a = max(a, b);}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("pieaters.in", "r", stdin);
    freopen("pieaters.out", "w", stdout);
    cin>>n>>m;
    for(int i = 1;i<=m;++i) {
        cin>>w[i]>>l[i]>>r[i];
        for(int j = l[i]; j<=r[i]; ++j) 
            ckmax(mx[j][l[i]][r[i]], w[i]);
    }
    for(int i = 1;i<=n;++i) {
        for(int j = i;j;--j) {
            for(int k = i;k<=n;++k) {
                ckmax(mx[i][j][k], mx[i][j][k - 1]);
                ckmax(mx[i][j][k], mx[i][j + 1][k]);
            }
        }
    }
    for(int l = 1;l<=n;++l) {
        for(int i = 1;i + l - 1<=n;++i) {
            int j = i + l - 1;
            for(int k = i;k<=j;++k) 
                ckmax(dp[i][j], dp[i][k] + dp[k + 1][j]);
            for(int k = i;k<=j;++k) 
                ckmax(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + mx[k][i][j]);
        }
    }
    cout<<dp[1][n]<<'\n';
    return 0;
}
