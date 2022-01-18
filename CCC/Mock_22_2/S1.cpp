#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;

int n, k, a[N][20], key[20], ans = 0;

void dfs(int u) {
    if(u == k + 1) {
        int cur = 0x3f3f3f3f;
        for(int i = 1;i<=n;++i) {
            int tot = 0;
            for(int j = 1;j<=k;++j) {
                tot += a[i][j] == key[j];
            }
            cur = min(cur, tot);
        }
        ans = max(cur, ans);
        return;
    }
    key[u] = 1;
    dfs(u + 1);
    key[u] = 0;
    dfs(u + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>k;
    for(int i = 1;i<=n;++i) {
        string s; cin>>s;
        for(int j = 1;j<=k;++j) {
            a[i][j] = s[j - 1] == 'T';
        }
    }
    dfs(1);
    cout<<ans<<'\n';
    return 0;
}