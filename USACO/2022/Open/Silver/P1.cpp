#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int inf = 0x3f3f3f3f;
int v[N], a[N], n;
long long ans;
bitset<N> vis, vis2;

void dfs(int u) {
    if(vis[u]) return;
    if(vis2[u]) {
        int x = u;
        int mn = v[x];
        x = a[x];
        while(x != u) {
            mn = min(mn, v[x]);
            x = a[x];
        }
        ans -= mn;
        return;
    }
    vis2[u] = 1;
    dfs(a[u]);
    vis2[u] = 0;
}

void dfs2(int u) {
    if(vis[u]) return;
    vis[u] = 1;
    dfs2(a[u]);
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    for(int i = 1;i<=n;++i) {
        cin>>a[i]>>v[i];
        ans += v[i];
    }
    for(int i = 1;i<=n;++i) if(!vis[i]) {
        dfs(i);
        dfs2(i);
    }
    cout<<ans<<'\n';
    return 0;
}