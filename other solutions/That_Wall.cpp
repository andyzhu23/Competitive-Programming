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

const int N = 200;

int n, k;
ll c[N], h[N], best[N][N], dp[N][N];

ll cal(ll a, int i, int j) {
    ll ans = 0;
    for(int k = i;k<=j;++k) {
        ans += c[k] * abs(a - h[k]);
    }
    return ans;
}

ll binarySearch(int i, int j) {
    ll l = 0, r = 1e6, ans = 0;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(cal(mid, i, j) > cal(mid + 1, i, j)) {
            l = mid + 1;
            ans = mid + 1;
        } else {
            r = mid - 1;
            ans = mid;
        }
    }
    return ans;
}
/*
1786514772
1786469334
*/

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(n), read(k);
    for(int i = 1;i<=n;++i) c[i] = read();
    for(int j = 1;j<=n;++j) h[j] = read();
    for(int i = 1;i<=n;++i) {
        for(int j = i;j<=n;++j) {
            best[i][j] = binarySearch(i, j);
            // cout<<best[i][j]<<' ';
            best[i][j] = cal(best[i][j], i, j);
            // cout<<best[i][j]<<' ';
        }
        // cout<<'\n';
    }
    memset(dp, 0x3f, sizeof(dp));
    memset(dp[0], 0, sizeof(dp[0]));
    for(int i = 1;i<=n;++i) {
        dp[i][0] = cal(0, 1, i);
    }
    for(int b = 1;b<=k;++b) {
        for(int a = 1;a<=n;++a) {
            for(int c = 0;c<a;++c) {
                dp[a][b] = min(dp[a][b], dp[c][b - 1] + best[c + 1][a]);
            }
        }
    }
    print(dp[n][k], '\n');
    return 0;
}
