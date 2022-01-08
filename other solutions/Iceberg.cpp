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
const int N = 2e3 + 10;
const int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int l, r, w, c, sum[N][N];
bool vis[N][N];

struct node {
    int x, y, d;
};

queue<node> q;
int get(int x, int y, int z, int w) {
    return sum[z][w] - sum[x - 1][w] - sum[z][y - 1] + sum[x - 1][y - 1];
}
bool ok(int x, int y) {
    return x > 0 && x <= r && y > 0 && y <= c && get(x, y, x + l - 1, y + w - 1) == 0;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(r), read(c), read(l), read(w);
    for(int i = 1;i<=r;++i) {
        for(int j = 1;j<=c;++j) {
            char c;
            do {c = getchar();} while(c != '.' && c != '#');
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + (c == '#');
        }
    }
    r = r - l + 1;
    c = c - w + 1;
    q.push({1, 1, 0});
    vis[1][1] = 1;
    if(ok(1, 1)) {
        while(!q.empty()) {
            node cur = q.front(); q.pop();
            if(cur.x == r && cur.y == c) {
                print(cur.d, '\n');
                return 0;
            }
            for(int i = 0;i<4;++i) {
                int x = cur.x + dir[i][0];
                int y = cur.y + dir[i][1];
                if(vis[x][y]) continue;
                vis[x][y] = 1;
                if(ok(x, y)) q.push({x, y, cur.d + 1});
            }
        }
    }
    puts("-1");
    return 0;
}
