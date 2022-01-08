#include <bits/stdc++.h>
using namespace std;
const int mod = 1234567;

template <typename T1, typename T2>
T1 fp(T1 a, T2 b) {
    T1 c = 1;
    while(b) {
        if(b & 1) c = (c * a) % mod;
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
    int n;
    scanf("%d", &n);
    printf("%lld\n", fp(2ll, n - 1));
    return 0;
}
