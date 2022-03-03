#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 505;
struct edge {
    int u, v, w;
};
vector<edge> e;
int n, m, W, dist[N];


void solve() {
    scanf("%d%d%d", &n, &m, &W);
    memset(dist, 0x3f, sizeof(dist));
    e.clear();
    dist[1] = 0;
    for(int i = 1;i<=m;++i) {
        int u, v, w; 
        scanf("%d%d%d", &u, &v, &w);
        e.pb({u, v, w});
        e.pb({v, u, w});
    }
    for(int i = 1;i<=W;++i) {
        int u, v, w; 
        scanf("%d%d%d", &u, &v, &w);
        e.pb({u, v, -w});
    }
    for(int i = 1;i<=n;++i) {
        for(auto[u, v, w] : e) {
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }
    bool flag = 0;
    for(auto[u, v, w] : e) {
        if(dist[v] > dist[u] + w) {
            dist[v] = dist[u] + w;
            flag = 1;
        }
    }
    puts(flag ? "YES" : "NO");
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t; scanf("%d", &t);
    while(t--) solve();
    return 0;
}
