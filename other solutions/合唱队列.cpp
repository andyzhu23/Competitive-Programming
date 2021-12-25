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
const int N = 1e2 + 10;
int n, a[N], dp[N][2];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    n = read();
    for(int i = 1;i<=n;++i) a[i] = read();
    for(int i = 1;i<=n;++i) {
        for(int j = 0;j<i;++j) {
            if(a[i] > a[j]) dp[i][0] = max(dp[i][0], dp[j][0] + 1);
            else if(a[i] < a[j]) dp[i][1] = max(dp[i][1], max(dp[j][0], dp[j][1]) + 1);
        }
    }
    int ans = 0;
    for(int i = 1;i<=n;++i) {
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }
    print(n - ans, '\n');
    return 0;
}


