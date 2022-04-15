#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 405;
const int NN = N * N;
struct edge{int u, v, f, nxt;} e[NN];
int S, T, dist[N], head[N], cur[N], tot = 1, n, f, d, cnt;
bitset<N> inq;

void add(int u, int v, int f) {
    e[++tot] = {u, v, f, head[u]};
    head[u] = tot;
    e[++tot] = {v, u, 0, head[v]};
    head[v] = tot;
}

bool bfs() {
    queue<int> q;
    inq.reset();
    memset(dist, 0x3f, sizeof(dist));
    dist[S] = 0;
    for(int i = 0;i<=cnt;++i) cur[i] = head[i];
    q.push(S);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = 0;
        for(int i = head[u];i;i=e[i].nxt) {
            if(e[i].f && dist[e[i].v] > dist[u] + 1) {
                dist[e[i].v] = dist[u] + 1;
                if(!inq[e[i].v]) {
                    inq[e[i].v] = 1;
                    q.push(e[i].v);
                }
            }
        }
    }
    inq.reset();
    return inf != dist[T];
}

int dfs(int u = S, int f = inf) {
    if(u == T) return f;
    inq[u] = 1;
    int ret = 0;
    for(int& i = cur[u];i;i=e[i].nxt) {
        if(e[i].f && dist[e[i].v] == dist[u] + 1 && !inq[e[i].v]) {
            int tmp = dfs(e[i].v, min(f, e[i].f));
            e[i].f -= tmp;
            f -= tmp;
            e[i ^ 1].f += tmp;
            ret += tmp;
            if(f == 0) break;
        }
    }
    inq[u] = 0;
    if(ret == 0) dist[u] = 0;
    return ret;
}

int dinic() {
    int ans = 0;
    while(bfs()) ans += dfs();
    return ans;
}

int pf[N], pd[N];

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>f>>d;
    S = 0;
    for(int i = 1;i<=f;++i) add(S, pf[i] = ++cnt, 1);
    T = ++cnt;
    for(int i = 1;i<=d;++i) add(pd[i] = ++cnt, T, 1);
    for(int i = 1;i<=n;++i) {
        int a, b;
        cin>>a>>b;
        ++cnt;
        for(int j = 1;j<=a;++j) {
            int x; cin>>x;
            add(pf[x], cnt, 1);
        }
        add(cnt, cnt + 1, 1);
        ++cnt;
        for(int j = 1;j<=b;++j) {
            int x; cin>>x;
            add(cnt, pd[x], 1);
        }
    }
    cout<<dinic()<<'\n';
    return 0;
}
