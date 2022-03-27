#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 20405;
const int inf = 0x3f3f3f3f;
int n, m, A[N], sum, tot = 1;
int head[N], S, T, cur[N], l[N];
struct edge {
    int u, v, f, nxt;
} e[N];

void add(int u, int v, int w) {
    e[++tot] = {u, v, w, head[u]};
    head[u] = tot;
}

int vis[N];
bitset<N> mark;

bool bfs() {
    queue<int> q;
    q.push(S);
    memset(vis, 0, sizeof(vis));
    vis[S] = 1;
    for(int i = 1;i<=n + 2;++i) cur[i] = head[i];
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i = head[u];i;i = e[i].nxt) if(!vis[e[i].v] && e[i].f > 0) {
            vis[e[i].v] = vis[u] + 1;
            q.push(e[i].v);
        }
    }
    mark.reset();
    return vis[T];
}


int dfs(int u = S, int f = inf) {
    if(u == T) return f;
    int ret = 0;
    mark[u] = 1;
    for(int& i = cur[u];i;i = e[i].nxt) if(vis[e[i].v] == vis[u] + 1 && e[i].f > 0 && !mark[e[i].v]) {
        int tmp = dfs(e[i].v, min(f, e[i].f));
        e[i].f -= tmp;
        e[i ^ 1].f += tmp;
        ret += tmp;
        f -= tmp;
        if(f == 0) break;
    }
    mark[u] = 0;
    if(ret == 0) vis[u] = 0;
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
    cin>>n>>m;
    S = n + 1, T = n + 2;
    for(int i = 1;i<=m;++i) {
        int s, t, lo, up;
        cin>>s>>t>>lo>>up;
        add(s, t, up - lo);
        l[tot] = lo;
        add(t, s, 0);
        A[s] -= lo, A[t] += lo;
    }
    for(int i = 1;i<=n;++i) {
        if(A[i] > 0) {
            add(S, i, A[i]);
            add(i, S, 0);
            sum += A[i];
        } else add(i, T, -A[i]), add(T, i, 0);
    }
    if(dinic() == sum) {
        cout<<"YES\n";
        for(int i = 2;i<=m * 2;i+=2) cout<<e[i ^ 1].f + l[i]<<'\n';
    } else cout<<"NO\n";
    return 0;
}
