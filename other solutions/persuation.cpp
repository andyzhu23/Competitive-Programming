#include <bits/stdc++.h>
using namespace std;
// 0x3f3f3f3f was not big enough
const int INF = 0x7f7f7f7f;
int dp[1 << 21], a[21], b[21], n;

int dfs(int x, int mask) {
    if(dp[mask] != -INF) return dp[mask];
    for(int i = 0;i<n;i++) {
        if(mask & (1 << i)) continue;
        if(dp[mask | (1 << i)] == -INF)
            dfs(x + 1, mask | (1 << i));
        dp[mask] = max(dp[mask], dp[mask | (1 << i)] + b[(i - x + (n << 1)) % n] * a[i]);
    }
    return dp[mask];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 0;i<(1 << n) - 1;i++) dp[i] = -INF;
    for(int i = 0;i<n;i++) cin>>a[i];
    for(int i = 0;i<n;i++) cin>>b[i];
    cout<<dfs(0, 0)<<'\n';
    return 0;
}
