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

const int N = 5e3 + 5;
int dist[N], n, t[N], in[N];
vector<int> e[N];

struct cmp {
    bool operator()(const int& a, const int& b) {
        return dist[a] + t[a] > dist[b] + t[b];
    }
};
priority_queue<int, vector<int>, cmp> heap;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(n);
    for(int i = 1;i<=n;++i) {
        t[i] = read();
        in[i] = read();
        if(in[i] == 0) heap.push(i);
        for(int j = 1;j<=in[i];++j) e[read()].push_back(i);
    }
    int ans = 0;
    while(!heap.empty()) {
        int u = heap.top(); heap.pop();
        dist[u] += t[u];
        ans = max(ans, dist[u]);
        for(int v : e[u]) {
            in[v]--;
            if(in[v] == 0) dist[v] = dist[u], heap.push(v);
        }
    }
    print(ans, '\n');
    return 0;
}

