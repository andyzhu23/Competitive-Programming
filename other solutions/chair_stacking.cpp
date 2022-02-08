#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;
const ll INF = 1e18;
int n;
ll x[N], y[N], sx[N], sy[N];

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    for(int i = 1;i<=n;++i) cin>>x[i]>>y[i];
    sort(x + 1, x + n + 1);
    sort(y + 1, y + n + 1);
    for(int i = 1;i<=n;++i) {
        sx[i] = sx[i - 1] + x[i];
        sy[i] = sy[i - 1] + y[i];
    }
    ll mnx = INF, mny = INF;
    for(int i = 1;i<=n;++i) {
        mnx = min(mnx, x[i] * i - sx[i] + (sx[n] - sx[i]) - x[i] * (n - i));
        mny = min(mny, y[i] * i - sy[i] + (sy[n] - sy[i]) - y[i] * (n - i));
    }
    cout<<mnx + mny<<'\n';
    return 0;
}
