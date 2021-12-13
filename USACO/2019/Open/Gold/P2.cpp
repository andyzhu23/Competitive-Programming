#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
const ll A = 2019201913;
const ll B = 2019201949;
const ll MOD = 2019201997;
int n, k;
using pii = pair<int, int>;
const int N = 7510;

ll dist[N], d[N];
bool vis[N];

int main() {
    freopen("walk.in", "r", stdin);
    freopen("walk.out", "w", stdout);
    scanf("%d %d", &n, &k);
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    for(int i = 1;i<=n;++i) d[i] = 2019201997;
    for(int i = 1;i<=n;++i) {
        int u = 0;
        for(int j = 1;j<=n;++j) {
            if(!vis[j] && (u == 0 || dist[j] < dist[u])) u = j;
        }
        vis[u] = 1;
        for(int v = 1;v<=n;++v) {
            if(v == u) continue;
            if(!vis[v]) {
                ll siz = (A * u % MOD + B * v % MOD) % MOD;
                siz = max(siz, (A * v % MOD + B * u % MOD) % MOD);
                dist[v] = min(dist[v], dist[u] + siz);
                d[v] = min(siz, d[v]);
            }
        }
    }
    sort(d + 1, d + n + 1);
    printf("%lld\n", d[n - k + 1]);
    return 0;
}
