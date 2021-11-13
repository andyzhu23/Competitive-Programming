#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, k, m;

bool ok(ll x) {
    ll n = N;
    ll cnt = 0;
    while(n > 0) {
        ll y = n / x;
        if(y <= m) {
            cnt += (n - 1) / m + 1;
            n = 0;
        } else {
            cnt += (n - x * y + 1) / y + 1;
            n -= ((n - x * y + 1) / y + 1) * y;
        }
    }
    return cnt <= k;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("loan.in", "r", stdin);
    freopen("loan.out", "w", stdout);
    cin>>N>>k>>m;
    ll l = 1, r = 1e12;
    ll ans = 0;
    while(l <= r) {
        ll mid = (l + r) >> 1;
        if(ok(mid)) {
            l = mid + 1;
            ans = mid;
        }
        else r = mid - 1;
    }
    cout<<ans<<'\n';
    return 0;
}