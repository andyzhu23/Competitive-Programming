#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e6 + 5;
int n, c, per[N], a[N], psa[N];
ll ans, cnt[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &c);
    int m = c / 2;
    for(int i = 0;i<=c;++i) per[i] = m++;
    for(int i = 1;i<=n;++i) {
        scanf("%d", a + i);
        ++psa[a[i]];
        ++psa[a[i] + c];
        ++cnt[a[i]];
    }
    for(int i = 1;i<=c * 2;++i) psa[i] += psa[i - 1];
    for(int i = 0;i<=c;++i) {
        ans += cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
        ll tmp = psa[per[i]] - psa[i];
        ans += cnt[i] * tmp * (tmp - 1) / 2;
        ans += cnt[i] * (cnt[i] - 1) / 2 * tmp;
    }
    if(per[per[0]] == c) {
        for(int i = 0;i<per[0];++i) {
            ans -= cnt[i] * (cnt[i] - 1) / 2 * cnt[per[i]];
            ans -= cnt[per[i]] * (cnt[per[i]] - 1) / 2 * cnt[i];
        }
    }
    printf("%lld\n", 1ll * n * (n - 1) * (n - 2) / 6 - ans);
    return 0;
}
