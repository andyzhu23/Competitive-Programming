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
using ll = __int128;
const int N = 2e6 + 10;
int n;
ll L, dp[N], sum[N]; 

deque<ll> dq;

bool case1(ll i, ll j, ll k) {
    return dp[j] + (k - j - 1 + sum[k] - sum[j] - L) * (k - j - 1 + sum[k] - sum[j] - L) <
        dp[i] + (k - i - 1 + sum[k] - sum[i] - L) * (k - i - 1 + sum[k] - sum[i] - L);
}

bool case2(ll i, ll j, ll k) {
    return (dp[k] + (sum[k] - k - 1) * (sum[k] - k - 1) - (dp[j] + (sum[j] - j - 1) * (sum[j] - j - 1)))
        * (sum[j] - j - (sum[i] - i)) < 
        (dp[j] + (sum[j] - j - 1) * (sum[j] - j - 1) - (dp[i] + (sum[i] - i - 1) * (sum[i] - i - 1)))
        * (sum[k] - k - (sum[j] - j));
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    n = read(), L = read();
    for(int i = 1;i<=n;++i) sum[i] = sum[i - 1] + read();
    dq.push_back(0);
    for(ll i = 1;i<=n;++i) {
        while(dq.size() > 1 && case1(dq[0], dq[1], i)) dq.pop_front();
        ll j = dq.front();
        dp[i] = dp[j] + (i - j - 1 + sum[i] - sum[j] - L) * (i - j - 1 + sum[i] - sum[j] - L);
        while(dq.size() > 1 && case2(dq[dq.size() - 2], dq.back(), i)) dq.pop_back();
        dq.push_back(i);
    }
    print(dp[n], '\n');
    return 0;
}
