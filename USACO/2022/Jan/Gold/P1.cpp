#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int mod = 1e9 + 7;
const int H = 1005;
int n, h[N], dp[N][H], sum[N][H], mn = mod;
int ans = 0;

void solve() {
    memset(dp, 0, sizeof(dp));
    memset(sum, 0, sizeof(sum));
    dp[0][0] = 1;
    for(int i = 1;i<=n;++i) {
        sum[i][0] = (dp[i - 1][0]) % mod;
        for(int j = 1;j<=h[i];++j) {
            sum[i][j] = (sum[i][j - 1] + dp[i - 1][j]) % mod;
        }
        for(int j = 0;j<=h[i];++j) { // final value
            dp[i][j] = (dp[i][j] + sum[i][h[i] - j]) % mod;
        }
    }
    ans = (ans + dp[n][0]) % mod;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    for(int i = 1;i<=n;++i) {
        cin>>h[i];
        mn = min(mn, h[i]);
    }
    if(n % 2 == 0) {
        solve();
        cout<<dp[n][0]<<'\n';
        return 0;
    }
    for(int i = 0;i<=mn;++i) {
        solve();
        for(int i = 1;i<=n;++i) h[i]--;
    }
    cout<<ans<<'\n';
    return 0;
}

