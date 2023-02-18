#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
char ans[N][N];
int n, m, r, c;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>m>>r>>c;
    if(m == 1 && r != n) {
        puts("IMPOSSIBLE");
        return 0;
    } 
    if(n == 1 && c != m) {
        puts("IMPOSSIBLE");
        return 0;
    }
    if(r == 0 && c == 0) {
        for(int i = 1;i<=n / 2;++i) {
            for(int j = 1;j<=m/2;++j) ans[i][j] = 'a';
        }
        for(int i = n/2+1;i<=n;++i) {
            for(int j = 1;j<=m/2;++j) ans[i][j] = 'b';
        }
        for(int i = 1;i<=n / 2;++i) {
            for(int j = m/2 + 1;j<=m;++j) ans[i][j] = 'b';
        }
        for(int i = n/2+1;i<=n;++i) {
            for(int j = m/2 + 1;j<=m;++j) ans[i][j] = 'a';
        }
    } else if(n > r && m > c) {
        for(int i = 1;i<=r;++i) {
            for(int j = 1;j<=m;++j) ans[i][j] = 'a';
        }
        for(int j = 1;j<=c;++j) {
            for(int i = 1;i<=n;++i) ans[i][j] = 'a';
        }
        for(int i = 1;i<=n;++i) {
            for(int j = 1;j<=m;++j) if(ans[i][j] != 'a') ans[i][j] = 'b';
        }
        if(r == 0) {
            for(int j = c + 1;j<=m;++j) {
                for(int i = 1;i<=n/2;++i) ans[i][j] = 'b';
                for(int i = n/2 + 1;i<=n;++i) ans[i][j] = 'c';
            }
        }
        if(c == 0) {
            for(int i = r + 1;i<=n;++i) {
                for(int j = 1;j<=m/2;++j) ans[i][j] = 'b';
                for(int j = m/2 + 1;j<=m;++j) ans[i][j] = 'c';
            }
        }
        for(int i = 1;i<=n;++i) {
            for(int j = 1;j<=m;++j) cout<<ans[i][j];
            cout<<'\n';
        }
        return 0;
    } else if(n == r && m == c) {
        for(int i = 1;i<=n;++i) {
            for(int j = 1;j<=m;++j) cout<<'a';
            cout<<'\n';
        }
        return 0;
    } else if(n == r || m == c) {
        if(n == r && (m % 2 == 0) && c % 2 == 1) {
            puts("IMPOSSIBLE");
            return 0;
        } 
        if(m == c && (n % 2 == 0) && r % 2 == 1) {
            puts("IMPOSSIBLE");
            return 0;
        }
        if(n == r) {
            if(c % 2 == 1) {
                for(int i = 1;i<=n;++i) {
                    ans[i][(m - 1) / 2 + 1] = 'a';
                }
            }
            c /= 2;
            for(int j = 1;j<=c;++j) {
                for(int i = 1;i<=n;++i) {
                    ans[i][j] = ans[i][m - j + 1] = 'a';
                }
            }
            for(int j = 1;j<=m;++j) if(ans[1][j] != 'a') {
                for(int i = 1;i<=n / 2;++i) {
                    ans[i][j] = 'b';
                }
                for(int i = n / 2 + 1;i<=n;++i) ans[i][j] = 'c';
            }
        }
        if(m == c) {
            if(r % 2 == 1) {
                for(int j = 1;j<=m;++j) {
                    ans[(n - 1) / 2 + 1][j] = 'a';
                }
            }
            r /= 2;
            for(int i = 1;i<=r;++i) {
                for(int j = 1;j<=m;++j) {
                    ans[i][j] = ans[n - i + 1][j] = 'a';
                }
            }
            for(int i = 1;i<=n;++i) if(ans[i][1] != 'a') {
                for(int j = 1;j<=m / 2;++j) {
                    ans[i][j] = 'b';
                }
                for(int j = m / 2 + 1;j<=m;++j) ans[i][j] = 'c';
            }
        }
    }
    for(int i = 1;i<=n;++i) {
        for(int j = 1;j<=m;++j) cout<<ans[i][j];
        cout<<'\n';
    }
    return 0;
}