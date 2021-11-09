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

const int N = 1e5 + 10;
int n, h;
ll a[N], dp[N];

ll cal(int i, int j) {
    return dp[j] + h + (a[i] - a[j + 1]) * (a[i] - a[j + 1]);
}

bool case1(int i, int j, int c) {
    return dp[i] + a[i + 1] * a[i + 1] - (dp[j] + a[j + 1] * a[j + 1])
        <= 2 * a[c] * (a[i + 1] - a[j + 1]);
}

bool case2(int i, int j, int c) {
    return (dp[c] + a[c + 1] * a[c + 1] - (dp[j] + a[j + 1] * a[j + 1])) * (a[j + 1] - a[i + 1])
        >= (dp[j] + a[j + 1] * a[j + 1] - (dp[i] + a[i + 1] * a[i + 1])) * (a[c + 1] - a[j + 1]);
}

deque<int> dq;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(n), read(h);
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for(int i = 1;i<=n;++i) a[i] = read();
    dq.push_back(0);
    for(int i = 1;i<=n;++i) {
        while(dq.size() > 1 && case1(dq[1], dq[0], i)) dq.pop_front();
        dp[i] = cal(i, dq.front());
        while(dq.size() > 1 && case2(dq.back(), dq[dq.size() - 2], i))
            dq.pop_back();
        dq.push_back(i);
    }
    print(dp[n], '\n');
    return 0;
}