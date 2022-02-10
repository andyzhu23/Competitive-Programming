#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 1005;
#define pb push_back
#define fir first
#define sec second
vector<pii> e[N];
const int INF = 0x3f3f3f3f;
int n, m, k, dist[N][20];

struct cmp {
    bool operator() (const pii& a, const pii& b) {
        return dist[a.fir][a.sec] > dist[b.fir][b.sec];
    }
};
priority_queue<pii, vector<pii>, cmp> heap;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>m>>k;
    while(m--) {
        int u, v, w;
        cin>>u>>v>>w;
        e[u].pb({v, w});
        e[v].pb({u, w});
    }
    memset(dist, 0x3f, sizeof(dist));
    dist[1][0] = 0;
    heap.push({1, 0});
    while(!heap.empty()) {
        pii u = heap.top(); heap.pop();
        for(pii v : e[u.fir]) {
            if(u.sec < k && dist[v.fir][u.sec + 1] > dist[u.fir][u.sec]) {
                dist[v.fir][u.sec + 1] = dist[u.fir][u.sec];
                heap.push({v.fir, u.sec + 1});
            }
            if(dist[v.fir][u.sec] > max(dist[u.fir][u.sec], v.sec)) {
                dist[v.fir][u.sec] = max(dist[u.fir][u.sec], v.sec);
                heap.push({v.fir, u.sec});
            }
        }
    }
    cout<<(dist[n][k] == INF ? -1 : dist[n][k])<<'\n';
    return 0;
}
