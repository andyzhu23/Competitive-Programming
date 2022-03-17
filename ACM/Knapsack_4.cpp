#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
namespace fast_io {
    inline int read() {
        int x = 0, f = 0; char ch = getchar();
        while (!isdigit(ch)) f |= ch == '-', ch = getchar();
        while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
            return f ? -x : x;
    }
    inline void read(int& x) {x = read();}
    template<typename T> inline void print(T x) {
        if (x < 0) putchar('-'), x = -x;
        if (x >= 10) print(x / 10);
            putchar(x % 10 + '0');
    }
    template<typename T> inline void print(T x, char let) {
        print(x), putchar(let);
    }
}
using namespace fast_io;
using pii = pair<int, int>;
const int N = 1001;
const int NN = 200005;
ll dp[NN];
vector<pii> x;

int main(){
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    srand(time(NULL));
    int t = read();
    while(t--) {
        int n = read(), m = read();
        memset(dp, -0x3f, sizeof(dp));
        x.clear();
        dp[100000] = 0;
        for(int i = 1;i<=n;++i) {
            int u = read(), v = read();
            x.push_back({u, v});
        }
        for(int i = 1;i<=m;++i) {
            int u = -read(), v = read();
            x.push_back({u, v});
        }
        random_shuffle(x.begin(), x.end());
        for(auto[w, v] : x) {
            if(w > 0) for(int i = NN - 1;i >= w;--i) {
                dp[i] = max(dp[i], dp[i - w] + v);
            }
            else for(int i = 0;i<NN + w;++i) {
                dp[i] = max(dp[i], dp[i - w] + v);
            }
        }
        print(dp[100000], '\n');
    }
    return 0;
}

