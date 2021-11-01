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

#define mp make_pair
#define fir first
#define sec second
#define pb push_back
using pii = pair<int, int>;
using ll = long long;
const int N = 1e5 + 10;
vector<pii> e[N];
int n;

struct node {
    int mx, smx;
    node operator+(const node& other) const {
        node ans;
        ans.mx = max(mx, other.mx);
        ans.smx = max(smx, other.smx);
        ans.smx = max(ans.smx, ans.mx == mx ? other.mx : mx);
        return ans;
    }
};

int dep[N], f[N][30];
unordered_set<int> vis[N];
node dist[N][30];

void dfs(int u, int fa, int d) {
    dep[u] = dep[fa] + 1;
    f[u][0] = fa;
    dist[u][0] = {d, -1};
    for(int i = 1;i<22;++i) 
        f[u][i] = f[f[u][i - 1]][i - 1], 
        dist[u][i] = dist[u][i - 1] + dist[f[u][i - 1]][i - 1];
    for(pii v : e[u]) {
        if(v.fir == fa) continue;
        dfs(v.fir, u, v.sec);
    }
}

node lca(int u, int v) {
    if(dep[u] < dep[v]) swap(u, v);
    node ans = {-1, -1};
    for(int i = 21;i>=0;--i) {
        if(dep[f[u][i]] >= dep[v]) {
            ans = ans + dist[u][i];
            u = f[u][i];
        }
        if(u == v) return ans;
    }
    for(int i = 21;i>=0;--i) {
        if(f[u][i] != f[v][i]) {
            ans = ans + dist[u][i] + dist[v][i];
            u = f[u][i], v = f[v][i];
        }
    }
    ans = ans + dist[u][0] + dist[v][0];
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(n);
    for(int i = 1;i<n;++i) {
        int u = read(), v = read(), w = read();
        e[u].pb(mp(v, w));
        e[v].pb(mp(u, w));
        vis[u].insert(v);
        vis[v].insert(u);
    }
    int q = read();
    dfs(1, 0, 0);
    while(q--) {
        int s = read(), t = read();
        if(vis[s].count(t)) print(-1, '\n');
        else print(lca(s, t).smx, '\n');
    }
    return 0;
}
