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
using ll = long long;
const int N = 3005;
int n, k;
int a[N][N];

inline void dfs(int u) {
    if(u == 1) return;
    int siz = u == 2 ? 1 : (u * 2 - 1) / 3 + 1;
    dfs(siz);
    for(int i = 1;i<=n - u + 1;++i) 
        for(int j = 1;j<=i;++j) 
            a[i][j] = max({a[i][j], a[i + u - siz][j], a[i + u - siz][j + u - siz]});
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    n = read(), k = read();
    for(int i = 1;i<=n;++i) 
        for(int j = 1;j<=i;++j) 
            a[i][j] = read();
    dfs(k);
    ll ans = 0;
    for(int i = 1;i<=n - k + 1;++i) 
        for(int j = 1;j<=i;++j) 
            ans += a[i][j];
    print(ans, '\n');
    return 0;
}
