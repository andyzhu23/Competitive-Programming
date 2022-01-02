#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;
using ld = long double;
using ll = long long;
int n;
ll a[N];
__int128 b[N];
namespace fast_io {
    int read() {
        int x = 0, f = 0; char ch = getchar();
        while (!isdigit(ch)) f |= ch == '-', ch = getchar();
        while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
        return f ? -x : x;
    }
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

struct fenwick {
    __int128 c[30002];
    void update(int a, __int128 b) {
        for(int i = a;i<30002;i += i & (-i)) c[i] += b;
    }
    __int128 query(int a) {
        __int128 ans = 0;
        for(int i = a;i;i-= i & (-i)) ans += c[i];
        return ans;
    }
    __int128 query(int a, int b) {return query(b) - query(a - 1);}
} fen, fen2, fen3, fen4;

__int128 get(__int128 x) {
    int y = ceil((ld)x / 10000) + 15001;
    return (fen.query(y, 30001) - fen2.query(y, 30001) * x +
            fen3.query(y, 30001) * x * x - fen4.query(y, 30001) * x * x * x)
           - (fen.query(y - 1) - fen2.query(y - 1) * x + fen3.query(y - 1) * x * x
              - fen4.query(y - 1) * x * x * x);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    n = read();
    for(int i = 1;i<=n;++i) {
        a[i] = read();
        b[i] = a[i] * 10000;
        a[i] += 15001;
        fen.update(a[i], b[i] * b[i] * b[i]);
        fen2.update(a[i], b[i] * b[i] * 3);
        fen3.update(a[i], b[i] * 3);
        fen4.update(a[i], 1);
        ll l = -150000000, r = 150000000;
        ld ans;
        __int128 mx = -1;
        while(l <= r) {
            ll mid1 = l + r >> 1;
            ll mid2 = mid1 + 1;
            __int128 res1 = get(mid1);
            __int128 res2 = get(mid2);
            if(res1 < res2) {
                r = mid1;
                if(res1 < mx || mx == -1) ans = mid1, mx = res1;
            }
            else {
                l = mid2;
                if(res2 < mx || mx == -1) ans = mid2, mx = res2;
            }
            if(abs(r - l) < 10) break;
        }
        ans /= 10000;
        printf("%.4Lf\n", ans);
    }
    return 0;
}
