#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, m, a[N], b[N], f[N];
int mpa[N], mpb[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>m;
    for(int i = 1;i<=n;++i) {
        cin>>a[i]>>b[i];
        mpa[a[i]]++;
        mpb[b[i]]++;
    }
    for(int i = 0;i<=2 * m;++i) {
        for(int j = 0;j<=i;++j) {
            f[i] += mpa[j] * (mpa[i - j]);
            f[i + 1] -= mpb[j] * (mpb[i - j]);
        }
    }
    for(int i = 1;i<=2 * m;++i) {
        f[i] += f[i - 1];
    }
    for(int i = 0;i<=2 * m;++i) {
        cout<<f[i]<<'\n';
    }
    return 0;
}
