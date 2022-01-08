#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, dp[N][N][N], a[N][N];
int dir[2][2] = {{-1, 0}, {0, -1}};

template <typename T> void ckmax(T& a, T b) { a = max(a, b); }
bool ok(int x, int y) {return x > 0 && y > 0;}

int dfs(int A, int b, int c, int d) {
    if(dp[A][b][c] != -1) return dp[A][b][c];
    for(int i = 0;i<2;++i) {
        for(int j = 0;j<2;++j) {
            int x = A + dir[i][0];
            int y = b + dir[i][1];
            int z = c + dir[j][0];
            int w = d + dir[j][1]; 
            if(ok(x, y) && ok(z, w)) {
                ckmax(dp[A][b][c], dfs(x, y, z, w) + abs(a[A][b] - a[c][d]));
            }
        }
    }
    return dp[A][b][c];
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    memset(dp, -1, sizeof(dp));
    dp[1][1][1] = 0;
    cin>>n;
    for(int i = 1;i<=n;++i) 
        for(int j = 1;j<=n;++j) cin>>a[i][j];
    cout<<dfs(n, n, n, n)<<'\n';
    return 0;
}
