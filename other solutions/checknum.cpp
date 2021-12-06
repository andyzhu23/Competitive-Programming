#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using ll = __int128;

namespace fast_io {
    int read() {
        int x = 0, f = 0; char ch = getchar();
        while (!isdigit(ch)) f |= ch == '-', ch = getchar();
        while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
            return f ? -x : x;
    }
    ll readLL() {
        ll x = 0, f = 0; char ch = getchar();
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

bool ok(ll x, ll n, ll a) {
    ll odd = ((x - 1) >> 1) + 1;
    ll even = x >> 1;
    return odd * 9 >= a && even * 9 >= (n - a * a);
}

void solve() {
    ll n = readLL();
    ll l = 1, r = n, ans = 0, a = 0;
    while(l <= r) {
        ll mid = l + r >> 1;
        if(mid * mid <= n) {
            l = mid + 1;
            a = mid;
        } else r = mid - 1;
    }
    l = 1, r = n;
    while(l <= r) {
        ll mid = l + r >> 1;
        if(ok(mid, n, a)) {
            r = mid - 1;
            ans = mid;
        } else l = mid + 1;
    }
    print(ans, '\n');
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t = read();
    while(t--) solve();
    return 0;
}
