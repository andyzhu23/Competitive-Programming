#include <bits/stdc++.h>
using namespace std;
const int N = 4e2 + 10;
const int INF = 0x3f3f3f3f;
int n, K, st[N][20], dp[N][N], sum[N];

int query(int a, int b) {
    int len = log2(b - a + 1);
    return max(st[a][len], st[b - (1 << len) + 1][len]);
}

int main() {
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);
    scanf("%lld %lld", &n, &K);
    ++K;
    for(int i = 1;i<=n;++i) scanf("%lld", &st[i][0]), sum[i] = sum[i - 1] + st[i][0];
    for(int j = 1;(1 << j)<=n;++j) {
        for(int i = 1;i + (1 << j) - 1 <= n;++i) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1;i<=n;++i) { // first i
        for(int j = 1;j<=K;++j) { // change size by j
            for(int k = 0;k<i;++k) { // last size
                int siz = query(k + 1, i);
                dp[i][j] = min(dp[i][j], dp[k][j - 1] + (i - k) * siz - (sum[i] - sum[k]));
            }
        }
    }
    printf("%lld\n", dp[n][K]);
    return 0;
}
