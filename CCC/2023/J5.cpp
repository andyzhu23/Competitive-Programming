#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 105;
const int mod = 1e9 + 7;
int r, c;
char a[N][N];
string s;

ll key, ans;

int dir[8][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {-1, 1}, {1, -1}, {-1, -1}, {1, 1}};
int p1[8][2] = {{1, 0}, {0, 1}, {0, 1}, {1, 0}, {-1, -1}, {-1, -1}, {1, -1}, {-1, 1}};
int p2[8][2] = {{-1, 0}, {0, -1}, {0, -1}, {-1, 0}, {1, 1}, {1, 1}, {-1, 1}, {1, -1}};


#define ok(i, j) (i > 0 && i <= r && j > 0 && j <= c)
void dfs(int i, int j, int k, int u = 1, int t = 0, ll cur = 0) {
    if(!ok(i, j)) return;
    cur = (cur * 131 + a[i][j]) % mod;
    if(u == s.size()) {
        ans += cur == key;
        return;
    }
    if(t == 0) {
        dfs(i + dir[k][0], j + dir[k][1], k, u + 1, t, cur);
        if(u != s.size() - 1) {
            dfs(i + dir[k][0], j + dir[k][1], k, u + 1, 1, cur);
            dfs(i + dir[k][0], j + dir[k][1], k, u + 1, 2, cur);
        }
    } else if(t == 1) {
        dfs(i + p1[k][0], j + p1[k][1], k, u + 1, t, cur);
    } else if(t == 2) {
        dfs(i + p2[k][0], j + p2[k][1], k, u + 1, t, cur);
    }
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>s>>r>>c;
    for(int i = 0;i<s.size();++i) key = (key * 131 + s[i]) % mod;
    for(int i = 1;i<=r;++i) {
        for(int j = 1;j<=c;++j) cin>>a[i][j];
    }
    for(int i = 1;i<=r;++i) {
        for(int j = 1;j<=c;++j) {
            for(int k = 0;k<8;++k) {
                dfs(i, j, k);
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}