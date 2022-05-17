#include <bits/stdc++.h>
using namespace std;
const int N = 15;
using ll = long long;
int k;
ll a[N], b[N], p = 1, ans;

ll exgcd(ll a, ll b, ll& x, ll& y) {
    if(a * b == 0) {
        x = 1, y = 0;
        return a + b;
    }
    ll gcd = exgcd(b, a % b, x, y);
    ll tmp = x - a / b * y;
    x = y;
    y = tmp;
    return gcd;
}

ll fm(ll a, ll b, ll mod) {
    ll c = 0;
    while(b) {
        if(b & 1) c = (c + a) % mod;
        b >>= 1;
        a = (a + a) % mod;
    }
    return c;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &k);
    for(int i = 1;i<=k;++i) scanf("%lld", a + i);
    for(int i = 1;i<=k;++i) scanf("%lld", b + i), p *= b[i];
    for(int i = 1;i<=k;++i) {
        a[i] = (a[i] % b[i] + b[i]) % b[i];
        ll u = p / b[i];
        ll v, y;
        exgcd(u, b[i], v, y);
        v = (v % p + p) % p;
        ans = (ans + fm(fm(u, v, p) % p, a[i], p) % p) % p;
    }
    printf("%lld\n", ans);
    return 0;
}
