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
using pii = pair<int, int>;
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
int n, dist[N];

vector<pii> e[N];

void dfs(int u, int fa, int d) {
    dist[u] = dist[fa] ^ d;
    for(pii v : e[u]) {
        if(v.fir == fa) continue;
        dfs(v.fir, u, v.sec);
    }
}

struct Trie {
    int tr[N * 30][2], tot = 0;
    void update(int u) {
        int cur = 0;
        for(int i = 31;i>=0;--i) {
            bool a = (1 << i) & u;
            if(!tr[cur][a]) tr[cur][a] = ++tot;
            cur = tr[cur][a];
            // cout<<cur<<'\n';
        }
    }
    int query(int u) {
        int cur = 0;
        int ans = 0;
        for(int i = 31;i>=0;--i) {
            bool a = (1 << i) & u;
            if(tr[cur][a ^ 1]) {
                cur = tr[cur][a ^ 1];
                ans |= 1 << i;
            } else cur = tr[cur][a];
        }
        return ans;
    }
} trie;

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
    }
    dfs(1, 0, 0);
    for(int i = 1;i<=n;++i) {
        trie.update(dist[i]);
    }
    int ans = 0;
    for(int i = 1;i<=n;++i) {
        ans = max(ans, trie.query(dist[i]));
    }
    print(ans, '\n');
}
