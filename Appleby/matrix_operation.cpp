#include <bits/stdc++.h>
using namespace std;

const int N = 2000;
const int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int dp[N][N], a[N][N];
int n;

bool ok(int x, int y) {
    return(x > 0 && x <= n && y > 0 && y <= n);
}


int dfs(int x, int y) {
    if(dp[x][y] != -1) return dp[x][y];
    for(int i = 0;i<4;++i) {
        int nxtx = x + dir[i][0];
        int nxty = y + dir[i][1];
        if(!ok(nxtx, nxty)) continue;
        if(a[nxtx][nxty] > a[x][y]) dp[x][y] = max(dp[x][y], dfs(nxtx, nxty) + 1);
    }
    if(dp[x][y] == -1) dp[x][y] = 0;
    return dp[x][y];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    memset(dp, -1, sizeof(dp));
    for(int i = 1;i<=n;++i) {
        for(int j = 1;j<=n;++j) {
            cin>>a[i][j];
        }
    }
    int ans = 0;
    for(int i = 1;i<=n;++i) {
        for(int j = 1;j<=n;++j) {
            ans = max(ans, dfs(i, j));
        }
    }
    cout<<ans<<'\n';

    return 0;
}
