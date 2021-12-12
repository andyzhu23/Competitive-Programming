#pragma GCC optimize(2)
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

const int N = 1e5 + 10;
int n, m, t[N], f[N][22], dep[N];
vector<int> e[N];
#define pb push_back
#define fir first
#define sec second
using pii = pair<int, int>;

unordered_map<int, int> ans[N];
int cnt[N];

struct query {
    int a, b, c, lca;
};
vector<query> q;

void dfs(int u = 1, int fa = 0) {
    dep[u] = dep[fa] + 1;
    f[u][0] = fa;
    for(int i = 1;i<22;++i) f[u][i] = f[f[u][i - 1]][i - 1];
    for(int v : e[u]) {
        if(v == fa) continue;
        dfs(v, u);
    }
}

int LCA(int u, int v) {
    if(dep[u] < dep[v]) swap(u, v);
    for(int i = 21;i>=0;--i) {
        if(dep[f[u][i]] >= dep[v]) u = f[u][i];
        if(u == v) return u;
    }
    for(int i = 21;i>=0;--i) {
        if(f[u][i] != f[v][i]) u = f[u][i], v = f[v][i];
    }
    return f[u][0];
}

void dfs2(int u = 1, int fa = 0) {
    cnt[t[u]]++;
    for(auto& a : ans[u]) {
        a.sec = cnt[a.fir];
    }
    for(int v : e[u]) {
        if(v == fa) continue;
        dfs2(v, u);
    }
    cnt[t[u]]--;
}

int main() {
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    read(n), read(m);
    for(int i = 1;i<=n;++i) cin>>t[i];
    for(int i = 1;i<n;++i) {
        int u = read(), v = read();
        e[u].pb(v);
        e[v].pb(u);
    }
    dfs();
    for(int i = 1;i<=m;++i) {
        int a = read(), b = read(), c = read(), lca;
        lca = LCA(a, b);
        q.pb({a, b, c, lca});
        ans[a][c] = 0;
        ans[b][c] = 0;
        ans[lca][c] = 0;
    }
    dfs2();
    for(auto& x : q) {
        putchar((bool)(ans[x.a][x.c] + ans[x.b][x.c] - 2 * ans[x.lca][x.c] + (t[x.lca] == x.c)) ? '1' : '0');
    }
    putchar('\n');
    return 0;
}
