#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 5;
const int M = 2e4 + 5;

int n, e, a[N], b[N];
ll dp[N][M];

template<typename T>
void ckmax(T& a, T b) {
    a = max(a, b);
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>e;
    for(int i = 1;i<=n;++i) cin>>a[i]>>b[i];
    for(int i = 0;i<e;++i) dp[1][i] = i;
    for(int i = 2;i<=n;++i) {
        ll mx = 0;
        for(int j = 0;j<a[i - 1];++j) ckmax(mx, dp[i - 1][j]);
        for(int j = 0;j<M;++j) {
            if(j >= a[i - 1] + b[i - 1]) ckmax(dp[i][j], dp[i - 1][j]);
            else if(j >= b[i - 1]) ckmax(dp[i][j], dp[i - 1][j - b[i - 1]] + b[i - 1]);
            else if(j + a[i - 1] < M) ckmax(dp[i][j], dp[i - 1][j + a[i - 1]]);
            if(j < b[i - 1]) ckmax(dp[i][j], mx + j);
        }
    }
    ll ans = 0;
    for(auto x : dp[n]) ckmax(ans, x);
    cout<<ans<<'\n';
    return 0;
}

