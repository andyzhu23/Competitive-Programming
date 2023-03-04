#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, a[N][N];

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "w", stdout);
#endif
    int n = 100;
    cout<<n<<'\n';
    a[1][2] = 1;
    a[1][3] = 3;
    for(int i = 4;i<=n;++i) a[1][i] = 100;
    for(int i = 3;i<=n;++i) a[2][i] = 1;
    a[3][4] = 100;
    a[3][5] = 99;
    for(int i = 6;i<=n;++i) a[3][i] = 1;
    for(int i = 4;i<=n;++i) {
        for(int j = i + 1;j<=n;++j) a[i][j] = 100;
        a[i][i & 1 ? i + 3 : i + 1] = 1;
    }
    for(int i = 1;i<=n;++i) {
        for(int j = i + 1;j<=n;++j) cout<<a[i][j]<<" \n"[j==n];
    }
    return 0;
}
