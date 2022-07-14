#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int K = 1e5 + 5;
const int mod = 1e9 + 7;
int a[N], n, k, dp[N][K], psa[N][K];

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>k;
    for(int i = 1;i<=n;++i) cin>>a[i];
    dp[0][0] = 1;
    for(int i = 1;i<=n;++i) {
        psa[i - 1][0] = dp[i - 1][0];
        for(int j = 1;j<=k;++j)
            psa[i - 1][j] = (psa[i - 1][j - 1] + dp[i - 1][j]) % mod;
        for(int j = 0;j<=k;++j) {
            dp[i][j] = (psa[i - 1][j] - (j - a[i] - 1 < 0 ? 0 : psa[i - 1][j - a[i] - 1]) + mod) % mod;
        }
    }
    cout<<dp[n][k]<<'\n';
    return 0;
}
