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
using ll = long long;
const int N = 1e5 + 5;
const ll mod = 1e9;
int n, m, dfn[N], low[N], tot, color, circ[N], c[N], in[N];
vector<int> e[N], stk;
vector<int> dag[N];
bool instk[N];
ll dp[N];

void tarjan(int u) {
    dfn[u] = low[u] = ++tot;
    stk.pb(u);
    instk[u] = 1;
    for(int v : e[u]) {
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if(instk[v]) low[u] = min(low[u], dfn[v]);
    }
    if(dfn[u] == low[u]) {
        ++color;
        while(stk.back() != u) {
            int v = stk.back(); stk.pop_back();
            circ[color] = 1;
            instk[v] = 0;
            c[v] = color;
        }
        int v = stk.back(); stk.pop_back();
        instk[v] = 0;
        c[v] = color;
    }
}

bool vis[N], flag[N];
ll dfs(int u) {
    if(vis[u]) return dp[u];
    vis[u] = 1;
    for(int v : dag[u]) {
        if(dp[u] + dfs(v) >= mod) flag[u] = 1;
        flag[u] |= flag[v];
        dp[u] = (dp[u] + dfs(v)) % mod;
        circ[u] |= circ[v] * dp[v];
    }
    return dp[u];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(n), read(m);
    for(int i = 1;i<=m;++i) {
        int a = read(), b = read();
        e[a].pb(b);
    }
    for(int i = 1;i<=n;++i) if(!dfn[i]) tarjan(i);
    for(int u = 1;u<=n;++u)
        for(int v : e[u]) if(c[u] != c[v]){
                dag[c[v]].pb(c[u]);
            }
    vis[c[1]] = 1;
    dp[c[1]] = 1;
    dfs(c[2]);
    if(circ[c[2]]) {
        puts("inf");
        return 0;
    } else if(flag[c[2]]) {
        ll u = dp[c[2]];
        int cnt = 10;
        while(u) {
            --cnt;
            u /= 10;
        }
        while(--cnt) putchar('0');
    }
    print(dp[c[2]], '\n');
    return 0;
}


