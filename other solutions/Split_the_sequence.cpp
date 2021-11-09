#include <bits/stdc++.h>
using namespace std;
#define ll __int128

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
const int N = 1e5 + 10;
int n, K, a[N];
ll sum[N], dp[2][N]; // first n, with k operations
int fa[210][N];

deque<ll> dq;

bool case1(int i, int j, int c, int k) {
    return dp[c & 1][j] - dp[c & 1][i] >= 
            (sum[n] - sum[k]) * (sum[j] - sum[i]);
}

bool case2(int i, int j, int k, int c) {
    return (dp[c & 1][j] - dp[c & 1][i]) * (sum[k] - sum[j]) <= 
        (dp[c & 1][k] - dp[c & 1][j]) * (sum[j] - sum[i]);
}

signed main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(n), read(K);
    if(n == 1) {
        putchar('0');
        return 0;
    }
    for(int i = 1;i<=n;++i) {
        read(a[i]);
        sum[i] = sum[i - 1] + a[i];
    }
    for(int k = 1;k<=K + 1;++k) {
        dq.push_back(0);
        for(int i = 1;i<=n;++i) {
            while(dq.size() > 1 && case1(dq.front(), dq[1], k - 1, i)) dq.pop_front(); 
            int j = dq.front();
            fa[k][i] = j;
            dp[k & 1][i] = dp[k & 1 ^ 1][j] + (sum[n] - sum[i]) * (sum[i] - sum[j]);
            while(dq.size() > 1 && case2(dq[dq.size() - 2], dq.back(), i, k - 1)) dq.pop_back();
            dq.push_back(i);
        }
        memset(dp[k & 1 ^ 1], 0, sizeof(dp[k & 1 ^ 1]));
        dq.clear();
    }
    print(dp[K & 1 ^ 1][n], '\n');
    int i = n, j = K + 1;
    set<int> vis;
    while(j > 1 && i > 0) {
        print(fa[j][i], ' ');
        i = fa[j][i];
        j--;
    }
    putchar('\n');
    return 0;
}
