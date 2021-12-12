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

const int N = 60;
using pii = pair<int, int>;
#define fir first
#define sec second

unordered_set<int> e[N];

void ae(int x, int y) {
    e[x].insert(y);
    e[y].insert(x);
}

void init() {
    ae(2, 6);
    ae(1, 6);
    ae(3, 6);
    ae(4, 6);
    ae(5, 6);
    ae(7, 6);
    ae(3, 4);
    ae(5, 4);
    ae(3, 5);
    ae(3, 15);
    ae(15, 13);
    ae(13, 14);
    ae(13, 12);
    ae(11, 12);
    ae(9, 12);
    ae(11, 10);
    ae(9, 10);
    ae(9, 8);
    ae(7, 8);
    ae(17, 16);
    ae(18, 16);
    ae(17, 18);
}

void i() {
    int x = read(), y = read();
    e[x].insert(y);
    e[y].insert(x);
}

void d() {
    int x = read(), y = read();
    e[x].erase(y);
    e[y].erase(x);
}

void n() {
    print(e[read()].size(), '\n');
}

void f() {
    unordered_set<int> vis;
    int x = read();
    for(auto y : e[x]) {
        for(auto z : e[y]) {
            vis.insert(z);
        }
    }
    vis.erase(x);
    for(auto y : e[x]) vis.erase(y);
    print(vis.size(), '\n');
}

bool vis[N];

void s() {
    queue<pii> q;
    int x = read(), y = read();
    q.push({x, 0});
    memset(vis, 0, sizeof(vis));
    while(!q.empty()) {
        pii u = q.front(); q.pop();
        if(u.fir == y) {
            print(u.sec, '\n');
            return;
        }
        for(int v : e[u.fir]) {
            if(vis[v]) continue;
            vis[v] = 1;
            q.push({v, u.sec + 1});
        }
    }
    puts("Not connected");
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    init();
    while(1) {
        char c = getchar();
        while(!isalpha(c)) c = getchar();
        if(c == 'q') break;
        switch (c) {
            case 'i': i(); break;
            case 'd': d(); break;
            case 'n': n(); break;
            case 'f': f(); break;
            case 's': s(); break;
        }
    }
    return 0;
}

