#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
const int N = 2e5 + 5;
int n, h[N];
ll tot, sz[N];
vector<int> e[N];

struct node {
    int u, v;
    ll w;
};

vector<node> ans;

void get(int u = 1, int fa = 0) {
    sz[u] = h[u] - tot;
    for(int v : e[u]) if(v != fa) {
        get(v, u);
        sz[u] += sz[v];
    }
}

void dfs(int u = 1, int fa = 0) {
    for(int v : e[u]) if(v != fa) {
        if(sz[v] >= 0) dfs(v, u);
        if(sz[v] > 0) ans.pb({v, u, sz[v]});
    }
    for(int v : e[u]) if(v != fa) {
        if(sz[v] < 0) {
            ans.pb({u, v, -sz[v]});
            dfs(v, u);
        }
    }
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    for(int i = 1;i<=n;++i) {
        cin>>h[i];
        tot += h[i];
    }
    tot /= n;
    for(int i = 1;i<n;++i) {
        int u, v;
        cin>>u>>v;
        e[u].pb(v);
        e[v].pb(u);
    }
    get();
    dfs();
    cout<<ans.size()<<'\n';
    for(auto[u, v, w] : ans) cout<<u<<' '<<v<<' '<<w<<'\n';
    return 0;
}