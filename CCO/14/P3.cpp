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
#define pb push_back
using pii = pair<int, int>;
using ll = long long;
const int N = 205;
const int mod = 1e9 + 7;
int n, w, m, fa[N], siz[N];
ll dp[N][N][2];
vector<pii> e[N];

void dfs(int u = 0, int fa = -1) {
    dp[u][1][1] = 1;
    dp[u][0][0] = 1;
    for(pii ed : e[u]) {
        int v = ed.first;
        bool t = ed.second;
        if(v == fa) continue;
        dfs(v, u);
        for(int i = w;i>=0;--i) {
            ll ans0 = 0, ans1 = 0;
            for(int j = 0;j<=i;++j) {
                ans0 = (ans0 + dp[u][i - j][0] * (dp[v][j][0] + dp[v][j][1]) % mod) % mod;
                if(t == 0)
                    ans1 = (ans1 + dp[u][i - j][1] * dp[v][j][0] % mod) % mod;
                else 
                    ans1 = (ans1 + dp[u][i - j][1] * dp[v][j][1] % mod) % mod;
            }
            dp[u][i][0] = ans0;
            dp[u][i][1] = ans1;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    n = read(), w = read(), m = read();
    while(m--) {
        char c; do {c = getchar();} while(!isalpha(c));
        int a = read(), b = read();
        e[a].pb({b, c == 'D'});
        fa[b] = a;
    }
    for(int i = 1;i<=n;++i) if(fa[i] == 0) e[0].pb({i, 0});
    dfs();
    print(dp[0][w][0], '\n');
    return 0;
}
