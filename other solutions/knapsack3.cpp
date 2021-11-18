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

const int N = 5e3 + 10;
using ll = long long;
int n, m;
ll dp[N];

void knap01(int v, ll p) {
    for(int i = N - 1;i>=v;--i) 
        dp[i] = max(dp[i], dp[i - v] + p);
}

void cknap(int v, ll p) {
    for(int i = v;i<N;++i) 
        dp[i] = max(dp[i], dp[i - v] + p);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(n), read(m);
    for(int i = 1;i<=n;++i) {
        ll k = read(), v = read(), p = read();
        if(v * k >= N) cknap(v, p);
        else {
            ll tmp = 1;
            while(tmp < k) {
                knap01(v * tmp, p * tmp);
                k -= tmp;
                tmp <<= 1;
            }
            knap01(v * k, p * k);
        }
    }

    ll ans = -0x3f3f3f3f;
    for(int i = 1;i<=m;++i) {
        int c = read(), f = read();
        ans = max(ans, dp[c] - f);
    }
    print(ans, '\n');
    return 0;
}
