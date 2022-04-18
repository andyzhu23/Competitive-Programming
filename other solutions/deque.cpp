#include <bits/stdc++.h>
using namespace std;
const int N = 3005;
using ll = long long;
int a[N], n;
ll dp[2][N][N];

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    for(int i = 1;i<=n;++i) {
        cin>>a[i];
        dp[0][i][i] = a[i];
        dp[1][i][i] = -a[i];
    }
    for(int l = 2;l<=n;++l) {
        for(int i = 1;i + l - 1<=n;++i) {
            int j = i + l - 1;
            dp[0][i][j] = max(dp[1][i][j - 1] + a[j], dp[1][i + 1][j] + a[i]);
            dp[1][i][j] = min(dp[0][i][j - 1] - a[j], dp[0][i + 1][j] - a[i]);
        }
    }
    cout<<dp[0][1][n]<<'\n';
    return 0;
}
