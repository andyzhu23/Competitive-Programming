#include<bits/stdc++.h>
using namespace std;
const int N = 5001;
int n, dp[2][N];
char s[N], t[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    scanf("%s", s + 1);
    for(int i = 1;i<=n;++i) t[i] = s[n - i + 1];
    for(int i = 1;i<=n;++i) {
        for(int j = 1;j<=n;++j) {
            if(s[i] == t[j]) dp[i & 1][j] = dp[i & 1 ^ 1][j - 1] + 1;
            dp[i & 1][j] = max(dp[i & 1][j], max(dp[i & 1 ^ 1][j], dp[i & 1][j - 1]));
        }
        memset(dp[i & 1 ^ 1], 0, sizeof(dp[i & 1 ^ 1]));
    }
    printf("%d\n", n - dp[n & 1][n]);
    return 0;
}
