#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 405;
const int INF = 0x3f3f3f3f;
struct edge {
    int v, c, w, id;
};
vector<edge> e[N];
int n, m, ans, tot, dist[N], cnt[N];

bitset<N> inq;

inline bool spfa() {
    queue<int> q;
    inq.reset();
    memset(dist, 0x3f, sizeof(dist));
    memset(cnt, 0, sizeof(cnt));
    dist[1] = 0;
    q.push(1);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = 0;
        for(auto[v, c, w, id] : e[u]) {
            if(c > 0 && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if(!inq[v]) {
                    inq[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    inq.reset();
    return dist[n] != INF;
}

inline int dfs(int u = 1, int f = INF) {
    if(u == n) {
        tot += f * dist[u];
        return f;
    }
    int ret = 0;
    inq[u] = 1;
    for(int& i = cnt[u];i<e[u].size();++i) {
        auto&[v, c, w, id] = e[u][i];
        if(!inq[v] && c > 0 && dist[v] == dist[u] + w) {
            int tmp = dfs(v, min(c, f));
            ret += tmp;
            c -= tmp;
            e[v][id].c += tmp;
            f -= tmp;
            if(f == 0) break;
        }
    }
    inq[u] = 0;
    if(ret == 0) dist[u] = INF;
    return ret;
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>m;
    for(int i = 1;i<=m;++i) {
        int s, t, c, w;
        cin>>s>>t>>c>>w;
        e[s].pb({t, c, w, (int)e[t].size()});
        e[t].pb({s, 0, -w, (int)e[s].size() - 1});
    }
    while(spfa()) ans += dfs();
    cout<<ans<<' '<<tot<<'\n';
    return 0;
}
