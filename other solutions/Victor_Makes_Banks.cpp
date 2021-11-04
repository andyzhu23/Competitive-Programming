/*
 * Author: Andy Zhu
 * @date    2021-11-03 19:55:36
 * @version 1.0.0
 */

//include
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
namespace fast_io {
    ll read() {
        ll x = 0, f = 0; char ch = getchar();
        while (!isdigit(ch)) f |= ch == '-', ch = getchar();
        while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
            return f ? -x : x;
    }
    void read(ll& x) {x = read();}
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

const int MOD = 1e9 + 7;

ll n, k, t, c;

struct mat {
    ll a[104][104];
    mat operator*(const mat& other) const {
        mat ans;
        memset(ans.a, 0, sizeof(ans.a));
        for(int i = 1;i<=t + 1;++i) {
            for(int j = 1;j<=t + 1;++j) {
                for(int k = 1;k<=t + 1;++k) {
                    ans.a[i][j] = (ans.a[i][j] + a[i][k] % MOD * other.a[k][j] % MOD) % MOD;
                }
            }
        }
        return ans;
    }
} init, b;

template <typename T1, typename T2> 
inline T1 fast_pow(T1 a, T2 b) {
    mat res = a;
    --b;
    while(b) {
        if(b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(n), read(k), read(t), read(c);
    memset(init.a, 0, sizeof(init.a));
    memset(b.a, 0, sizeof(b.a));
    if(n == 1) {
        print((c << 1) % MOD, '\n');
        return 0;
    }
    init.a[1][1] = c;
    b.a[1][1] = 1;
    for(int i = 1;i<=t;++i) b.a[i][i + 1] = 1;
    b.a[t + 1][1] = k;
    mat ans = fast_pow(b, n - 1) * init;
    ll tot = ans.a[1][1];
    for(int i = 1;i<=t + 1;++i) {
        tot += ans.a[i][1];
        tot %= MOD;
    }
    print(tot, '\n');
    return 0;
}
