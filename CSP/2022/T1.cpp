#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N = 2505;
const int inf = 0x3f3f3f3f;
int n, m, k, a[N];
#define all(v) v.begin(), v.end()
#define pb push_back
#define fir first
#define sec second
using pii = pair<int, int>;
vector<int> e[N];

int dist[N][N];
vector<int> dp[N];

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>m>>k;
    ++k;
    for(int i = 2;i<=n;++i) cin>>a[i];
    memset(dist, 0x3f, sizeof dist);
    for(int i = 1;i<=n;++i) dist[i][i] = 0;
    while(m--) {
        int u, v;
        cin>>u>>v;
        e[u].pb(v);
        e[v].pb(u);
    }
    for(int i = 1;i<=n;++i) {
        queue<int> q;
        q.push(i);
        dist[i][i] = 0;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int v : e[u]) if(dist[i][v] == inf) {
                dist[i][v] = dist[i][u] + 1;
                q.push(v);
            }
        }
    }
    for(int i = 2;i<=n;++i) if(dist[1][i] <= k) {
        for(int j = 2;j<=n;++j) if(i != j && dist[i][j] <= k) {
            dp[j].pb(i);
        }
    }
    for(int i = 1;i<=n;++i) sort(all(dp[i]), [&](int x, int y) {return a[x] > a[y];});
    int ans = 0;
    for(int i = 2;i<=n;++i) if(!dp[i].empty()) {
        for(int j = 2;j<=n;++j) if(i != j && dist[i][j] <= k) {
            int I = 0;
            if(dp[i][0] == j) ++I;
            if(I == dp[i].size()) continue;
            I = dp[i][I];
            int J = 0;
            while(J < dp[j].size() && (dp[j][J] == i || dp[j][J] == I)) ++J;
            if(J == dp[j].size()) continue;
            J = dp[j][J];
            ans = max(ans, a[i] + a[j] + a[I] + a[J]);
        }
    }
    cout<<ans<<'\n';
    return 0;
}