#include <bits/stdc++.h>
using namespace std;
const int N = 4e4 + 5;
const int inf = 0x3f3f3f3f;
struct edge{int u, v, nxt;} e[N];
int head[N], n, tot, sz[N], ans = inf, ret;

void dfs(int u = 1, int fa = 0) {
    sz[u] = 0;
    int tmp = 0;
    for(int i = head[u];i;i=e[i].nxt) {
        int v = e[i].v;
        if(fa == v) continue;
        dfs(v, u);
        sz[u] += sz[v];
        tmp = max(tmp, sz[v]);
    }
    ++sz[u];
    tmp = max(tmp, n - sz[u]);
    if(tmp == ans) ret = min(ret, u);
    if(tmp < ans) {
        ret = u;
        ans = tmp;
    }
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    for(int i = 1;i<n;++i) {
        int u, v;
        cin>>u>>v;
        e[++tot] = {u, v, head[u]};
        head[u] = tot;
        e[++tot] = {v, u, head[v]};
        head[v] = tot;
    }
    dfs();
    cout<<ret<<' '<<ans<<'\n';
    return 0;
}
