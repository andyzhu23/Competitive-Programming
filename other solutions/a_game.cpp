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

const int N = 1e3 + 10;
using ll = long long;
ll dp[N][N], sum[N];
int n;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(n);
    for(int i =1;i<=n;++i) dp[i][i] = read();
    for(int i = 1;i<=n;++i) sum[i] = sum[i - 1] + dp[i][i];
    for(int l = 2;l<=n;++l) {
        for(int i = 1;i + l - 1<=n;++i) {
            int j = i + l - 1;
            dp[i][j] = sum[j] - sum[i - 1] - min(dp[i][j - 1], dp[i + 1][j]);
        }
    }
    print(dp[1][n], '\n');
    return 0;
}
