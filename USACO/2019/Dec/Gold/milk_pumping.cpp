#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 1e3 + 10;
const int INF = 0x3f3f3f3f;
using pii = pair<int, int>;
#define fir first
#define sec second
int n, m, dp[N][N]; // dp[i][u] means with i flow rate, shortest path to u
bool vis[N][N];
struct cmp {
    bool operator() (const pii& a, const pii& b) {
        return dp[a.fir][a.sec] > dp[b.fir][b.sec];
    }
};
priority_queue<pii, vector<pii>, cmp> heap;

struct edge {
    int v, c, f;
};
vector<edge> e[N];
int flow = 0;

template <typename T> inline void ckmin(T& a, T b, int i) {
    if(b == INF) return;
    if((double)flow / (double)a < (double)i / (double)b) a = b, flow = i;
}

int main() {
    freopen("pump.in", "r", stdin);
    freopen("pump.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for(int i = 1;i<=m;++i) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        e[a].pb({b, c, d});
        e[b].pb({a, c, d});
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[1001][1] = 0;
    heap.push((pii){1001, 1});
    while(!heap.empty()) {
        int a = heap.top().fir;
        int u = heap.top().sec;
        heap.pop();
        for(edge& v : e[u]) {
            int f = min(a, v.f);
            if(vis[f][v.v]) continue;
            vis[f][v.v] = 1;
            dp[f][v.v] = dp[a][u] + v.c;
            heap.push((pii){f, v.v});
        }
    }
    int ans = INF;
    for(int i = 0;i<=1000;++i) ckmin(ans, dp[i][n], i);
    printf("%d\n", (int) ((double)flow / ans * 1e6));
    return 0;
}
