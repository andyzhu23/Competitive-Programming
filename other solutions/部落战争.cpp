#include <bits/stdc++.h>
using namespace std;

#define ok(x, y) (x > 0 && x <= m && y > 0 && y <= n && a[x - 1][y - 1] == '.')
#define id(x, y) ((x - 1) * n + y)
#define pb push_back
const int N = 60;
const int NN = N * N;
int m, n, r, c, tot, match[NN], vis[NN];
set<int> e[NN], lft;
string a[N];

bool Find(int u) {
    for(auto& v : e[u]) {
        if(vis[v]) continue;
        vis[v] = 1;
        if(match[v] == 0 || Find(match[v])) {
            match[v] = u;
            return 1;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>m>>n>>r>>c;
    int dir[4][2] = {{r, c}, {r, -c}, {c, r}, {c, -r}};
    for(int i = 1;i<=m;i++) {
        cin>>a[i - 1];
    }
    for(int i = 1;i<=m;i++) {
        for(int j = 1;j<=n;j++) {
            tot += a[i - 1][j - 1] == '.';
            if(a[i - 1][j - 1] != '.') continue;
            for(int k = 0;k<4;k++) {
                int x = i + dir[k][0];
                int y = j + dir[k][1];
                if(ok(x, y)) {
                    e[id(i, j)].insert(id(x, y));
                    lft.insert(id(i, j));
                }
            }
        }
    }
    int ans = 0;
    for(auto& i : lft) {
        memset(vis, 0, sizeof(vis));
        if(Find(i)) ans ++;
    }
    cout<<tot - ans<<'\n';
    return 0;
}
