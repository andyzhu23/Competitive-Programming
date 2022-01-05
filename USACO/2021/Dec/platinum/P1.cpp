#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define lc (rt << 1)
#define rc (rt << 1 | 1)
#define fir first
#define sec second
using ll = long long;
using pii = pair<ll, ll>;
const int N = 5e5 + 10;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int n, k;
vector<pii> e[N];
vector<ll> d1, d2, d3;

void build(int rt, int l, int r) {
    if(l == r) return;
    e[lc].pb({rt, 0}), e[rc].pb({rt, 0});
    int mid = l + r >> 1;
    build(lc, l, mid), build(rc, mid + 1, r);
}

int query(int rt, int l, int r, int pos) {
    if(l == r) return rt;
    int mid = l + r >> 1;
    if(pos <= mid) return query(lc, l, mid, pos);
    else return query(rc, mid + 1, r, pos);
}

void assign(int rt, int l, int r, int x, int y, int c, int p) {
    if(l == x && y == r) {
        e[rt].pb({c > 4 * n ? c : query(1, 1, n, c), p});
        return;
    }
    int mid = l + r >> 1;
    if(y <= mid) assign(lc, l, mid, x, y, c, p);
    else if(x > mid) assign(rc, mid + 1, r, x, y, c, p);
    else assign(lc, l, mid, x, mid, c, p), assign(rc, mid + 1, r, mid + 1, y, c, p);
}

vector<ll> dijkstra(int x) {
    priority_queue<pii, vector<pii>, greater<> > heap;
    vector<ll> dist((N), INF);
    dist[x] = 0;
    heap.push({0, x});
    while(!heap.empty()) {
        pii cur = heap.top();
        heap.pop();
        int u = cur.sec;
        for(auto v : e[u]) {
            if(dist[v.fir] > dist[u] + v.sec) {
                dist[v.fir] = dist[u] + v.sec;
                heap.push({dist[v.fir], v.fir});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>k;
    build(1, 1, n);
    for(int i = 1;i<=k;++i) {
        int c, p, a, b;
        cin>>c>>p>>a>>b;
        assign(1, 1, n, a, b, n * 4 + i, 0);
        e[n * 4 + i].pb({query(1, 1, n, c), p});
    }
    d1 = dijkstra(query(1, 1, n, 1));
    d2 = dijkstra(query(1, 1, n, n));
    for(int i = 1;i <= n;++i) {
        int x = query(1, 1, n, i);
        e[0].pb({x, d1[x] + d2[x]});
    }
    for(int i = 4 * n;i<= 4 * n + k;++i) 
        e[0].pb({i, d1[i] + d2[i]});
    d3 = dijkstra(0);
    for(int i = 1;i<=n;++i) {
        int x = query(1, 1, n, i);
        cout<<(d3[x] == INF ? -1 : d3[x])<<'\n';
    }
    return 0;
}

