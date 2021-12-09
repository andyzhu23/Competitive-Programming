#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define pb push_back

const int MX = 1e6 + 10;
const int N = 1e5 + 10;
using ll = long long;
int n, a[N], cnt[MX], mx;
ll sum[MX];

template<typename T> 
inline void ckmax(T& a, T b) {a = max(a, b);}

ll gets(ll x) {
    if(x > mx) return sum[mx];
    return sum[x];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for(int i = 1;i<=n;++i) {
        scanf("%d", a + i);
        cnt[a[i]]++;
        ckmax(mx, a[i]);
    }
    ll ans = 0;
    for(int i = 1;i<=mx;++i) 
        sum[i] = sum[i - 1] + cnt[i];
    for(int x = 1;x<=mx;++x) {
        vector<int> odd;
        for(int t = 1;t * x <= mx;++t) {
            if((gets(1ll * x * (t + 1) - 1) - gets(1ll * x * t - 1)) & 1) odd.pb(t);
        }
        if((odd.size() == 1 && odd[0] == 1) || (odd.size() == 2 && odd[0] == odd[1] - 1)) 
            ans += gets(1ll * x * (odd.back() + 1) - 1) - gets(1ll * x * odd.back() - 1);
    }
    printf("%lld\n", ans);
    return 0;
}
