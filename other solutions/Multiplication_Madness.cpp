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
const int N = 1e6 + 5;
const int mod = 1e9 + 7;
ll p[N];

template <typename T1, typename T2>
T1 fp(T1 a, T2 b) {
    T1 c = 1;
    while(b) {
        if(b & 1) c = c * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return c;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    p[0] = 1;
    for(int i = 1;i<N;++i) p[i] = p[i - 1] * i % mod;
    int n = read();
    while(n--) {
        int x = read(), y = read();
        print(p[y] * fp(p[--x], mod - 2) % mod, '\n');
    }
    return 0;
}
