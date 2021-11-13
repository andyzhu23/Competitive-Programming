#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    ll ans = 0;
    for(int i = 1;i<=n;++i) {
        ans += n / i * (n / (n / i) - i + 1);
        i = n / (n / i);
    }
    cout<<ans<<'\n';
    return 0;
}
