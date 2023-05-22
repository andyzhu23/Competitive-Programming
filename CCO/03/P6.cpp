#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 1005;
int n, r, tot, in[N];
vector<int> e[N];
set<int> ee[N];
int dfn[N], low[N], c[N], color;
bitset<N> vis;
vector<int> stk;
void tarjan(int u, int fa = 0) {
    dfn[u] = low[u] = ++tot;
    stk.pb(u);
    vis[u] = 1;
    for(int v : e[u]) if(v != fa) {
        if(!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        } else if(vis[v]) low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u]) {
        ++color;
        while(stk.back() != u) {
            c[stk.back()] = color;
            vis[stk.back()] = 0;
            stk.pop_back();
        }
        c[stk.back()] = color;
        vis[stk.back()] = 0;
        stk.pop_back();
    }
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>r;
    for(int i = 1;i<=r;++i) {
        int u, v;
        cin>>u>>v;
        e[u].pb(v);
        e[v].pb(u);
    }
    for(int i = 1;i<=n;++i) if(!dfn[i]) tarjan(i);
    for(int u = 1;u<=n;++u) {
        for(int v : e[u]) if(c[u] != c[v]) {
            ee[c[u]].insert(c[v]);
            ee[c[v]].insert(c[u]);
        }
    }
    int cnt = 0;
    for(int i = 1;i<=color;++i) cnt += ee[i].size() & 1;
    cout<<(cnt + 1) / 2<<'\n';
    return 0;
}
