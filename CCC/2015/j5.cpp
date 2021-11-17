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
const int N = 300;
int n, k, dp[N][N][N], vis[N][N][N];

int solve(int i, int j, int l) {
    if(vis[i][j][l] || i == 0 || j == 0) return dp[i][j][l];
    vis[i][j][l] = 1;
    for(int cnt = l;cnt <=j;++cnt) dp[i][j][l] += solve(i - 1, j - cnt, cnt);
    return dp[i][j][l];
}

int main() {
    read(n), read(k);
    for(int i = 0;i<=n;++i) dp[0][0][i] = 1;
    print(solve(k, n, 1), '\n');
    return 0;
}
