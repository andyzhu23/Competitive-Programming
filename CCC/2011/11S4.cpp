#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;

const int N = 20;

struct node {int u, v, f, nxt;} e[100];
int tot = 1, head[N], S = 0, T = 17, cur[N], dist[N];
bitset<N> vis;

void add(int u, int v, int f) {
    e[++tot] = {u, v, f, head[u]};
    head[u] = tot;
    e[++tot] = {v, u, 0, head[v]};
    head[v] = tot;
}

bool bfs() {
    queue<int> q;
    memset(dist, 0x3f, sizeof dist);
    memcpy(cur, head, sizeof cur);
    q.push(S);
    vis[S] = 1;
    dist[S] = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i = head[u];i;i=e[i].nxt) {
            if(e[i].f && !vis[e[i].v]) {
                vis[e[i].v] = 1;
                dist[e[i].v] = dist[u] + 1;
                q.push(e[i].v);
            }
        }
    }
    vis.reset();
    return dist[T] != inf;
}

int dfs(int u = S, int f = inf) {
    if(u == T) return f;
    vis[u] = 1;
    int ret = 0;
    for(int& i = cur[u];i;i=e[i].nxt) {
        if(e[i].f && dist[e[i].v] == dist[u] + 1 && !vis[e[i].v]) {
            int tmp = dfs(e[i].v, min(f, e[i].f));
            e[i].f -= tmp;
            e[i ^ 1].f += tmp;
            f -= tmp;
            ret += tmp;
            if(f == 0) break;
        }
    }
    if(ret == 0) dist[u] = 0;
    vis[u] = 0;
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
    for(int i = 1;i<=8;++i) {
        int x; cin>>x;
        add(S, i, x);
    }
    for(int i = 1;i<=8;++i) {
        int x; cin>>x;
        add(i + 8, T, x);
    }
    for(int i = 9;i<=16;++i) add(1, i, inf);
    for(int i = 10;i<=16;i+=2) add(2, i, inf);
    add(3, 11, inf);
    add(3, 12, inf);
    add(4, 12, inf);
    add(5, 13, inf);
    add(5, 14, inf);
    add(6, 14, inf);
    for(int i = 1;i<=8;i+=2) add(i, 15, inf);
    for(int i = 1;i<=8;++i) add(i, 16, inf); 
    cout<<dinic()<<'\n';
    return 0;
}
