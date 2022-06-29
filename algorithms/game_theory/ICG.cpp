#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 2005;
int n, m, k, sg[N];
bitset<N> vis;
vector<int> e[N];

int dfs(int u) {
    if(vis[u]) return sg[u];
    vis[u] = 1;
    sg[u] = 0;
    unordered_set<int> tmp; 
    for(int v : e[u]) tmp.insert(dfs(v));
    while(tmp.count(sg[u])) ++sg[u];
    return sg[u];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1;i<=m;++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].pb(v);
    }
    for(int i = 1;i<=n;++i) dfs(i);
    int ans = 0;
    for(int i = 1;i<=k;++i) {
        int x;
        scanf("%d", &x);
        ans ^= sg[x];
    }
    puts(ans ? "win" : "lose");
    return 0;
}
