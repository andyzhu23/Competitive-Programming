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
#define all(v) v.begin(), v.end()
#define lb lower_bound
#define pb push_back
const int N = 1e6 + 10;
int a[N], b[N], c[N];
vector<int> dp(1);

int main() {
#ifdef LOCAL
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
#endif
    memset(b, -1, sizeof(b));
    int n = read();
    for(int i = 1;i<=n;++i) {
        read(a[i]);
        b[a[i]] = i;
    }
    int m = read();
    for(int j = 1;j<=m;++j) read(c[j]);
    for(int i = 1;i<=m;++i) c[i] = b[c[i]];
    
    // LIS 
    for(int i = 1;i<=m;++i) {
        if(c[i] == -1) continue;
        if(dp.back() < c[i]) dp.pb(c[i]);
        else {
            int k = lb(all(dp), c[i]) - dp.begin();
            dp[k] = c[i];
        }
    }
    print(dp.size() - 1, '\n');
    return 0;
}