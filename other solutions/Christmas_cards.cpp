#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
using ll = long long;
ll dp[N];
int n;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    memset(dp, 0x3f, sizeof(dp));
    dp[1] = 0;
    for(int i = 1;i<=n;++i) {
        ll c;
        int d;
        cin>>c>>d;
        for(int j = n;j>i;--j) {
            dp[j] = min(dp[j], dp[max(j - d, i)] + c);
        }
    }
    cout<<dp[n]<<'\n';
    return 0;
}
