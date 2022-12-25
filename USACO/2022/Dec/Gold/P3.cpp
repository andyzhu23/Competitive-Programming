#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define lb lower_bound
using pii = pair<int, int>;
using ll = long long;
const int N = 1e5 + 5;

int n, m, in[N], dfn[N], rnk[N], sz[N], f[N];
vector<int> e[N];
set<pii> bst;

int Find(int x) {return f[x] == x ? x : f[x] = Find(f[x]);}
void merge(int u, int v) {
    int fu = Find(u);
    int fv = Find(v);
    if(fu == fv) return;
    f[fu] = fv;
    sz[fv] += sz[fu];
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>m;
    for(int i = 1;i<=m;++i) {
        int u, v;
        cin>>u>>v;
        e[u].pb(v);
        e[v].pb(u);
        ++in[u];
        ++in[v];
    }
    for(int i = 1;i<=n;++i) {
        bst.insert({in[i], i});
        sz[i] = 1;
        f[i] = i;
    }
    for(int i = 1;i<=n;++i) {
        auto[uu, u] = *bst.begin();
        bst.erase(bst.begin());
        dfn[i] = u;
        rnk[u] = i;
        for(int v : e[u]) if(!rnk[v]) {
            bst.erase({in[v], v});
            bst.insert({--in[v], v});
        }
    }
    ll ans = 0;
    for(int i = n;i;--i) {
        int u = dfn[i];
        int cnt = 0;
        for(int v : e[u]) if(rnk[u] < rnk[v]) {
            merge(u, v);
            ++cnt;
        }
        ans = max(ans, 1ll * sz[Find(u)] * cnt);
    }
    cout<<ans<<'\n';
    return 0;
}
