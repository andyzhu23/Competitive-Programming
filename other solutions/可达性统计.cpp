/*
 * Author: Andy Zhu
 * @date    2022-03-10 21:19:45
 * @version 1.0.0
 */

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
#define pb push_back
const int N = 3e4 + 5;
vector<int> e[N];
int in[N];
bitset<N> bs[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n = read(), m = read();
    for(int i = 1;i<=m;++i) {
        int u = read(), v = read();
        e[v].pb(u);
        ++in[u];
    }
    queue<int> q;
    for(int i = 1;i<=n;++i) if(!in[i]) q.push(i);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        bs[u][u] = 1;
        for(int v : e[u]) {
            bs[v] |= bs[u];
            --in[v];
            if(!in[v]) q.push(v);
        }
    }
    for(int i = 1;i<=n;++i) print(bs[i].count(), '\n');
}
