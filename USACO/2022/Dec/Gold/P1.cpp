#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
const int N = 2005;
int n, A, B;
struct node {
    int p, c, x;
    bool operator<(const node& other) const {
        return x < other.x;
    }
} a[N];

int dp[N][N << 1];
bitset<(N << 1)> vis[N];

int dfs(int u = 1, int c = A, int x = B) {
    if(u == n + 1) return 0;
    if(a[u].x > x) x = 0;
    int key = c + x;
    if(vis[u][key]) return dp[u][key];
    vis[u][key] = 1;
    dp[u][key] = dfs(u + 1, c, x);
    int tmp = x / a[u].x;
    int nc = c, nx = x;
    if(tmp >= a[u].c) nx -= a[u].c * a[u].x;
    else {
        nx = 0;
        nc -= a[u].c - tmp;
    }
    if(nx >= 0 && nc >= 0) dp[u][key] = max(dp[u][key], dfs(u + 1, nc, nx) + a[u].p);
    return dp[u][key];
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>A>>B;
    for(int i = 1;i<=n;++i) {
        int p, c, x;
        cin>>p>>c>>x;
        a[i] = {p, c, x};
    }
    sort(a + 1, a + n + 1);
    cout<<dfs()<<'\n';
    return 0;
}
