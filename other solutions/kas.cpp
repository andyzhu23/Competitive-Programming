/*
 * Author: Andy Zhu
 * @date    2021-11-09 13:51:59
 * @version 1.0.0
 */

//include
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
const int N = 510;
int n, a[N], dp[3][100010];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(n);
    int tot = 0;
    for(int i = 1;i<=n;++i) tot += a[i] = read();
    memset(dp, -0x3f, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1;i<=n;++i) {
        for(int j = 0;j<=tot;++j) {
            dp[i & 1][j] = max(dp[i & 1][j], dp[i & 1 ^ 1][j]);
            dp[i & 1][j] = max(dp[i & 1][j], dp[i & 1 ^ 1][j + a[i]] + a[i]);
            dp[i & 1][j] = max(dp[i & 1][j], dp[i & 1 ^ 1][abs(j - a[i])] + a[i]);
        }
    }
    print(tot - (dp[n & 1][0] >> 1), '\n');
    return 0;
}
