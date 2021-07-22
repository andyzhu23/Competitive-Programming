#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 110;
const int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int n, m, match[N * N];
bool no[N][N], vis[N * N], nt[N * N];
vector<int> e[N * N], e2[N * N], black, white;

void dfs(int u, bool colid) {
    vis[u] = 1;
    if(colid && !nt[u]) black.pb(u);
    else if(!nt[u]) white.pb(u);
    for (int v : e[u]) {
        if(colid && !nt[v]) e2[u].pb(v);
        if(vis[v]) continue;
        dfs(v, !colid);
    }
}

bool Find(int x) {
    for(int i : e2[x]) {
        if(vis[i] == 0) {
            vis[i] = 1;
            if(match[i] == 0 || Find(match[i])) {
                match[i] = x;
                return true;
            }
        }
    }
    return false;
}

bool ok(int x, int y) {
    return x > 0 && x <= n && y > 0 && y <= n;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 1;i<=m;i++) {
        int x, y;
        cin>>x>>y;
        no[x][y] = 1;
    }
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=n;j++) {
            if(no[i][j]) {
                nt[(i - 1) * n + j] = 1;
            }
            for(int k = 0;k<4;k++) {
                int x = i + dir[k][0];
                int y = j + dir[k][1];
                if(!ok(x, y)) continue;
                e[(i - 1) * n + j].pb((x - 1) * n + y);
                e[(x - 1) * n + y].pb((i - 1) * n + j);
            }
            
        }
    }
    dfs(1, 1);
    int ans = 0;
    for(int i : black) {
        memset(vis, 0, sizeof(vis));
        if(Find(i)) {
            ans ++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
