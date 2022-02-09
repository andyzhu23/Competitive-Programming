#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;
int n;
ll a[N][3], b[N][3], dp[3][3][N], ans = -1e9; // dp[i][j][k], start at i, end at j, kth index
bool flag;
template <typename T> void ckmax(T& a, T b) {a = max(a, b);}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    for(int i = 1;i<=n;++i) {
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    }
    auto solve = [&]() {
        memset(dp, -0x3f, sizeof(dp));
        dp[0][0][1] = a[1][0];
        dp[1][1][1] = a[1][1];
        dp[2][2][1] = a[1][2];
        for(int i = 2;i<=n;++i) {
            for(int j = 0;j<3;++j) {
                for(int k = 0;k<3;++k) {
                    if(i & 1) {
                        for(int l = 0;l<k;++l) {
                            ckmax(dp[j][k][i], dp[j][l][i - 1] + a[i][k]);
                        }
                    } else {
                        for(int l = k + 1;l<3;++l) {
                            ckmax(dp[j][k][i], dp[j][l][i - 1] + a[i][k]);
                        }
                    }
                }
            }
        }
        for(int i = 0;i<3;++i) {
            for(int j = 0;j<i;++j) {
                ckmax(ans, dp[i][j][n]);
            }
        }
    };
    solve();
    for(int i = 1;i<n;++i) {
        b[i + 1][0] = a[i][0];
        b[i + 1][1] = a[i][1];
        b[i + 1][2] = a[i][2];
    }
    b[1][0] = a[n][0];
    b[1][1] = a[n][1];
    b[1][2] = a[n][2];
    for(int i = 1;i<=n;++i) {
        a[i][0] = b[i][0];
        a[i][1] = b[i][1];
        a[i][2] = b[i][2];
    }
    flag = 1;
    solve();
    cout<<ans<<'\n';
    return 0;
}
