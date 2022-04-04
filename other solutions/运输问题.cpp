#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N = 205;
const int inf = 0x3f3f3f3f;
int m, n, a[N], b[N], head[N], tot = 1, s, t;

struct edge {
    int u, v, w, f, nxt;
} e[N * N], oe[N * N];

void add(int u, int v, int w, int f) {
    oe[++tot] = {u, v, w, f, head[u]};
    head[u] = tot;
    oe[++tot] = {v, u, -w, 0, head[v]};
    head[v] = tot;
}

int dist[N], cur[N], ans;
bitset<N> inq, vis;

bool spfa() {
    queue<int> q;
    q.push(s);
    inq.reset();
    vis.reset();
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    for(int i = 1;i<=t;++i) cur[i] = head[i];
    while(!q.empty()) {
        int u = q.front(); q.pop();
        inq[u] = 0;
        vis[u] = 1;
        for(int i = head[u];i;i=e[i].nxt) {
            if(e[i].f && dist[e[i].v] > dist[u] + e[i].w) {
                dist[e[i].v] = dist[u] + e[i].w;
                if(!inq[e[i].v]) {
                    inq[e[i].v] = 1;
                    q.push(e[i].v);
                }
            }
        }
    }
    return vis[t];
}

int dfs(int u = s, int f = inf) {
    if(u == t) {
        ans += f * dist[t];
        return f;
    }
    int ret = 0;
    inq[u] = 1;
    for(int& i = cur[u];i;i=e[i].nxt) {
        if(e[i].f && !inq[e[i].v] && dist[e[i].v] == dist[u] + e[i].w) {
            int tmp = dfs(e[i].v, min(f, e[i].f));
            f -= tmp;
            ret += tmp;
            e[i].f -= tmp;
            e[i ^ 1].f += tmp;
            if(f == 0) break;
        }
    }
    inq[u] = 0;
    if(ret == 0) dist[u] = 0;
    return ret;
}

int dinic() {
    ans = 0;
    while(spfa()) dfs();
    return ans;
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>m>>n;
    s = m + n + 1, t = m + n + 2;
    for(int i = 1;i<=m;++i) cin>>a[i];
    for(int i = 1;i<=n;++i) cin>>b[i];
    for(int i = 1;i<=m;++i) {
        for(int j = 1;j<=n;++j) {
            int x; cin>>x;
            add(i, j + m, x, inf);
        }
    }
    for(int i = 1;i<=m;++i) add(s, i, 0, a[i]);
    for(int i = 1;i<=n;++i) add(i + m, t, 0, b[i]);
    for(int i = 2;i<=tot;++i) e[i] = oe[i];
    cout<<dinic()<<'\n';
    for(int i = 2;i<=tot;++i) e[i] = oe[i], e[i].w *= -1;
    cout<<-dinic()<<'\n';
    return 0;
}
