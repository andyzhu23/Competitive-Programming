#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
ll dp1[(int)(1e7 + 10)];
unordered_map<int, ll> dp2;

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

ll dfs(int n) {
    if(n <= 1e7) {
        if(dp1[n]) return dp1[n];
        for(int i = 2, nxt;i<=n;i=nxt) {
            int x = n / i;
            nxt = n / x + 1;
            dp1[n] += (nxt - i) * dfs(x);
        }
        return dp1[n];
    }
    if(dp2[n]) return dp2[n];
    for(int i = 2, nxt;i<=n;i=nxt) {
        int x = n / i;
        nxt = n / x + 1;
        dp2[n] += (nxt - i) * dfs(x);
    }
    return dp2[n];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    dp1[1] = 1;
    n = read();
    print(dfs(n), '\n');
    return 0;
}
