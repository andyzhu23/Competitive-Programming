#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int b, p[N], n, l[N], r[N], mn[N], mx[N], f[N], ret, mxx[N], mnn[N], c[N];
using ll = long long;
int ans[N];
vector<int> e[N];

void dfs(int u = 1) {
    for(int v : e[u]) {
        dfs(v);
        mn[u] = min(mn[v], mn[u]);
        mx[u] = max(mx[v], mx[u]);
    }
    mn[u] = min(mn[u], r[u]);
    mx[u] = max(mx[u], l[u]);
}

void dfs2(int u = 1) {
    for(int v : e[u]) {
        dfs2(v);
        mxx[u] = max(mxx[u], mxx[v]);
        mnn[u] = min(mnn[u], mnn[v]);
    }
    int val = (mn[1] + mx[1] - 1) / 2 + 1;
    if(val >= l[u] && val <= r[u]) ans[u] = val;
    else {
        if(val > r[u]) ans[u] = r[u];
        else ans[u] = l[u];
    }
    if(e[u].size())
        ret = max({ret, abs(mxx[u] - ans[u]), abs(mnn[u] - ans[u])});
    mxx[u] = max(ans[u], mxx[u]);
    mnn[u] = min(ans[u], mnn[u]);

}

void solve() {
    cin>>n;
    ret = 0;
    memset(mn, 0x3f, sizeof(mn));
    memset(mx, 0, sizeof(mx));
    memset(mnn, 0x3f, sizeof(mn));
    memset(mxx, 0, sizeof(mx));
    memset(f, 0x3f, sizeof(f));
    memset(c, 0, sizeof(c));
    for(int i = 1;i<=n;++i) e[i].clear();
    for(int i = 2;i<=n;++i) cin>>p[i], e[p[i]].push_back(i);
    for(int i = 1;i<=n;++i) {
        cin>>l[i]>>r[i];
    }
    dfs();
    dfs2();
    cout<<ret<<'\n';
    if(b) for(int i = 1;i<=n;++i) cout<<ans[i]<<(i == n ? '\n' : ' ');
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t; cin>>t>>b;
    while(t--) solve();
    return 0;
}