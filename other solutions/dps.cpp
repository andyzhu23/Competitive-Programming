#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
const int D = 105;
const int mod = 1e9 + 7;
string s;
int n, d, dp[N][D];

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>s;
    n = s.size();
    s = '@' + s;
    cin>>d;
    dp[0][0] = 1;
    for(int i = 1;i<=n;++i) {
        for(int j = 0;j<=d;++j) {
            for(int k = 0;k<=9;++k) {
                dp[i][j] += dp[i - 1][(j - k + d * 10) % d];
                dp[i][j] %= mod;
            }
        }
    }
    int ans = 0, cnt = 0;
    for(int i = 1;i<=n;++i) {
        for(int j = 0;j<s[i] - '0';++j) {
            ans = (ans + dp[n - i][(d - ((cnt + j) % d)) % d]) % mod;
        }
        cnt = (cnt + s[i] - '0') % d;
    }
    cout<<(ans - 1 + (cnt == 0) + mod) % mod<<'\n';
    return 0;
}
