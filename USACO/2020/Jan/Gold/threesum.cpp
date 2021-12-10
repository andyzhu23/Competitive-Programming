#pragma GCC optimize(2)
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

const int N = 5000;
using ll = long long;
int n, q, a[N];
ll dp[N][N];
int cnt[(int)(3e6 + 10)];

int main() {
    freopen("threesum.in", "r", stdin);
    freopen("threesum.out", "w", stdout);
    read(n), read(q);
    for(int i = 0;i<n;++i) read(a[i]);
    for(int i = 0;i<n;++i) {
        for(int j = i + 1;j<n;++j) {
            if(-a[i] - a[j] > -1e6 && -a[i] - a[j] < 1e6)
                dp[i][j] = cnt[(int)(-a[i] - a[j] + 1e6)];
            ++cnt[(int)(a[j] + 1e6)];
        }
        for(int j = i + 1;j<n;++j) --cnt[(int)(a[j] + 1e6)];
    }
    for(int l = 2;l<=n;++l) {
        for(int i = 0;i + l - 1<n;++i) {
            int j = i + l - 1;
            dp[i][j] += dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
        }
    }
    while(q--) print(dp[read() - 1][read() - 1], '\n');
    return 0;
}