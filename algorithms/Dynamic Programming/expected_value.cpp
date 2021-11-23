#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
double dp[N];
// dp[i] means the expected value after i turns
bool vis[N];
double n;
int m;

double dfs(int u) {
    if(vis[u]) return dp[u];
    double last = dfs(u - 1);
    dp[u] = (n - last) / n * (last + 1) + last / n * last;
    vis[u] = 1;
    return dp[u];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    vis[1] = 1;
    dp[1] = 1;
    cin>>n>>m;
    cout<<setprecision(7)<<dfs(m)<<'\n';
    return 0;
}
