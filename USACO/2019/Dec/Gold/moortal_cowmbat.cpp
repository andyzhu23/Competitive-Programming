#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
using pii = pair<int, int>;
#define fir first
#define sec second

int n, m, k, a[30][30], dp[N], sum[N][30];
char s[N];

int cmp(int a, int b, int c) {
    return dp[a] - sum[a][c] < dp[b] - sum[b][c] ? a : b;
}

int best[30];

int main() {
    freopen("cowmbat.in", "r", stdin);
    freopen("cowmbat.out", "w", stdout);
    scanf("%d %d %d", &n, &m, &k);
    scanf("%s", s + 1);
    for(int i = 1;i<=m;++i) {
        for(int j = 1;j<=m;++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for(int k = 1;k<=m;++k) {
        for(int i = 1;i<=m;++i) {
            for(int j = 1;j<=m;++j) {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for(int i = 1;i<=n;++i) {
        for(int j = 1;j<=m;++j) {
            sum[i][j] = sum[i - 1][j] + a[s[i] - 'a' + 1][j];
        }
    }
    for(int i = k;i<=n;++i) {
        for(int c = 1;c<=m;++c) {
            if(i - k > 0) best[c] = cmp(best[c], i - k, c);
            dp[i] = min(dp[i], dp[best[c]] - sum[best[c]][c] + sum[i][c]);
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}
