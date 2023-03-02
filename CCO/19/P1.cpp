#include <bits/stdc++.h>
using namespace std;
const int N = 5e6 + 5;
const int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int r, c;
double dp[N][5];
bool vis[N][5];
char s[N];

int fp(int a, int b) {
    int c = 1;
    while(b) {
        if(b & 1) c *= a;
        a = a * a;
        b >>= 1;
    }
    return c;
}
#define ok(u, v) (u >= 0 && u < r && v >= 0 && v < c)
int tmp[20][20], J, D;
double dfs(int u, int p = 1) {
    if(vis[u][p]) return dp[u][p];
    vis[u][p] = 1;
    for(int i = 0;i<r;++i) {
        for(int j = 0;j<c;++j) {
            tmp[i][j] = u / fp(3, i * c + j) % 3;
        }
    }
    vector<double> v;
    for(int i = 0;i<r;++i) {
        for(int j = 0;j<c;++j) if(tmp[i][j] == p) {
            for(int k = 0;k<4;++k) {
                int ii = i + dir[k][0];
                int jj = j + dir[k][1];
                if(ok(ii, jj) && tmp[ii][jj]) {
                    tmp[i][j] = 0;
                    int o = tmp[ii][jj];
                    tmp[ii][jj] = p;
                    int nxt = 0;
                    for(int i = 0;i<r;++i) {
                        for(int j = 0;j<c;++j) {
                            nxt += tmp[i][j] * fp(3, i * c + j);
                        }
                    }
                    v.push_back(dfs(nxt, p == 1 ? 2 : 1));
                    tmp[ii][jj] = o;
                    tmp[i][j] = p;
                }
            }
        }
    }
    sort(v.begin(), v.end());
    int sz = min(p == 1 ? J : D, (int)v.size());
    for(int i = 0;i<sz;++i) dp[u][p] += 1 - v[i];
    if(sz) dp[u][p] /= sz;
    return dp[u][p];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &r, &c);
    int o = 0;
    for(int i = 0;i<r;++i) {
        scanf("%s", s);
        for(int j = 0;j<c;++j) o += (s[j] == 'J' ? 1 : 2) * fp(3, i * c + j);
    }
    scanf("%d%d", &J, &D);
    printf("%.3f\n", dfs(o));
    return 0;
}
