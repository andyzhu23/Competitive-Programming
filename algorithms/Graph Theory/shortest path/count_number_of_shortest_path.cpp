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
const int MOD = 100003;
#define pb push_back
vector<int> e[N];
int n, m, dist[N], cnt[N];
bool vis[N];

struct cmp {
    bool operator()(const int& a, const int& b) const {
        return dist[a] > dist[b];
    }
};

priority_queue<int, vector<int>, cmp> heap;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    n = read(), m = read();
    for(int i = 1;i<=m;++i) {
        int a = read(), b = read();
        e[a].pb(b);
        e[b].pb(a);
    }
    heap.push(1);
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0, cnt[1] = 1;
    while(!heap.empty()) {
        int u = heap.top(); heap.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int v : e[u]) {
            if(dist[v] > dist[u] + 1) {
                cnt[v] = cnt[u];
                dist[v] = dist[u] + 1;
                heap.push(v);
            } else if(dist[v] == dist[u] + 1) cnt[v] = (cnt[v] + cnt[u]) % MOD;
        }
    }
    for(int i = 1;i<=n;++i) print(cnt[i], '\n');
    return 0;
}

