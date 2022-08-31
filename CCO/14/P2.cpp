#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 1e5 + 5;
const int inf = 0x3f3f3f3f;
using pii = pair<int, int>;
int n, m, A, B, d[N], ans[N];
struct edge {
    int x, y, l, c;
};
vector<edge> es;
vector<vector<pii> > e(N), ee(N);

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>m>>A>>B;
    for(int i = 1;i<=m;++i) {
        int x, y, l, c;
        cin>>x>>y>>l>>c;
        es.pb({x, y, l, c});
        e[x].pb({y, l});
        ee[y].pb({x, l});
    }
    auto dijkstra = [&](vector<vector<pii> >& e, int S) {
        vector<int> dist(N, inf);
        priority_queue<pii, vector<pii>, greater<pii> > heap;
        dist[S] = 0;
        heap.push({dist[S], S});
        while(!heap.empty()) {
            auto[x, u] = heap.top(); heap.pop();
            for(auto[v, w] : e[u]) {
                if(dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    heap.push({dist[v], v});
                }
            }
        }
        return dist;
    };
    auto a = dijkstra(e, A);
    auto b = dijkstra(ee, B);
    int Q; cin>>Q;
    vector<pii> q;
    for(int i = 1;i<=Q;++i) {
        int D; cin>>D;
        q.pb({D, i});
    }
    sort(q.begin(), q.end());
    for(auto[x, y, l, c] : es) {
        int dist = a[x] + b[y] + l;
        d[lower_bound(q.begin(), q.end(), (pii){dist, 0}) - q.begin()] += c;
    }
    for(int i = 0;i<Q;++i) {
        if(i) d[i] += d[i - 1];
        ans[q[i].second] = d[i];
    }
    for(int i = 1;i<=Q;++i) cout<<ans[i]<<'\n';
    return 0;
}
