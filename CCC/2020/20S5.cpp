#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
#define fir first
#define sec second
int n, a[N], cnt[N];
double dp[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for(int i = 1;i<=n;++i) scanf("%d", a + i);
    if(a[1] == a[n]) {
        puts("1");
        return 0;
    }
    dp[a[1]] = 1;
    dp[a[n]] = 0;
    cnt[a[1]]++;
    cnt[a[n]]++;
    double ans = 0.5;
    for(int i = n - 1;i>1;--i) {
        if(cnt[a[i]] == 0) dp[a[i]] = ans;
        ans = (ans * (n - i + 1) + dp[a[i]]) / (n - i + 2);
        ++cnt[a[i]];
    }
    ans = 0;
    for(int i = 1;i<=n;++i) ans += dp[i] * cnt[i] / n;
    printf("%.10f\n", ans);
    return 0;
}
