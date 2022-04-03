#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
using ll = long long;
int n, m, ans[N];
ll k;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>m>>k;
    k -= n;
    if(k < 0) {
        puts("-1");
        return 0;
    }
    for(int i = 1;i<=n;++i) {
        int nxt = min({(ll)m - 1, (ll)i - 1, k});
        if(i - nxt - 1 == 0) ans[i] = ans[i - 1] + 1;
        else ans[i] = ans[i - nxt - 1];
        k -= nxt;
    }
    if(k) {
        puts("-1");
        return 0;
    }
    for(int i = 1;i<=n;++i) cout<<ans[i]<<(i == n ? '\n' : ' ');
    return 0;
}
