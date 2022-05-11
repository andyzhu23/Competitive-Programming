#include <bits/stdc++.h>
using namespace std;
const int N = 1002;
const int M = 202;
const int mod = 1e9 + 7;
using ll = long long;
// uses K substrings, first i in A match first j in B
int n, m, K;
// dp don't end current, f end current
ll dp[2][M][M], f[2][M][M];
string s, t;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>m>>K>>s>>t;
    s = '@' + s;
    t = '@' + t;
    dp[0][0][0] = 1;
    for(int i = 1;i<=n;++i) {
        dp[i & 1][0][0] = 1;
        for(int j = 1;j<=m;++j) {
            for(int k = 1;k<=K;++k) {
                if(s[i] == t[j]) f[i & 1][j][k] = (f[i & 1 ^ 1][j - 1][k] + dp[i & 1 ^ 1][j - 1][k - 1]) % mod;
                else f[i & 1][j][k] = 0;
                dp[i & 1][j][k] = (dp[i & 1 ^ 1][j][k] + f[i & 1][j][k]) % mod;
            }
        }
        memset(dp[i & 1 ^ 1], 0, sizeof(dp[i & 1 ^ 1]));
    }
    cout<<dp[n & 1][m][K]<<'\n';
    return 0;
}
