#include <bits/stdc++.h>
#define fir first
#define sec second
#define mp make_pair
#define pb push_back
using namespace std;
using pii = pair<int, int>;
template <typename T> using vec = vector<T>;
using vpii = vec<pii>;
const int N = 1e4 + 10;
int dep[N], f[N][22], dist[N], n, m;
vpii e[N];

int LCA(int u, int v) {
    if(dep[u] < dep[v]) swap(u, v);
    for(int i = 20;i>=0;i--) {
        if(dep[f[u][i]] >= dep[v]) u = f[u][i];
        if(u == v) return u;
    }
    for(int i = 20;i>=0;i--) {
        if(f[u][i] != f[v][i]) {
            u = f[u][i];
            v = f[v][i];
        }
    }
    return f[u][0];
}

void dfs(int u, int fa, int d) {
    dep[u] = dep[fa] + 1;
    f[u][0] = fa;
    dist[u] = dist[fa] + d;
    for(int i = 1;i<=20;i++) {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }
    for(pii v : e[u]) {
        if(v.fir == fa) continue;
        dfs(v.fir, u, v.sec);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 1;i<n;i++) {
        int u, v, w;
        cin>>u>>v>>w;
        e[u].pb(mp(v, w));
        e[v].pb(mp(u, w));
    }
    dfs(1, 0, 0);
    while(m--) {
        int u, v;
        cin>>u>>v;
        cout<<dist[u] + dist[v] - (dist[LCA(u, v)] << 1) <<endl;
    }
    return 0;
}
