#include <bits/stdc++.h>
using namespace std;

#define ins insert
#define pb push_back
using vi = vector<int>;

const int N = 210;
const int NN = N * N;
const int dir[8][2] = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {-2, 1}, {-2, -1}, {2, -1}};
int n, tot, ans, a[N][N], match[NN];
bool vis[NN];
vi e[NN], black;

int get(int x, int y) {
    return (x - 1) * n + y;
}

bool ok(int x, int y) {
    return x > 0 && n >= x && y > 0 && n >= y;
}

bool Find(int u) {
    for(auto& v : e[u]) {
        if(!vis[v]) {
            vis[v] = 1;
            if(match[v] == 0 || Find(match[v])) {
                match[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

void dfs(int i, int j, bool color) {
    vis[get(i, j)] = 1;
    if(color && !a[i][j]) black.pb(get(i, j));
    for(int k = 0;k<8;k++) {
        int x = i + dir[k][0];
        int y = j + dir[k][1];
        if(ok(x, y)) {
            if(color && !a[i][j] && !a[x][y]) e[get(i, j)].pb(get(x, y));
            if(!vis[get(x, y)]) dfs(x, y, !color);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 1;i<=n;i++) {
        string s; cin>>s;
        for(int j = 0;j < n;j++) {
            a[i][j + 1] = s[j] - '0';
            if(!a[i][j + 1]) tot++;
        }
    }
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=n;j++) {
            if(!a[i][j]) {
                dfs(i, j, 1);
                for(auto& x : black) {
                    memset(vis, 0, sizeof(vis));
                    if(Find(x)) ans++;
                }
                cout<<tot - ans<<"\n";
                return 0;
            }
        }
    }
}
