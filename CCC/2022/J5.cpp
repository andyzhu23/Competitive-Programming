#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define pb push_back
#define x first
#define y second
int n, t;
vector<pii> a;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>t;
    for(int i = 1;i<=t;++i) {
        int x, y;
        cin>>x>>y;
        a.pb({x, y});
    }
    a.pb({0, 0});
    a.pb({n + 1, n + 1});
    sort(a.begin(), a.end(), [&](pii& a, pii& b) {
        return a.x < b.x;
    });
    int ans = 0;
    for(int i = 0;i<a.size();++i) {
        vector<int> b;
        b.pb(0);
        b.pb(n + 1);
        for(int j = i + 1;j<a.size();++j) {
            int mx = 0;
            sort(b.begin(), b.end());
            for(int k = 1;k<b.size();++k) {
                mx = max(mx, b[k] - b[k - 1] - 1);
            }
            ans = max(ans, min(mx, a[j].x - a[i].x - 1));
            b.pb(a[j].y);
        }
    }
    cout<<ans<<'\n';
    return 0;
}
