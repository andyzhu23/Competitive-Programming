#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 7e6 + 1e5 + 5;
using ll = long long;
int n, m, u, v, t, q, i, j, k;
deque<ll> a, b, c;
vector<ll> ans;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>m>>q>>u>>v>>t;
    for(int i = 1;i<=n;++i) {
        int x; cin>>x;
        a.pb(x);
    }
    sort(a.begin(), a.end(), greater<int>());
    for(int i = 0;i<m;++i) {
        ll mx = 0;
        if(!b.empty()) mx = max(b[0], c[0]);
        if(!a.empty()) mx = max(mx, a[0]);
        mx += q * i;
        ans.pb(mx);
        ll x = mx * u / v;
        ll y = mx - x;
        b.pb(x - (i + 1) * q);
        c.pb(y - (i + 1) * q);
        mx -= q * i;
        if(!a.empty() && a[0] == mx) a.pop_front();
        else if(!b.empty() && b[0] == mx) b.pop_front();
        else c.pop_front();
    }
    for(int i = t - 1;i<ans.size();i+=t) cout<<ans[i]<<" \n"[i + t >= ans.size()];
    if(t >= ans.size()) cout<<'\n';
    for(auto x : b) a.pb(x);
    for(auto x : c) a.pb(x);
    sort(a.begin(), a.end(), greater<int>());
    for(int i = t - 1;i<a.size();i+=t) cout<<a[i] + m * q<<" \n"[i + t >= a.size()];
    return 0;
}