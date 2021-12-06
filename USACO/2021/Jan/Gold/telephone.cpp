#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define all(v) v.begin(), v.end()
using pii = pair<int, int>;
#define fir first
#define sec second
const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const int K = 60;
int n, k, b[N], dist[N];
bool a[K][K], vis[N];

vector<pii> e[N];
vector<int> cow[K];

struct cmp {
    bool operator() (const int& a, const int& b) {
        return dist[a] > dist[b];
    }
};

priority_queue<int, vector<int>, cmp> pq;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    memset(dist, 0x3f, sizeof(dist));
    scanf("%d %d", &n, &k);
    for(int i = 1;i<=n;++i) {
        scanf("%d", b + i);
        cow[b[i]].pb(i);
    }
    for(int i = 1;i<=k;++i) {
        for(int j = 1;j<=k;++j) {
            char c = getchar();
            while(!isdigit(c)) c = getchar();
            a[i][j] = c - '0';
        }
    }
    for(int i = 1;i<=n;++i) {
        for(int j = 1;j<=k;++j) {
            if(a[b[i]][j]) {
                auto x = ub(all(cow[j]), i);
                if(x != cow[j].end()) e[i].pb({*x, *x - i});
                auto y = lb(all(cow[j]), i);
                if(y != cow[j].begin()) e[i].pb({*(y - 1), i - *(y - 1)});
            }
        }
        if(a[b[i]][b[n]]) e[i].pb({n, n - i});
    }
    pq.push(1);
    vis[1] = 1;
    dist[1] = 0;
    while(!pq.empty()) {
        int u = pq.top(); pq.pop();
        vis[u] = 1;
        for(pii v : e[u]) {
            if(vis[v.fir]) continue;
            if(dist[v.fir] > dist[u] + v.sec) {
                dist[v.fir] = dist[u] + v.sec;
                pq.push(v.fir);
            }
        }
    }
    printf("%d\n", dist[n] == INF ? -1 : dist[n]);
    return 0;
}
