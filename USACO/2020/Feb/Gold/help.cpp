#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int N = 2e5 + 10;
int n, lazy[N], l[N], r[N], p[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("help.in", "r", stdin);
    freopen("help.out", "w", stdout);
    cin>>n;
    for(int i = 1;i<=n;++i) {
        cin>>l[i]>>r[i];
        lazy[l[i]]++;
        lazy[r[i] + 1]--;
    }
    p[0] = 1;
    for(int i = 1;i<=2 * n + 2;++i) {
        lazy[i] += lazy[i - 1];
        p[i] = (p[i - 1] << 1) % MOD;
    }
    ll ans = 0;
    for(int i = 1;i<=n;++i) {
        ans = (ans + p[n - lazy[l[i]]]) % MOD;
    }
    cout<<ans<<'\n';
    return 0;
}