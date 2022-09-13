#include <bits/stdc++.h>
using namespace std;
#define ins insert
#define fir first
#define sec second
#define int long long
#define ok(v) v >= l - 1 && v <= r
using pii = pair<int, int>;
int n, l, r, y;
const int N = 1e5 + 5;
const int M = 1e6 + 5;
set<int> dis;
unordered_map<int, int> mp;
pii a[N];

int d[M], dfn[M], ans[N];

signed main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>l>>r>>y;
    for(int i = 1;i<=n;++i) {
        int x, v, h;
        cin>>x>>v>>h;
        int len = (h * y - 1) / v;
        a[i] = {x - len, x + len};
        dis.ins(x - len - 1);
        dis.ins(x - len);
        dis.ins(x - len + 1);
        dis.ins(x + len - 1);
        dis.ins(x + len);
        dis.ins(x + len + 1);
    }
    dis.ins(l - 1);
    dis.ins(r);
    int tot = 0;
    for(auto x : dis) if(ok(x)) {
        mp[x] = ++tot;
        dfn[tot] = x;
    }
    for(int i = 1;i<=n;++i) {
        ++d[mp[min(r, max(l - 1, a[i].fir))]];
        --d[mp[min(r, max(l - 1, a[i].sec))] + 1];
    }
    for(int i = 1;i<=tot;++i) d[i] += d[i - 1];
    for(int i = 2;i<=tot;++i) {
        ans[d[i]] += dfn[i] - dfn[i - 1];
    }
    for(int i = 0;i<=n;++i) cout<<(ans[i] += ans[i - 1])<<'\n';
    return 0;
}
