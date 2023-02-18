#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define all(v) v.begin(), v.end()
const int N = 2005;
int n, m;
ll dist[N], ans;

struct edge {
    int u, v, l, c;
    bool operator<(const edge& o) const {
        return c > o.c;
    }
    bool operator==(const edge& o) const {
        return u == o.u && v == o.v && l == o.l && c == o.c;
    }
};
vector<edge> e[N];
vector<edge> ee;

struct cmp {
    bool operator()(const int& a, const int& b) {
        return dist[a] > dist[b];
    }
};
priority_queue<int, vector<int>, cmp> heap;

void dijkstra(int x) {
    memset(dist, 0x3f, sizeof dist);
    dist[x] = 0;
    heap.push(x);
    while(!heap.empty()) {
        int u = heap.top(); heap.pop();
        for(auto[x, v, l, c] : e[u]) if(dist[v] > dist[u] + l) {
            dist[v] = dist[u] + l;
            heap.push(v);
        }
    }
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>m;
    for(int i = 1;i<=m;++i) {
        int u, v, l, c;
        cin>>u>>v>>l>>c;
        e[u].push_back({u, v, l, c});
        e[v].push_back({v, u, l, c});
        ee.push_back({u, v, l, c});
    }
    sort(all(ee), [&](edge& a, edge& b) {
        return a.c > b.c;
    });
    for(auto tmp : ee) {
        auto[u, v, l, c] = tmp;
        for(auto it = e[u].begin();it!=e[u].end();++it) {
            if(*it == tmp) {
                e[u].erase(it);
                break;
            }
        }
        swap(tmp.u, tmp.v);
        for(auto it = e[v].begin();it!=e[v].end();++it) {
            if(*it == tmp) {
                e[v].erase(it);
                break;
            }
        }
        dijkstra(u);
        if(dist[v] > l) {
            e[u].push_back({u, v, l, c});
            e[v].push_back({v, u, l, c});
            ans += c;
        }
    }
    cout<<ans<<'\n';
    return 0;
}