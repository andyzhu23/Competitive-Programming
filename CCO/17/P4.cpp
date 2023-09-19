#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 505;
const int MX = 25005;
int n, a[N];
ll dp[2][MX];

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    cin>>n;
    for(int i = 1;i<=n;++i) cin>>a[i];
    sort(a + 1, a + n + 1, greater<int>());
    a[1] = 51;
    dp[1][0] = 1ll << a[1];
    for(int i = 2;i<=n;++i) {
        for(int j = 0;j<MX;++j) if(dp[i&1^1][j]) {
            dp[i&1][j] |= dp[i&1^1][j] | (1ll << a[i]);
            bool flag = 0;
            for(int k = a[1] - 1;~k;--k) if(dp[i&1^1][j] >> k & 1) {
                if(j + k - a[i] < MX)
                    dp[i&1][j + k - a[i]] |= dp[i&1^1][j];
            }
        }
        memset(dp[i&1^1], 0, sizeof dp[i&1^1]);
    }
    for(int i = 0;i<MX;++i) if(dp[n&1][i]) cout<<i<<' ';
    cout<<'\n';
    return 0;
}
