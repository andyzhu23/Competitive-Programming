#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
int n, k, a[30][30], dist[30], ans = 1;
string s[N];

void dfs(int u) {
    for(int v = 1;v<=k;++v) {
        if(a[u][v]) {
            dist[v] = dist[u] + 1;
            ans = max(ans, dist[v]);
            dfs(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>k;
    memset(a, -1, sizeof(a));
    for(int i = 1;i<=k;++i) {
        a[i][i] = 0;
    }
    for(int i = 1;i<=n;++i) {
        cin>>s[i];
        s[i] = '@' + s[i];
        for(int j = 1;j<=k;++j) {
            for(int l = 1;l<=j;++l) {
                a[s[i][j] - 'A' + 1][s[i][l] - 'A' + 1] = 0;
            }
        }
        
    }
    for(int i = 1;i<=k;++i) {
        memset(dist, 0, sizeof(dist));
        dist[i] = 1;
        dfs(i);
    }
    cout<<ans<<'\n';
    return 0;
}