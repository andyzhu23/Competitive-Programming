#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll p, y, t;

bool ok(ll n) {
    __int128 ret = 0;
    for(int i = 1;i<=y;++i) {
        ret = (ret + n) * (100 + p) / 100;
        if(ret >= t) return 1;
    }
    return ret >= t;
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>p>>y>>t;
    ll lo = 1, hi = t, ans;
    while(lo <= hi) {
        ll mid = lo + hi >> 1;
        if(ok(mid)) ans = mid, hi = mid - 1;
        else lo = mid + 1;
    }
    cout<<ans<<'\n';
    return 0;
}
