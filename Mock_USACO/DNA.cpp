#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

using ull = unsigned long long;
const int N = 5e6 + 5;
const int base = 131;
ull h[N], p[N];
string s;
int n, k;
gp_hash_table<int, int> mp;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>s>>k;
    n = s.size();
    s = '@' + s;
    p[0] = 1;
    for(int i = 1;i<=n;++i) {
        h[i] = h[i - 1] * base + s[i];
        p[i] = p[i - 1] * base;
    }
    for(int i = k;i<=n;++i) {
        ++mp[h[i] - h[i - k] * p[k]];
    }
    int ans = 0;
    for(auto x : mp) {
        ans = max(ans, x.second);
    }
    cout<<ans<<'\n';
    return 0;
}

