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
using ld = long double;
#define pb push_back
const int N = 1e3 + 10;
ld dp[N * 20][N];
vector<ld> res;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int k = read(), q = read();
    dp[0][0] = 1;
    for(int i = 1;i<=20000;++i) {
        for(int j = 1;j<=k;++j) {
            dp[i][j] = dp[i - 1][j] * (ld)(j) / (ld)(k) + dp[i - 1][j - 1] * (ld)(k - (j - 1)) / (ld)(k);
        }
        res.pb(dp[i][k]);
    }
    for(int i = 1;i<=q;++i) {
        ld target = (ld)read() / 2e3;
        print(lower_bound(res.begin(), res.end(), target) - res.begin() + 1, '\n');
    }
    return 0;
}
