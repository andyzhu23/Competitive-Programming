#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;
int n, a[N];
bitset<N> b;

bool get() {
    ll cnt1 = 0, cnt2 = 0;
    for(int i = 1;i<=n;++i) {
        cnt1 += (ll)b[i] * i * (n - i + 1);
        cnt2 += (ll)(b[i] ^ 1) * i * (n - i + 1);
    }
    return cnt2 < cnt1;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    for(int i = 1;i<=n;++i) cin>>a[i];
    int ans = 0;
    for(int i = 0;i<=31;++i) {
        for(int j = 1;j<=n;++j) b[j] = a[j] >> i & 1;
        ans |= get() << i;
    }
    cout<<ans<<'\n';
    return 0;
}
