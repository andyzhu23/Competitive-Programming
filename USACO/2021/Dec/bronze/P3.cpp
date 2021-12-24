#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 55;
int n, k, ok[N][N][N], ok2[N][N][N], ans;

void dfs(int x, int y, int u, bool d) {
    ans += (x == n && y == n);
    if(u == k + 1) return;
    if(d) {
        for(int i = y + 1;i<=n;++i) {
            if(ok[x][y][i]) dfs(x, i, u + 1, d ^ 1);
        }
    }
    else {
        for(int i = x + 1;i<=n;++i) {
            if(ok2[y][x][i]) dfs(i, y, u + 1, d ^ 1);
        }
    }
}

void solve() {
    cin>>n>>k;
    memset(ok, 0, sizeof(ok));
    memset(ok2, 0, sizeof(ok2));
    ans = 0;
    for(int i = 1;i<=n;++i) {
        for(int j = 1;j<=n;++j) {
            char c; cin>>c;
            ok[i][j][j] = c == '.';
            ok2[j][i][i] = c == '.';
        }
    }
    for(int i = 1;i<=n;++i) {
        for(int j = 1;j<=n;++j) {
            for(int k = j + 1;k<=n;++k) {
                ok[i][j][k] = ok[i][j][k - 1] & ok[i][k][k];
                ok2[i][j][k] = ok2[i][j][k - 1] & ok2[i][k][k];
                ok[i][k][j] = ok[i][j][k - 1] & ok[i][k][k];
                ok2[i][k][j] = ok2[i][j][k - 1] & ok2[i][k][k];
            }
        }
    }
    dfs(1, 1, 0, 0);
    dfs(1, 1, 0, 1);
    cout<<ans<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
