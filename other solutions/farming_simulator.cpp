#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
const int N = 3e3 + 5;
ll dp[N]; // time it takes for the first i to grow
ll h, mx[N];
pll p[N];
int n;

ll dist(int l, int r) {
    return max((p[r].first - p[l].first) * 3, mx[r]);
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>h;
    for(int i = 1;i<=n;++i) cin>>p[i].first>>p[i].second;
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    sort(p + 1, p + n + 1);
    for(int i = 1;i<=n;++i) {
        memset(mx, 0, sizeof(mx));
        mx[i] = p[i].second;
        dp[i] = min(dp[i], dp[i - 1] + p[i].second + p[i].first - p[i - 1].first);
        for(int j = i + 1;j<=n;++j) {
            mx[j] = max(mx[j - 1] + p[j].first - p[j - 1].first, p[j].second + p[j].first - p[i].first);
//            cout<<i<<' '<<j<<' '<<mx[j]<<'\n';
            dp[j] = min(dp[j], dp[i - 1] + dist(i, j) + p[i].first - p[i - 1].first);
        }
    }
    cout<<dp[n] + h - p[n].first<<'\n';
    return 0;
}
