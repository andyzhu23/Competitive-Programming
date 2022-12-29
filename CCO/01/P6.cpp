#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int inf = 0x3f3f3f3f;
const int N = 205;
const int NN = N * N;
int n, m, must[N], may[N];
int adj[N][N];

int S, T, head[N], cur[N], dist[N], tot = 1;
struct edge {int u, v, f, nxt;} e[NN];
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
    dist[S] = 0;
    q.push(S);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i = head[u];i;i=e[i].nxt) {
            if(e[i].f && dist[e[i].v] > dist[u] + 1) {
                dist[e[i].v] = dist[u] + 1;
                q.push(e[i].v);
            }
        }
    }
    return dist[T] != inf;
}

int dfs(int u = S, int f = inf) {
    if(u == T) return f;
    int ret = 0;
    vis[u] = 1;
    for(int& i = cur[u];i;i=e[i].nxt) {
        if(e[i].f && !vis[e[i].v] && dist[e[i].v] == dist[u] + 1) {
            int tmp = dfs(e[i].v, min(f, e[i].f));
            e[i].f -= tmp;
            f -= tmp;
            e[i ^ 1].f += tmp;
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

void solve(int x) {
    bool flag = 1;
    for(int i = 1;i<=n;++i) if(x != i) {
        flag &= must[x] > may[i];
    }
    if(flag) {
        printf("Candidate %d will become president.\n", x);
        return;
    }
    int cnt = 0;
    S = n + m + 1, T = n + m + 2, tot = 1;
    memset(head, 0, sizeof head);
    for(int i = 1;i<=m;++i) {
        if(!adj[i][x]) {
            for(int j = 1;j<=n;++j) if(adj[i][j]) {
                add(i, m + j, 1);
            }
            add(S, i, 1);
            ++cnt;
        }
    }
    for(int i = 1;i<=n;++i) add(m + i, T, may[x] - 1);
    int tmp = dinic();
    printf(tmp == cnt ? "Candidate %d may become president.\n" : "Candidate %d will not become president.\n", x);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while(1) {
        scanf("%d%d", &m, &n);
        if(m == 0 && n == 0) break;
        memset(adj, 0, sizeof adj);
        memset(must, 0, sizeof must);
        memset(may, 0, sizeof may);
        for(int i = 1;i<=m;++i) {
            int x; 
            scanf("%d", &x);
            for(int j = 1;j<=x;++j) {
                int y;
                scanf("%d", &y);
                adj[i][y] = 1;
                ++may[y];
                if(x == 1) ++must[y];
            }
        }
        for(int i = 1;i<=n;++i) solve(i);
        putchar('\n');
    }
    return 0;
}
