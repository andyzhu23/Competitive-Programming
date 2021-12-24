#include <bits/stdc++.h>
using namespace std;

string s;
const int N = 5e5 + 10;
using ll = long long;
int n, a[N];
ll siz[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>s;
    for(int i = 0;i<s.size();++i) {
        a[i + 1] = s[i] == 'G' ? 1 : 0;
    }
    int l = 0;
    a[0] = -1;
    a[n + 1] = -1;
    for(int i = 1;i<=n + 1;++i) {
        if(a[i] != a[i - 1]) {
            for(int j = l;j<=i;++j) siz[j] = i - 1 - l + 1;
            l = i;
        }
    }
    ll ans = 0;
    for(int i = 2;i<n;++i) {
        int prev = ans;
        if(siz[i] == 1) ans += siz[i - 1] * siz[i + 1];
        if(a[i] != a[i - 1]) ans += siz[i - 1] - 1;
        if(a[i] != a[i + 1]) ans += siz[i + 1] - 1;
    }
    if(a[1] != a[2]) ans += siz[2] - 1;
    if(a[n] != a[n - 1]) ans += siz[n - 1] - 1;
    cout<<ans<<'\n';
    return 0;
}
