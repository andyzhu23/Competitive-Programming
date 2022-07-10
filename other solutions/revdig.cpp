#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
const int inf = 0x3f3f3f3f;
int m, n, tot = 1, head[N], dist[N], cur[N], S, T;

struct node {int u, v, f, nxt;} e[N * 100];

void add(int u, int v, int f) {
    e[++tot] = {u, v, f, head[u]};
    head[u] = tot;
    e[++tot] = {v, u, 0, head[v]};
    head[v] = tot;
}

bitset<N> vis;
bool bfs() {
    queue<int> q;
    vis.reset();
    memset(dist, 0x3f, sizeof dist);
    memcpy(cur, head, sizeof cur);
    q.push(S);
    vis[S] = 1;
    dist[S] = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i = head[u];i;i=e[i].nxt) {
            if(e[i].f && !vis[e[i].v]) {
                dist[e[i].v] = dist[u] + 1;
                vis[e[i].v] = 1;
                q.push(e[i].v);
            }
        }
    }
    vis.reset();
    return dist[T] != inf;
}

int dfs(int u = 1, int f = inf) {
    if(u == T) return f;
    int ret = 0;
    vis[u] = 1;
    for(int& i = cur[u];i;i=e[i].nxt) {
        if(e[i].f && !vis[e[i].v] && dist[e[i].v] == dist[u] + 1) {
            int tmp = dfs(e[i].v, min(f, e[i].f));
            e[i].f -= tmp;
            e[i ^ 1].f += tmp;
            f -= tmp;
            ret += tmp;
            if(f == 0) break;
        }
    }
    vis[u] = 0;
    if(ret == 0) dist[u] = 0;
    return ret;
}

int dinic() {
    int ans = 0;
    while(bfs()) ans += dfs();
    return ans;
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>m>>n;
    S = 1, T = m * 2 + 1;
    for(int i = 1;i<=m;++i) {
        int x; cin>>x;
        if(x == 0) add(i, T, inf);
        else add(i, i + m, x);
    }
    for(int i = 1;i<=n;++i) {
        int u, v; cin>>u>>v;
        add(u + m, v, inf);
    }
    cout<<dinic()<<'\n';
    return 0;
}
