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
#define pb push_back
using ull = unsigned long long;

vector<int> prime;
bool p[100000];

struct tree_hashing {
    vector<int> e[N], heavy;
    int tot, root, siz[N];
    ull f[N];
    vector<ull> ans;
    void dfs(int u, int fa) {
        siz[u] = 1;
        for(int v : e[u]) {
            if(v == fa) continue;
            dfs(v, u);
            siz[u] += siz[v];
        }
    }
    void dfs2(int u, int fa) {
        bool flag = siz[u] >= tot / 2, flag2 = 0;
        if(siz[u] == tot / 2) flag2 = 1;
        for(int v : e[u]) {
            if(v == fa) continue;
            if(flag2) flag &= siz[v] < tot / 2;
            else flag &= siz[v] <= tot / 2;
            dfs2(v, u);
        }
        if(flag) heavy.pb(u);
    }
    void dfs3(int u, int fa) {
        f[u] = 1;
        for(int v : e[u]) {
            if(v == fa) continue;
            dfs3(v, u);
            f[u] += f[v] * prime[siz[v]];
        }
    }
    void hashing() {
        dfs(root, 0);
        dfs2(root, 0);
        for(auto x : heavy) {
            root = x;
            dfs(root, 0);
            dfs3(root, 0);
            ans.pb(f[root]);
        }
    }
} th[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    for(int i = 2;i<=1e5;++i) {
        if(p[i]) continue;
        prime.pb(i);
        for(int j = i + i; j <= 1e5;j += i) p[j] = 1;
    }
    int t = read();
    for(int i = 1;i<=t;++i) {
        int n = th[i].tot = read();
        for(int j = 1;j<=n;++j) {
            int x = read();
            if(x == 0) th[i].root = j;
            else {
                th[i].e[j].pb(x);
                th[i].e[x].pb(j);
            }
        }
        th[i].hashing();
    }
    for(int i = 1;i<=t;++i) {
        bool flag = 0;
        for(int j = 1;j<=t;++j) {
            if(th[i].tot != th[j].tot) continue;
            for(auto x : th[i].ans) {
                for(auto y : th[j].ans) {
                    if(x == y) {
                        print(j, '\n');
                        flag = 1;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag) break;
        }
    }
    return 0;
}
