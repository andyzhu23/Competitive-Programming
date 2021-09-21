#include <bits/stdc++.h>
using namespace std;
#define int long long
using pii = pair<int, int>;
#define fir first
#define sec second
#define pb push_back
#define mp make_pair
const int N = 1e5 + 10;
int n, c, k, a[N], ctot[N], ktot[N], ans;
vector<pii> e[N];

void dfs(int u, int fa, int dist) {
    ctot[u] = a[u];
    ktot[u] = dist;
    for(pii v : e[u]) {
        if(v.fir == fa) continue;
        dfs(v.fir, u, v.sec);
        ctot[u] += ctot[v.fir];
        ktot[u] += ktot[v.fir];
    }
}

signed main() {
    cin>>n>>c>>k;
    for(int i = 1;i<=n;++i) cin>>a[i];
    for(int i = 1;i<n;++i) {
        int u, v, w;
        cin>>u>>v>>w;
        e[u].pb(mp(v, w));
        e[v].pb(mp(u, w));
    }
    dfs(1, 0, 0);
    for(int i = 2;i<=n;++i) {
        if(ctot[i] >= c && ktot[i] <= k) ans++;
    }
    cout<<ans<<'\n';
    return 0;
}
