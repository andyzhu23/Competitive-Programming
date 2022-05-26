#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 2005;
const int NN = N * N;
using pii = pair<int, int>;
int n, m, tot;
pii l[N][N], r[N][N], u[N][N], d[N][N];
char s[N][N];
vector<int> e[NN];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for(int i = 1;i<=n;++i) {
        scanf("%s", s[i] + 1);
    }
    for(int i = 1;i<=n;++i) {
        int x = 0, y = 0;
        for(int j = 1;j<=m;++j) {
            if(s[i][j] != '.') {
                l[i][j] = {x, y};
                x = i, y = j;
            }
        }
    }
    for(int i = 1;i<=n;++i) {
        int x = 0, y = 0;
        for(int j = m;j;--j) {
            if(s[i][j] != '.') {
                r[i][j] = {x, y};
                x = i, y = j;
            }
        }
    }
    for(int j = 1;j<=m;++j) {
        int x = 0, y = 0;
        for(int i = 1;i<=n;++i) {
            if(s[i][j] != '.') {
                u[i][j] = {x, y};
                x = i, y = j;
            }
        }
    }
    for(int j = 1;j<=m;++j) {
        int x = 0, y = 0;
        for(int i = n;i;--i) {
            if(s[i][j] != '.') {
                d[i][j] = {x, y};
                x = i, y = j;
            }
        }
    }
    queue<pii> q;
    for(int i = 1;i<=n;++i) {
        for(int j = 1;j<=m;++j) {
            switch (s[i][j]) {
                case 'E':
                    if(r[i][j] == (pii){0, 0}) q.push({i, j});
                    break;
                case 'W':
                    if(l[i][j] == (pii){0, 0}) q.push({i, j});
                    break;
                case 'N':
                    if(u[i][j] == (pii){0, 0}) q.push({i, j});
                    break;
                case 'S':
                    if(d[i][j] == (pii){0, 0}) q.push({i, j});
                    break;
            }
        }
    }
    vector<pii> ans;
    while(!q.empty()) {
        auto[x, y] = q.front(); q.pop();
        ans.pb({x - 1, y - 1});
        if(l[x][y] != (pii){0, 0}) {
            auto[xx, yy] = l[x][y];
            r[xx][yy] = r[x][y];
            if(r[x][y] == (pii){0, 0} && s[xx][yy] == 'E') q.push({xx, yy});
        }
        if(r[x][y] != (pii){0, 0}) {
            auto[xx, yy] = r[x][y];
            l[xx][yy] = l[x][y];
            if(l[x][y] == (pii){0, 0} && s[xx][yy] == 'W') q.push({xx, yy});
        }
        if(u[x][y] != (pii){0, 0}) {
            auto[xx, yy] = u[x][y];
            d[xx][yy] = d[x][y];
            if(d[x][y] == (pii){0, 0} && s[xx][yy] == 'S') q.push({xx, yy});
        }
        if(d[x][y] != (pii){0, 0}) {
            auto[xx, yy] = d[x][y];
            u[xx][yy] = u[x][y];
            if(u[x][y] == (pii){0, 0} && s[xx][yy] == 'N') q.push({xx, yy});
        }
    }
    for(auto[u, v] : ans) {
        printf("(%d,%d)\n", u, v);
    }
    return 0;
}
