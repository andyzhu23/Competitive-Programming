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
const int N = 1e5 + 10;
int h[N], dp[N], n, k;

int main() {
    n = read(), k = read();
    for(int i = 1;i<=n;++i) {
        read(h[i]);
        if(i > 1) dp[i] = 0x3f3f3f3f;
        for(int j = max(1, i - k); j<i;++j) 
            dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j]));
    }
    print(dp[n], '\n');
    return 0;
}