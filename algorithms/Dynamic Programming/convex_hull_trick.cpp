#include <bits/stdc++.h>
using namespace std;

namespace fast_io {
    using ll = long long;
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
    int read(int& x) {return x = read();}
    ll read(ll& x) {return x = readLL();}
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

const int N = 5e5 + 10;
int n, m;
ll sum[N], dp[N];

deque<int> dq;

bool case1(int i, int j, int c) {
    return ((dp[j] + sum[j] * sum[j]) - (dp[i] + sum[i] * sum[i])) <= 2 * sum[c] * (sum[j] - sum[i]);
}

bool case2(int i, int j, int k) {
    return ((dp[j] + sum[j] * sum[j]) - (dp[i] + sum[i] * sum[i])) *  (sum[k] - sum[j]) >=
    ((dp[k] + sum[k] * sum[k]) - (dp[j] + sum[j] * sum[j])) * (sum[j] - sum[i]);
}

void solve() {
    read(m);
    for(int i = 1;i<=n;++i) sum[i] = readLL() + sum[i - 1];
    memset(dp, 0, sizeof(dp));
    dq.push_back(0);
    for(int i = 1;i<=n;++i) {
        while(dq.size() > 1 && case1(dq[0], dq[1], i)) dq.pop_front();
        int j = dq.front();
        dp[i] = dp[j] + (sum[i] - sum[j]) * (sum[i] - sum[j]) + m;
        while(dq.size() > 1 && case2(dq[dq.size() - 2], dq.back(), i)) dq.pop_back();
        dq.push_back(i);
    }
    while(!dq.empty()) dq.pop_back();
    print(dp[n], '\n');
    return;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while(cin>>n) 
        solve();
    return 0;
}
