#include <bits/stdc++.h>
using namespace std;

namespace fast_io {
    int read() {
        int x = 0, f = 0; char ch = getchar();
        while (!isdigit(ch)) f |= ch == '-', ch = getchar();
        while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
        return f ? -x : x;
    }
    void read(int& x) {x = read();}
    template<typename T> void print(T x) {
        if (x < 0) putchar('-'), x = -x;
        if (x >= 10) print(x / 10);
        putchar(x % 10 + '0');
    }
    template<typename T> void print(T x, char let) {
        print(x), putchar(let);
    }
}
using namespace fast_io;

int n;
const int N = 210;

void solve() {
    vector<int> a(n + 1);
    int dp[N][N] = {0};
    for(int i = 1;i<=n;++i) read(a[i]);
    for(int i = 2;i<n;++i) dp[i][i] = a[i - 1] + a[i] + a[i + 1];
    for(int l = 2;l<n;++l) {
        for(int i = 2;i + l - 1 < n;++i) {
            int j = i + l - 1;
            for(int k = i;k<=j;++k) {
                dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + a[i - 1] + a[j + 1] + a[k]);
            }
        }
    }
    print(dp[2][n - 1], '\n');
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while(1) {
        read(n);
        if(!n) break;
        solve();
    }
    return 0;
}
