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
const int N = 3e4 + 10;
int dp[N][505], sum[N];

void solve() {
    int n = read(), K = read(), w = read();
    for(int i = 1;i<=n;++i) sum[i] = sum[i - 1] + read();
    for(int i = w;i<=n;++i) 
        for(int k = 1;k<=K;++k) 
            dp[i][k] = max(dp[i - 1][k], dp[i - w][k - 1] + sum[i] - sum[i - w]);
    print(dp[n][K], '\n');
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t = read();
    while(t--) solve();
    return 0;
}
