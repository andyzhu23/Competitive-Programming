#include <bits/stdc++.h>
using namespace std;
const int N = 1505;
int n, m, k;
using pii = pair<int, int>;
int a[N][N], dist[N][N];
const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
#define fir first
#define sec second

struct cmp {
    bool operator() (const pii& c, const pii& b) {
        if(dist[c.fir][c.sec] == dist[b.fir][b.sec]) {
            return a[c.fir][c.sec] > a[b.fir][b.sec];
        } else return dist[c.fir][c.sec] > dist[b.fir][b.sec];
    }
};

priority_queue<pii, vector<pii>, cmp> q;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>m>>k;
    memset(dist, 0x3f, sizeof(dist));
    for(int i = 1;i<=n;++i) {
        for(int j = 1;j<=m;++j) {
            cin>>a[i][j];
            if(a[i][j]) {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }
    while(!q.empty()) {
        auto[x, y] = q.top(); q.pop();
        for(int i = 0;i<4;++i) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
            if((dist[nx][ny] > dist[x][y] + 1) || (dist[nx][ny] == dist[x][y] + 1 && a[nx][ny] > a[x][y])) {
                a[nx][ny] = a[x][y];
                dist[nx][ny] = dist[x][y] + 1;
                if(dist[nx][ny] < k) q.push({nx, ny});
            }
        }
    }
    for(int i = 1;i<=n;++i) {
        for(int j = 1;j<=m;++j) {
            cout<<a[i][j]<<(j == m ? '\n' : ' ');
        }
    }
    return 0;
}