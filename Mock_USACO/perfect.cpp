#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;
using ll = long long;
int n, k, a[N];
unordered_map<int, int> Map;
ll cnt[N];
ll dp[3000][3000];
ll tot = 0, f[N];

bool ok(int a) {
    for(;a > 0;a/=10) {
        if(a % 10 != 6 && a % 10 != 8) return 1;
    }
    return 0;
}

ll fast_pow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }
    return ans;
}

ll c(int i, int j) {
    if(j == 0) return 1ll;
    return f[i] * fast_pow(f[j], MOD - 2) % MOD * fast_pow(f[i - j], MOD - 2) % MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>k;
    f[0] = 1;
    for(int i = 1;i<=n;++i) {
        cin>>a[i];
        f[i] = f[i - 1] * i % MOD;
        if(ok(a[i])) a[i] = 0;
        else if(!Map[a[i]]) Map[a[i]] = ++tot;
    }
    for(int i = 1;i<=n;++i) if(Map[a[i]]) a[i] = Map[a[i]];
    for(int i = 1;i<=n;++i) cnt[a[i]]++;
    for(int i = 0;i<=tot;++i) dp[i][0] = 1;
    for(int i = 1;i<=tot;++i) {
        for(int j = 1;j<=min(i, k);++j) {
            dp[i][j] = (dp[i - 1][j - 1] * cnt[i] % MOD + dp[i - 1][j]) % MOD;
        }
    }
    ll ans = 0;
    for(int i = 0;i<=min(cnt[0], (ll)k);++i) {
        ans += c(cnt[0], i) * dp[tot][k - i] % MOD;
        ans %= MOD;
    }
    cout<<ans<<'\n';
    return 0;
}
