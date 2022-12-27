#include <bits/stdc++.h>
using namespace std;
const int N = 305;
const int inf = 0x3f3f3f3f;
int n, r[N][N], ans[N];

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    for(int i = 1;i<=n;++i) {
        for(int j = i;j<=n;++j) {
            cin>>r[i][j];
        }
    }
    auto ok = [&](int n) {
        if(ans[n] > inf || ans[n] < -inf) return false;
        int mx = ans[n], mn = ans[n];
        bool flag = 1;
        for(int i = n - 1;i;--i) {
            mx = max(mx, ans[i]);
            mn = min(mn, ans[i]);
            flag &= mx - mn == r[i][n];
        }
        return flag;
    };
    for(int i = 2;i<=n;++i) {
        ans[i] = ans[i - 1] - r[i - 1][i];
        if(ok(i)) continue;
        ans[i] = ans[i - 1] + r[i - 1][i];
    }
    for(int i = 1;i<=n;++i) cout<<ans[i]<<" \n"[i==n];
    return 0;
}