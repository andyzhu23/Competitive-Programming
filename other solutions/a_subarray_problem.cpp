#pragma GCC optmize(2)
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
const int N = 1e6 + 10;
int f[N], siz[N], a[N], p[N];
int Find(int x) {return f[x] == x ? x : f[x] = Find(f[x]);}
void merge(int u, int v) {
    int fu = Find(u);
    int fv = Find(v);
    f[fu] = fv;
    siz[fv] += siz[fu];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n = read();
    for(int i = 1;i<=n;++i) a[i] = read(), p[a[i]] = i, siz[i] = 1, f[i] = i;
    int ans = 0;
    for(int i = 1;i<=n;++i) {
        int pos = p[i];
        if(pos > 1 && a[pos - 1] < i) merge(a[pos - 1], i);
        if(pos < n && a[pos + 1] < i) merge(a[pos + 1], i);
        ans += siz[i] == i;
    }
    print(ans, '\n');
    return 0;
}
