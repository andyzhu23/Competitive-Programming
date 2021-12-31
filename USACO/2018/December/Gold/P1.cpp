#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 10;
using pii = pair<int, int>;
#define pb push_back
#define fir first
#define sec second
int n, m, k, dist[N], dist2[N], vis[N], inq[N];
vector<pii> e[N];

struct cmp {
    bool operator()(const int& a, const int& b) {
        return dist[a] > dist[b];
    }
};
priority_queue<int, vector<int>, cmp> heap;
queue<int> q;

void dijkstra() {
    memset(dist, 0x7f, sizeof(dist));
    dist[n] = 0;
    heap.push(n);
    while(!heap.empty()) {
        int u = heap.top(); heap.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(pii v : e[u]) {
            if(dist[v.fir] > dist[u] + v.sec) {
                dist[v.fir] = dist[u] + v.sec;
                heap.push(v.fir);
            }
        }
    }
}

void spfa() {
    memset(dist2, 0x7f, sizeof(dist2));
    dist2[0] = 0, inq[0] = 1;
    q.push(0);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        inq[u] = 0;
        for(pii v : e[u]) {
            if(dist2[v.fir] > dist2[u] + v.sec) {
                dist2[v.fir] = dist2[u] + v.sec;
                if(!inq[v.fir]) inq[v.fir] = 1, q.push(v.fir);
            }
        }
    }
}

int main() {
    freopen("dining.in", "r", stdin);
    freopen("dining.out", "w", stdout);
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1;i<=m;++i) {
        int a, b, t;
        scanf("%d %d %d", &a, &b, &t);
        e[a].pb({b, t});
        e[b].pb({a, t});
    }
    dijkstra();
    while(k--) {
        int a, b;
        scanf("%d %d", &a, &b);
        e[0].pb({a, dist[a] - b});
    }
    spfa();
    for(int i = 1;i<n;++i) {
        putchar(dist[i] >= dist2[i] ? '1' : '0');
        putchar('\n');
    }
    return 0;
}
