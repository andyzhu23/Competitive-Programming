#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(v) v.begin(), v.end()
#define fir first
#define sec second
using ll = long long;
using pll = pair<ll, ll>;
const int N = 1e5 + 5;
int n, ans[N], tot;
set<pll> bst;
struct triple {ll u, v; int id;};
vector<triple> a;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    for(int i = 1;i<=n;++i) {
        int u, v; cin>>u>>v;
        a.pb({u - v, u + v, i});
    }
    sort(all(a), [&](triple& a, triple& b) {
        if(a.u != b.u) return a.u < b.u;
        return a.v > b.v;
    });
    for(auto[u, v, id] : a) {
        auto x = bst.lower_bound({v, 0});
        if(x == bst.end()) ans[id] = ++tot;
        else {
            ans[id] = ans[(*x).sec];
            bst.erase(x);
        }
        bst.insert({v, id});
    }
    cout<<tot<<'\n';
    for(int i = 1;i<=n;++i) cout<<ans[i]<<'\n';
    return 0;
}
