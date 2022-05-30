#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 3005;
int n, k, q, a[N], vis[N];

bool ret[N][N], flag, mark[N][N];

vector<int> e[N];

void dfs(int u) {
    for(int v : e[u]) if(vis[v] != 2) {
        if(vis[v] == 1 || flag) {
            // cout<<u<<' '<<v<<'\n';
            flag = 1;
            return;
        }
        vis[v] = 1;
        dfs(v);
        vis[v] = 0;
    }
}

void dfs2(int u) {
    vis[u] = 2;
    for(int v : e[u]) if(vis[v] != 2) {
        vis[v] = 2;
        dfs(v);
    }
}

bool ok(int l, int r) {
    flag = 0;
    for(auto& x : e) x.clear();
    memset(vis, 0, sizeof(vis));
    for(int i = l + 1;i<=r;++i) {
        if(i & 1) {
            if(!mark[a[i]][a[i - 1]]) e[a[i]].pb(a[i - 1]);
            mark[a[i]][a[i - 1]] = 1;
        } else {
            if(!mark[a[i - 1]][a[i]]) e[a[i - 1]].pb(a[i]);
            mark[a[i - 1]][a[i]] = 1;
        }
    }
    for(int i = l;i<=r;++i) if(!vis[a[i]]) dfs(a[i]), dfs2(a[i]);
    for(int i = l + 1;i<=r;++i) {
        mark[a[i]][a[i - 1]] = mark[a[i - 1]][a[i]] = 0;
    }
    return !flag;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d%d", &n, &k, &q);
    for(int i = 1;i<=n;++i) scanf("%d", a + i);
    for(int l = 1, r = 1;r<=n;++r) {
        while(l < r && !ok(l, r)) ++l;
        for(int i = l;i<=r;++i) ret[i][r] = 1;
    }
    while(q--) {
        int x, y; scanf("%d%d", &x, &y);
        puts(ret[x][y] ? "YES" : "NO");
    }
    return 0;
}
