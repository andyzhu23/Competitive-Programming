#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
const int N = 5e4 + 10;
int n, m, f[N][22];

template<typename T1, typename T2>
T1 fast_pow(T1 a, T2 b) {
    if(b == 0) return 1;
    T1 tmp = fast_pow(a, b >> 1);
    if(b & 1) return tmp * tmp % MOD * a % MOD;
    else return tmp * tmp % MOD;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>m;
    int ans = 0;
    for(int i = 1;i<=n;++i) {
        f[i][1] = i;
        int x = i;
        for(int j = 2;j<=22;++j) {
            f[i][j] = (f[i][j - 1] * x % MOD + f[i][j - 1]) % MOD;
            x = x * x % MOD;
        }
        int M = m;
        for(int j = 22;j>=0;--j) {
            if(M >= (1ll << j)) {
                M -= 1ll << j;
                ans += fast_pow(i, M) * f[i][j + 1] % MOD;
                ans %= MOD;
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}
