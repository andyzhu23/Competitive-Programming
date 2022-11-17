#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {
    ll n, d, e;
    cin>>n>>d>>e;
    ll x = n - e * d + 2;
    ll lo = 0, hi = x / 2, ans = -1;
    while(lo <= hi) {
        ll mid = lo + hi >> 1;
        if(mid * (x - mid) == n) {
            cout<<mid<<' '<<x - mid<<'\n';
            return;
        } else if(mid * (x - mid) < n) lo = mid + 1;
        else hi = mid - 1;
    }
    cout<<"NO\n";
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t; cin>>t;
    while(t--) solve();

    return 0;
}
