#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, a[N], b[N], ans;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    for(int i = 1;i<=n;++i) cin>>a[i];
    for(int i = 1;i<=n;++i) cin>>b[i];
    for(int i = 1;i<=n;++i) {
        if(a[i] == 1) {
            ans += (a[i - 1] != 1) + (a[i + 1] != 1);
        }
        if(b[i] == 1) {
            ans += (b[i - 1] != 1) + (b[i + 1] != 1);
        }
    }
    for(int i = 1;i<=n;++i) {
        if(i & 1 ^ 1) {
            ans += (a[i] == 1) + (b[i] == 1);
        } else {
            if(a[i] == 1) ans += b[i] != 1;
            if(b[i] == 1) ans += a[i] != 1;
        }
    }
    cout<<ans<<'\n';
    return 0;
}