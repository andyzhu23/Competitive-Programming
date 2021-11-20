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
const int N = 110;
int dp[2][N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n = read();
    for(int i = 1;i<=n;++i) {
        for(int j = 1;j<=i;++j) {
            int tmp = read();
            dp[i & 1][j] = max(dp[i & 1 ^ 1][j - 1] + tmp, dp[i & 1 ^ 1][j] + tmp);
        }
        memset(dp[i & 1 ^ 1], 0, sizeof(dp[i & 1 ^ 1]));
    }
    int ans = 0;
    for(int i = 1;i<=n;++i) ans = max(ans, dp[n & 1][i]);
    print(ans, '\n');
    return 0;
}
