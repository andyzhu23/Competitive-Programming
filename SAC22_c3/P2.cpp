#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll m;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>m;
    double l = 0, r = 1e18;
    double ans;
    auto get = [&](double mid) {
        return 12 * mid * mid - 5 * mid + 1;
    };
    while(l <= r) {
        double mid = (l + r) / 2;
        // cout<<mid<<' '<<get(mid)<<' '<<m<<'\n';
        if(get(mid) <= m) ans = mid, l = mid + 0.0000001;
        else r = mid - 0.0000001; 
    }
    printf("%.7f", ans);
    return 0;
}