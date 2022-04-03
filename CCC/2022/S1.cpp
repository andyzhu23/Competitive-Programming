#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int n;

signed main() {
    // cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    int ans = 0;
    for(int i = 0;i * 4<=n;++i) {
        int j = n - i * 4;
        if(j % 5 == 0) {
            ans++;
        }
    }
    cout<<ans<<'\n';
    return 0;
}