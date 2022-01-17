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
const int N = 5e6 + 10;
int n, a[N], ans[N];

class DSU {
private:
    int f[N], n;
    bool x;
public:
    void init(int N, bool X) {n = N, x = X; iota(f + 1, f + n + 2, 1);}
    int Find(int x) {return f[x] == x ? x : f[x] = Find(f[x]);}
    void merge(int u, int v) {
        int fu = Find(u);
        int fv = Find(v);
        if(x && fu > fv) swap(fu, fv);
        else if(!x && fu < fv) swap(fu, fv);
        f[fu] = fv;
    }
} d1, d2;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    n = read();
    d1.init(n, 0), d2.init(n, 1);
    memset(ans, -1, sizeof(ans));
    for(int i = 1;i<=n;++i) read(a[i]);
    for(int i = n;i;--i) {
        int mx = d1.Find(a[i] - 1);
        int mn = d2.Find(a[i] + 1);
        if(!(mx == 0 || mn == n + 1)) ans[i] = abs(mn - mx);
        d1.merge(a[i], a[i] - 1);
        d2.merge(a[i], a[i] + 1);
    }
    for(int i = 1;i<n;++i) print(ans[i], ' ');
    print(ans[n], '\n');
    return 0;
}
