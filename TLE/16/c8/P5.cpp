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

const int N = 205;
int e[N][N], n, m, s = 0, t, ans, last[N], mn[N];
bitset<N> vis;

bool bfs() {
    vis.reset();
    memset(mn, 0x3f, sizeof(mn));
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        if(u == t) break;
        for(int v = s;v <= t;++v) if(e[u][v] && !vis[v]) {
            if(v > n && v <= n + m && !e[1][v]) continue; 
            vis[v] = 1;
            last[v] = u;
            mn[v] = min(mn[v], e[u][v]);
            q.push(v);
        }
    }
    return vis[t];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    n = read(), m = read();
    t = n + m + 1;
    for(int i = 1;i<=n;++i) {
        int t = read();
        if(i == 1) ans = t;
        while(t--) {
            int v = read() + n;
            e[i][v] = 1;
        }
    }
    for(int i = 2;i<=n;++i) e[s][i] = 1;
    for(int i = n + 1;i<=n + m;++i) e[i][t] = 1;
    while(bfs()) {
        int u = t;
        while(u != s) {
            e[last[u]][u] -= mn[t];
            e[u][last[u]] += mn[t];
            u = last[u];
        }
        ans -= mn[t];
    }
    print(ans, '\n');
    return 0;
}

