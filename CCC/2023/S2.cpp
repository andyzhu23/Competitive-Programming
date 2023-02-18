#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;
int n, h[N], ans[N];

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    memset(ans, 0x3f, sizeof ans);
    for(int i = 1;i<=n;++i) cin>>h[i];
    for(int i = 1;i<=n;++i) {
        int val = 0;
        for(int j = 0;i-j>0 && i + j<=n;++j) {
            val += abs(h[i - j] - h[i + j]);
            ans[j * 2 + 1] = min(ans[j * 2 + 1], val);
        }
        int val2 = 0;
        for(int j = 0;i-j>0 && i + j + 1<=n;++j) {
            val2 += abs(h[i - j] - h[i + j + 1]);
            ans[(j + 1) * 2] = min(ans[(j + 1) * 2], val2);
        }
    }
    for(int i = 1;i<=n;++i) cout<<ans[i]<<" \n"[i==n];
    return 0;
}