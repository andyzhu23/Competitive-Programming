#include <bits/stdc++.h>
using namespace std;
#define pb push_back

const int N = 1e5 + 5;

int x, y, g;
set<pair<string, string> > u, v;

signed main() {
    // cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>x;
    int ans = 0;
    for(int i = 1;i<=x;++i) {
        string a, b;
        cin>>a>>b;
        u.insert({max(a, b), min(a, b)});
    }
    cin>>y;
    for(int i = 1;i<=y;++i) {
        string c, d;
        cin>>c>>d;
        v.insert({max(c, d), min(c, d)});
    }
    cin>>g;
    for(int i = 1;i<=g;++i) {
        string a, b, c;
        cin>>a>>b>>c;
        if(u.count({max(a, b), min(a, b)})) {
            u.erase({max(a, b), min(a, b)});
        } else if(v.count({max(a, b), min(a, b)})) {
            ++ans;
        }
        if(u.count({max(c, b), min(c, b)})) {
            u.erase({max(c, b), min(c, b)});
        } else if(v.count({max(c, b), min(c, b)})) {
            ++ans;
        }
        if(u.count({max(a, c), min(a, c)})) {
            u.erase({max(a, c), min(a, c)});
        } else if(v.count({max(a, c), min(a, c)})) {
            ++ans;
        }
    }
    cout<<ans + u.size()<<'\n';
    return 0;
}