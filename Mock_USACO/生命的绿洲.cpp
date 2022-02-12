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

const int N = 1e6 + 10;
using ll = __int128;
const ll INF = 0x7f7f7f7f7f7f7f7f;
using pii = pair<int, int>;
#define fir first
#define sec second
#define pb push_back
vector<pii> e[N];
ll dist[N];

struct cmp {
    inline bool operator() (const int& a, const int& b) {
        return dist[a] > dist[b];
    }
};
priority_queue<int, vector<int>, cmp> heap;

int n, m, V;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(n), read(m), read(V);
    for(int i = 1;i<=m;++i) {
        int u = read(), v = read(), w = read();
        e[u].pb({v, w});
        e[v].pb({u, w});
    }
    memset(dist, 0x7f, sizeof(dist));
    dist[n] = 0;
    heap.push(n);
    while(!heap.empty()) {
        int u = heap.top(); heap.pop();
        for(pii x : e[u]) {
            int v = x.fir;
            ll w = x.sec;
            ll c = 0;
            if(V - 2ll * w >= dist[u]) c = dist[u] + w;
            else {
                if(V <= 3ll * w) continue;
                c = ((dist[u] - (V - 2ll * w) - 1) / (V - 3ll * w) + 1) * 2 * w + w + dist[u];
            }
            if(dist[v] > c) {
                dist[v] = c;
                heap.push(v);
            }
        }
    }
    print(dist[1] >= INF ? -1 : dist[1], '\n');
    return 0;
}
