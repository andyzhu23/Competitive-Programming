#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 505;
int n, k, dp[N][N];
#define x(i) a[i].first
#define y(i) a[i].second
pii a[N];

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>k;
    int ans = 0;
    for(int i = 1;i<=n;++i) {
        cin>>x(i)>>y(i);
    }
    sort(a + 1, a + n + 1);
    for(int i = 1;i<=n;++i) {
        dp[i][0] = 1;
        for(int j = 1;j<i;++j) if(y(i) >= y(j)) {
            int dist = abs(x(i) - x(j)) + abs(y(i) - y(j)) - 1;
            for(int l = dist;l<=k;++l) {
                dp[i][l] = max(dp[i][l], dp[j][l - dist] + dist + 1);
                ans = max(dp[i][l] + k - l, ans);
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}
