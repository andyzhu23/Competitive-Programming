#include <bits/stdc++.h>
using namespace std;
const int N = 405;
const int inf = 0x3f3f3f3f;
int n, s, t, in[N][N];

struct solve1 {
    int tot = 1, head[N], cur[N], dist[N];

    struct edge {
        int u, v, w, f, nxt;
    } e[N * N];

    void add(int u, int v, int w) {
        e[++tot] = {u, v, w, 1, head[u]};
        head[u] = tot;
        e[++tot] = {v, u, -w, 0, head[v]};
        head[v] = tot;
    }

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
            for(int i = head[u];i;i=e[i].nxt) if(e[i].f && dist[e[i].v] > dist[u] + e[i].w) {
                dist[e[i].v] = dist[u] + e[i].w;
                if(!inq[e[i].v]) {
                    inq[e[i].v] = 1;
                    q.push(e[i].v);
                }
            }
        }
        inq.reset();
        return vis[t];
    }

    int ans = 0;
    int dfs(int u = s, int f = inf) {
        if(u == t) {
            ans += dist[t];
            return f;
        }
        int ret = 0;
        inq[u] = 1;
        for(int& i = cur[u];i;i=e[i].nxt) if(!inq[e[i].v] && e[i].f && dist[e[i].v] == dist[u] + e[i].w) {
            int tmp = dfs(e[i].v, min(f, e[i].f));
            e[i].f -= tmp;
            e[i ^ 1].f += tmp;
            f -= tmp;
            ret += tmp;
            if(f == 0) break;
        }
        inq[u] = 0;
        if(ret == 0) dist[u] = 0;
        return ret;
    }
    void main() {
        s = 2 * n + 1;
        t = 2 * n + 2;
        for(int i = 1;i<=n;++i) {
            for(int j = 1;j<=n;++j) {
                add(i, j + n, in[i][j]);
            }
        }
        for(int i = 1;i<=n;++i) add(s, i, 0), add(i + n, t, 0);
        while(spfa()) dfs();
        cout<<ans<<'\n';
    }
} s1;

struct solve2 {
    int tot = 1, head[N], cur[N], dist[N];

    struct edge {
        int u, v, w, f, nxt;
    } e[N * N];

    void add(int u, int v, int w) {
        e[++tot] = {u, v, w, 1, head[u]};
        head[u] = tot;
        e[++tot] = {v, u, -w, 0, head[v]};
        head[v] = tot;
    }

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
            for(int i = head[u];i;i=e[i].nxt) if(e[i].f && dist[e[i].v] > dist[u] + e[i].w) {
                dist[e[i].v] = dist[u] + e[i].w;
                if(!inq[e[i].v]) {
                    inq[e[i].v] = 1;
                    q.push(e[i].v);
                }
            }
        }
        inq.reset();
        return vis[t];
    }

    int ans = 0;
    int dfs(int u = s, int f = inf) {
        if(u == t) {
            ans += dist[t];
            return f;
        }
        int ret = 0;
        inq[u] = 1;
        for(int& i = cur[u];i;i=e[i].nxt) if(!inq[e[i].v] && e[i].f && dist[e[i].v] == dist[u] + e[i].w) {
            int tmp = dfs(e[i].v, min(f, e[i].f));
            e[i].f -= tmp;
            e[i ^ 1].f += tmp;
            f -= tmp;
            ret += tmp;
            if(f == 0) break;
        }
        inq[u] = 0;
        if(ret == 0) dist[u] = 0;
        return ret;
    }
    void main() {
        s = 2 * n + 1;
        t = 2 * n + 2;
        for(int i = 1;i<=n;++i) {
            for(int j = 1;j<=n;++j) {
                add(i, j + n, -in[i][j]);
            }
        }
        for(int i = 1;i<=n;++i) add(s, i, 0), add(i + n, t, 0);
        while(spfa()) dfs();
        cout<<-ans<<'\n';
    }
} s2;


int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    s = 2 * n + 1;
    t = 2 * n + 2;
    for(int i = 1;i<=n;++i) {
        for(int j = 1;j<=n;++j) {
            cin>>in[i][j];
        }
    }
    s1.main();
    s2.main();
    return 0;
}
