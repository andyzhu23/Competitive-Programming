#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 5010;
using ll = __int128;
int n, m, k, s[N], c[N], f[30];

ll dp[N]; // length i ways.
ll opt[N], tot[N];

ll fp(ll a, ll b) {
    ll c = 1; 
    while(b) {
        if(b & 1) c = (c * a) % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return c;
}

int main() {
    freopen("poetry.in", "r", stdin);
    freopen("poetry.out", "w", stdout);
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1;i<=n;++i) {
        scanf("%d %d", s + i, c + i);
    }
    dp[0] = 1;
    for(int i = 1;i<=k;++i) {
        for(int j = 1;j<=n;++j) {
            if(i >= s[j])
                dp[i] = (dp[i] + dp[i - s[j]]) % mod;
        }
    }
    for(int i = 1;i<=n;++i) {
        opt[c[i]] = (opt[c[i]] + dp[k - s[i]]) % mod;
    }
    for(int i = 1;i<=m;++i) {
        char c; cin>>c;
        f[c - 'A' + 1]++;
    }
    for(int i = 1;i<=27;++i) {
        if(f[i] == 0) {
            tot[i] = 1;
            continue;
        }
        for(int j = 1;j<=n;++j) {
            tot[i] = (tot[i] + fp(opt[j], f[i])) % mod;
        }
    }
    ll ans = 1;
    for(int i = 1;i<=27;++i) {
        ans = (ans * tot[i]) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}
