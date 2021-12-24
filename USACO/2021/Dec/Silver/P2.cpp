#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
#define int long long
using ll = long long;

int n, m, f[N];
ll mn1[N], mnn[N];

int Find(int x) {return f[x] == x ? x : f[x] = Find(f[x]);}

void merge(int u, int v) {
    int fu = Find(u);
    int fv = Find(v);
    f[fu] = fv;
}

void solve() {
    cin>>n>>m;
    memset(mn1, 0x3f, sizeof(mn1));
    memset(mnn, 0x3f, sizeof(mnn));
    for(int i = 0;i<N;++i) f[i] = i;
    for(int i = 1;i<=m;++i) {
        int a, b;
        cin>>a>>b;
        merge(a, b);
    }
    if(Find(n) == Find(1)) {
        cout<<'0'<<'\n';
        return;
    }
    int last1 = 0x3f3f3f3f3f3f3f3f, lastn = 0x3f3f3f3f3f3f3f3f;
    mn1[Find(1)] = mnn[Find(n)] = 0;
    for(int i = 1;i<=n;++i) {
        if(Find(i) == Find(1)) last1 = i;
        else if(Find(i) == Find(n)) lastn = i;
        mn1[Find(i)] = min(mn1[Find(i)], (ll)abs(last1 - i));
        mnn[Find(i)] = min(mnn[Find(i)], (ll)abs(lastn - i));
    }
    for(int i = n;i;--i) {
        if(Find(i) == Find(1)) last1 = i;
        else if(Find(i) == Find(n)) lastn = i;
        mn1[Find(i)] = min(mn1[Find(i)], (ll)abs(last1 - i));
        mnn[Find(i)] = min(mnn[Find(i)], (ll)abs(lastn - i));
    }
    ll ans = 0x3f3f3f3f3f3f3f3f;
    for(int i = 1;i<=n;++i) {
        ans = min(ans, mn1[Find(i)] * mn1[Find(i)] + mnn[Find(i)] * mnn[Find(i)]);
    }
    cout<<ans<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
