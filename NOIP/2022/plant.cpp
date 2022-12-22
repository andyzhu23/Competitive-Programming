#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;
const int N = 1005;

int n, m, c, f;
char a[N][N];
int r[N][N];
ll dp[N][N], cc[N][N], ff[N][N], ansc, ansf;

void solve() {
    scanf("%d%d%d%d", &n, &m, &c, &f);
    for(int i = 1;i<=n;++i) {
        scanf("%s", a[i] + 1);
        for(int j = m;j;--j) {
            r[i][j] = a[i][j + 1] == '0' ? r[i][j + 1] + 1 : 0;
        }
    }
    memset(dp, 0, sizeof dp);
    memset(cc, 0, sizeof cc);
    memset(ff, 0, sizeof ff);
    ansc = ansf = 0;
    for(int i = 1;i<=n;++i) {
        for(int j = 1;j<=m;++j) {
            if(a[i][j] == '0') {
                cc[i][j] = dp[i - 1][j] * r[i][j] % mod;
                ff[i][j] = (ff[i - 1][j] + cc[i - 1][j]) % mod;
                dp[i][j] = (dp[i - 1][j] + (a[i - 1][j] == '0') * r[i - 1][j]) % mod;
                ansc = (ansc + cc[i][j]) % mod;
                ansf = (ansf + ff[i][j]) % mod;
            }
        }
    }
    cout<<c * ansc<<' '<<f * ansf<<'\n';
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t, id; 
    scanf("%d%d", &t, &id);
    while(t--) solve();
    return 0;
}
