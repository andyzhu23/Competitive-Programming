#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 500;
const int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const ll INF = 1e18;
int a[N][N], n, m, id[N][N], s, t, level[N];
ll e[N][N];

bool bfs() {
    queue<int> q;
    memset(level, 0, sizeof(level));
    q.push(s);
    level[s] = 1;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v = s;v<=t;++v) if(e[u][v] && !level[v]) {
            level[v] = level[u] + 1;
            q.push(v);
        }
    }
    return level[t];
}

int dfs(int u = s, ll f = INF) {
    if(u == t) return f;
    ll ret = 0;
    for(int v = s;v<=t;++v) if(e[u][v] && level[v] == level[u] + 1) {
        int mn = dfs(v, min(f, e[u][v]));
        e[u][v] -= mn;
        e[v][u] += mn;
        ret += mn;
        f -= mn;
        if(!f) break;
    }
    if(ret == 0) level[u] = -1;
    return ret;
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>m;
    int ans = 0;
    for(int i = 1;i<=n;++i) {
        for(int j = 1;j<=m;++j) {
            cin>>a[i][j];
            ans += a[i][j];
            id[i][j] = (i - 1) * m + j;
        }
    }
    t = n * m + 1;
    for(int i = 1;i<=n;++i) {
        for(int j = 1;j<=m;++j) if(i + j & 1) {
            e[0][id[i][j]] = a[i][j];
            for(int k = 0;k<4;++k) {
                int nx = i + dir[k][0];
                int ny = j + dir[k][1];
                if(nx > 0 && nx <= n && ny > 0 && ny <= m) 
                    e[id[i][j]][id[nx][ny]] = INF;
            }
        } else e[id[i][j]][t] = a[i][j];
    }
    while(bfs()) ans -= dfs();
    cout<<ans<<'\n';
    return 0;    
}
