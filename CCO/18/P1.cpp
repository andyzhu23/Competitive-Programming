#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int a[N], b[N], n, dp[N][N];
string s, t;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>s;
    s = '@' + s;
    for(int i = 1;i<=n;++i) cin>>a[i];
    cin>>t;
    t = '@' + t;
    for(int i = 1;i<=n;++i) cin>>b[i];
    for(int i = 1;i<=n;++i) {
        for(int j = 1;j<=n;++j) {
            if((s[i] == 'W' && t[j] == 'L' && a[i] > b[j]) || (s[i] == 'L' && t[j] == 'W' && a[i] < b[j])) 
                dp[i][j] = dp[i - 1][j - 1] + a[i] + b[j];
            dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
        }
    }
    cout<<dp[n][n]<<'\n';
    return 0;
}
