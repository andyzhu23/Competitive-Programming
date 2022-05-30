#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 5;
int n, dp[N][2], l[N], r[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    l[0] = r[0] = 1;
    for(int i = 1;i<=n;++i) {
        scanf("%d%d", l + i, r + i);
        dp[i][0] = r[i] - l[i] + min(dp[i - 1][0] + abs(l[i - 1] - r[i]), dp[i - 1][1] + abs(r[i - 1] - r[i])) + 1;
        dp[i][1] = r[i] - l[i] + min(dp[i - 1][0] + abs(l[i - 1] - l[i]), dp[i - 1][1] + abs(r[i - 1] - l[i])) + 1;
    }
    printf("%d\n", min(dp[n][0] + n - l[n], dp[n][1] + n - r[n]) - 1);
    return 0;
}
