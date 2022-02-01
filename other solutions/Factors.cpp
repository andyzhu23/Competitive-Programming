#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

namespace fast_io {
    ll read() {
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
ll a, b;
gp_hash_table<ll, ll> cnt;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    a = read(), b = read();
    auto solve = [&](ll num) {
        for(ll i = 2;i * i <=num;++i) {
            while(num % i == 0) {
                num /= i, ++cnt[i];
            }
        }
        if(num != 1) ++cnt[num];
    };
    solve(b - a + 1);
    solve(b + a);
    cnt[2]--;
    ll ans = 1;
    for(auto x : cnt) ans *= x.second + 1;
    print(ans, '\n');
    return 0;
}

