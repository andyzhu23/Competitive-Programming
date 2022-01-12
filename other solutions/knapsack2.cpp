#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, W, dp[N];

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>W;
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for(int i = 1;i<=n;++i) {
        int w, v;
        cin>>w>>v;
        for(int j = N - 1;j >= v;--j) dp[j] = min(dp[j], dp[j - v] + w);
    }
    int ans = 0;
    for(int i = 1;i<N;++i) if(dp[i] <= W) ans = i;
    cout<<ans<<'\n';
    return 0;
}
