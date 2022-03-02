#include <bits/stdc++.h>
using namespace std;
#define pb push_back
using pii = pair<int, int>;
const int N = 5e5 + 5;
pii e[N];
int n, m, a[N], ans, res[N];
bool vis[N];
vector<int> e2[N];

int f[N];
int Find(int x) {return f[x] == x ? x : f[x] = Find(f[x]);}
void merge(int u, int v) {
    int fu = Find(u);
    int fv = Find(v);
    if(fu != fv) --ans;
    f[fu] = fv;
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>m;
    iota(f, f + n + 1, 0);
    ans = n;
    for(int i = 1;i<=m;++i) {
        int u, v; cin>>u>>v;
        e[i] = {u, v};
    }
    int x; cin>>x;
    for(int i = 1;i<=x;++i) {
        cin>>a[i];
        vis[a[i]] = 1;
    }
    for(int i = 1;i<=m;++i) if(!vis[e[i].first] && !vis[e[i].second]) {
        merge(e[i].first, e[i].second);
    } else {
        if(vis[e[i].first]) {
            e2[e[i].first].pb(e[i].second);
        } 
        if(vis[e[i].second]) {
            e2[e[i].second].pb(e[i].first);
        }
    }
    for(int i = x;~i;--i) {
        res[i] = ans - i;
        for(int v : e2[a[i]]) if(!vis[v]) {
            merge(a[i], v);
        }
        vis[a[i]] = 0;
    }
    for(int i = 0;i<=x;++i) cout<<res[i]<<'\n';
    return 0;
}
