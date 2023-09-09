#pragma GCC optimize(2)

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
using pii = pair<int, int>;
const int N = 1e6 + 5;
const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

#define get(x, y) ((x - 1) * m + y) 

int n, m;
char c[N], ans[N];
int prv[N];

bitset<N> vis;

int f[N], h[N];
vector<int> a[N];

inline int Find(int x) {return f[x] == x ? x : f[x] = Find(f[x]);}
inline void merge(int u, int v) {
    int fu = Find(u);
    int fv = Find(v);
    if(fu == fv) return;
    f[fv] = fu;
    h[fu] = min(h[fu], h[fv]);
    if(a[fv].size() > a[fu].size()) swap(a[fu], a[fv]);
    for(auto x : a[fv]) {
        a[fu].pb(x);
    }
}

set<pii> heap;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for(int i = 1;i<=n;++i) {
        scanf("%s", c + get(i, 1));
        for(int j = 1;j<=m;++j) {
            int x = get(i, j);
            if(c[get(i, j)] == '#') {
                f[get(i, j)] = get(i, j);
                h[x] = n - i;
                a[x].pb(x);
            }
            if(i > 1) prv[get(i, j)] = c[get(i, j)] == '#' ? i : prv[get(i - 1, j)];
            else prv[get(i, j)] = c[get(i, j)] == '#' ? i : 0;
            ans[get(i, j)] = '.';
        }
    }
    for(int i = 1;i<=n;++i) {
        for(int j = 1;j<=m;++j) if(c[get(i, j)] == '#') {
            for(int k = 0;k<4;++k) {
                int ii = i + dir[k][0];
                int jj = j + dir[k][1];
                if(ii > 0 && ii <= n && jj > 0 && jj <= m && c[get(ii, jj)] == '#') 
                    merge(get(i, j), get(ii, jj));
            }
        }
    }
    for(int i = 1;i<=n;++i) {
        for(int j = 1;j<=m;++j) if(c[get(i, j)] == '#') {
            int x = Find(get(i, j));
            if(!vis[x]) {
                vis[x] = 1;
                heap.insert({h[x], x});
            }
        }
    }
    vis.reset();
    while(!heap.empty()) {
        auto[hu, u] = *heap.begin(); heap.erase(heap.begin());
        if(hu != h[u]) continue;
        vis[u] = 1;
        for(auto y : a[u]) {
            int i = (y - 1) % m + 1;
            y = (y - 1) / m + 1;
            int j = y == 1 ? 0 : prv[get(y - 1, i)];
            if(j && !vis[Find(get(j, i))]) {
                int x = Find(get(j, i));
                heap.erase({h[x], x});
                h[x] = min(h[x], y + h[u] - 1 - j);
                heap.insert({h[x], x});
            }
        }
    }
    for(int i = 1;i<=n;++i) {
        for(int j = 1;j<=m;++j) if(c[get(i, j)] == '#') {
            int x = Find(get(i, j));
            ans[get(i + h[x], j)] = '#';
        }
    }
    for(int i = 1;i<=n;++i) {
        for(int j = 1;j<=m;++j) putchar(ans[get(i, j)]);
        putchar('\n');
    }
    return 0;
}
