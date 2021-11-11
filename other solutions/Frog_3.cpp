#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
    void read(ll& x) {x = readLL();}
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

const int N = 2e5 + 10;
int n;
ll C, h[N], dp[N];

deque<int> dq;

bool case1(int a, int b, int c) {
    return (dp[b] + h[b] * h[b]) - (dp[a] + h[a] * h[a]) < 2 * h[c] * (h[b] - h[a]);
}

bool case2(int a, int b, int c) {
    return ((dp[b] + h[b] * h[b]) - (dp[a] + h[a] * h[a])) * (h[c] - h[b]) > 
        ((dp[c] + h[c] * h[c]) - (dp[b] + h[b] * h[b])) * (h[b] - h[a]);
}

signed main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(n), read(C);
    for(int i = 1;i<=n;++i) read(h[i]);
    dq.push_back(1);
    for(int i = 2;i<=n;++i) {
        while(dq.size() > 1 && case1(dq[0], dq[1], i)) dq.pop_front();
        int j = dq.front();
        dp[i] = dp[j] + (h[i] - h[j]) * (h[i] - h[j]) + C;
        while(dq.size() > 1 && case2(dq[dq.size() - 2], dq.back(), i)) dq.pop_back();
        dq.push_back(i);
    }
    print(dp[n], '\n');
    return 0;
}
