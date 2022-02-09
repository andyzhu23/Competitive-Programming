#include <bits/stdc++.h>
using namespace std;
const int N = 35;
const int way[5][4] = {
    {2, 1, 0, 2},
    {1, 1, 1, 1},
    {0, 0, 2, 1},
    {0, 3, 0, 0},
    {1, 0, 0, 1}
};
int n;
bool dp[N][N][N][N], vis[N][N][N][N];

bool dfs(int a, int b, int c, int d) {
    if(vis[a][b][c][d]) return dp[a][b][c][d];
    vis[a][b][c][d] = 1;
    dp[a][b][c][d] = 1;
    for(auto x : way) {
        int na = a - x[0];
        int nb = b - x[1];
        int nc = c - x[2];
        int nd = d - x[3];
        if(min({na, nb, nc, nd}) >= 0) {
            dp[a][b][c][d] &= dfs(na, nb, nc, nd) ^ 1;
        }
    }
    return dp[a][b][c][d];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for(int i = 1;i<=n;++i) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        puts(dfs(a, b, c, d) ? "Roland" : "Patrick");
    }
    return 0;
}
