#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 55;
const int mod = 1e9 + 7;
int n;
ll k;

struct mat {
    ll a[N][N];
    mat operator*(const mat& other) const {
        mat ans;
        memset(ans.a, 0, sizeof ans.a);
        for(int k = 1;k<=n;++k) {
            for(int i = 1;i<=n;++i) {
                for(int j = 1;j<=n;++j) {
                    ans.a[i][j] = (ans.a[i][j] + a[i][k] * other.a[k][j] % mod) % mod;
                }
            }
        }
        return ans;
    }
} dp[70];

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>k;
    for(int i = 1;i<=n;++i) {
        for(int j = 1;j<=n;++j) {
            cin>>dp[0].a[i][j];
        }
    }
    for(int i = 1;i<70;++i) dp[i] = dp[i - 1] * dp[i - 1];
    mat ans;
    for(int i = 1;i<=n;++i) ans.a[i][i] = 1;
    for(int i = 62;~i;--i) if((1ll << i) <= k) {
        ans = ans * dp[i];
        k -= 1ll << i;
    }
    ll ret = 0;
    for(int i = 1;i<=n;++i) {
        for(int j = 1;j<=n;++j) {
            ret = (ret + ans.a[i][j]) % mod;
        }
    }
    cout<<ret<<'\n';
    return 0;
}
