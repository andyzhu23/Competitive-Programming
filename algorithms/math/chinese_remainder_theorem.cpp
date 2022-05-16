#include <bits/stdc++.h>
using namespace std;
const int N = 15;
using ll = long long;
ll n, a[N], b[N], u[N], v[N], p = 1, ans;

ll exgcd(ll a, ll b, ll& x, ll& y) {
    if(a * b == 0) {
        x = 1, y = 0;
        return a + b;
    }
    ll gcd = exgcd(b, a % b, x, y);
    ll tmpy = x - a / b * y;
    x = y;
    y = tmpy;
    return gcd;
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    for(int i = 1;i<=n;++i) {
        cin>>a[i]>>b[i];
        p *= a[i];
    }
    for(int i = 1;i<=n;++i) {
        u[i] = p / a[i];
        ll y;
        exgcd(u[i], a[i], v[i], y);
        v[i] = (v[i] + a[i]) % a[i];
        ans = (ans + b[i] * u[i] % p * v[i] % p) % p;
    }
    cout<<ans<<'\n';
    return 0;
}
