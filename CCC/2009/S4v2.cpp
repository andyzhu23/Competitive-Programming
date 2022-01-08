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
const int N = 5005;
using pii = pair<int, int>;
#define fir first
#define sec second
#define pb push_back
int n, t, p[N], dist[N];
vector<pii> e[N];
vector<int> a;

struct cmp {
    bool operator()(int& a, int& b) {
        return dist[a] > dist[b];
    }
};
priority_queue<int, vector<int>, cmp> heap;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    memset(dist, 0x3f, sizeof(dist));
    n = read(), t = read();
    int ans = 0x7f7f7f7f;
    while(t--) {
        int u = read(), v = read(), w = read();
        e[u].pb({v, w});
        e[v].pb({u, w});
    }
    int k = read();
    for(int i = 1;i<=k;++i) {
        int x = read();
        a.pb(x);
        p[x] = read();
    }
    int d = read();
    dist[d] = 0;
    heap.push(d);
    while(!heap.empty()) {
        int u = heap.top(); heap.pop();
        for(pii v : e[u]) {
            if(dist[v.fir] > dist[u] + v.sec) {
                dist[v.fir] = dist[u] + v.sec;
                heap.push(v.fir);
            }
        }
    }
    for(auto x : a) ans = min(ans, dist[x] + p[x]);
    print(ans, '\n');
    return 0;
}
