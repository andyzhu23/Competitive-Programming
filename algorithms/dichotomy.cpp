#pragma GCC optimize("O3")
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
const int N = 3e5 + 10;
#define pb push_back
using ll = long long;
vector<int> pos[N];
int a[N], oa[N], ans[N];
int n, m, k;

struct metero {
    int l, r, a;
} met[N];

struct fenwick {
    ll c[N], d[N];
    inline void update(int a, ll b) {
        for(int i = a;i<N;i += i & (-i)) c[i] += b, d[i] += (a - 1) * b;
    }
    inline void update(int a, int b, ll c) {
        update(a, c);
        update(b + 1, -c);
    }
    inline ll query(int a) {
        ll ans = 0;
        for(int i = a;i;i -= i & (-i)) ans += a * c[i] - d[i];
        return ans;
    }
    ll query(int a, int b) {return query(b) - query(a - 1);}
} fen;

inline void solve(int l, int r, vector<int> b) {
    if (l == r) {
        for (auto x : b) ans[x] = l;
        return;
    }
    int mid = l + r >> 1;
    vector<int> bl, br;
    for (int i = l; i <= mid; ++i) {
        if (met[i].l <= met[i].r) fen.update(met[i].l, met[i].r, met[i].a);
        else fen.update(1, met[i].r, met[i].a), fen.update(met[i].l, m, met[i].a);
    }
    for (auto x : b) {
        __int128 tot = 0;
        for (auto y : pos[x])
            tot += fen.query(y, y);
        if (tot < a[x]) br.pb(x), a[x] -= tot;
        else bl.pb(x);
    }
    for (int i = l; i <= mid; ++i) {
        if (met[i].l <= met[i].r) fen.update(met[i].l, met[i].r, -met[i].a);
        else fen.update(1, met[i].r, -met[i].a), fen.update(met[i].l, m, -met[i].a);
    }
    solve(l, mid, bl), solve(mid + 1, r, br);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    memset(ans, -1, sizeof(ans));
    read(n), read(m);
    for(int i = 1;i<=m;++i) {
        int x = read();
        pos[x].pb(i);
    }
    for(int i = 1;i<=n;++i) a[i] = oa[i] = read();
    vector<int> b;
    for(int i = 1;i<=n;++i) b.pb(i);
    read(k);
    for(int i = 1;i<=k;++i) {
        int l = read(), r = read(), a = read();
        met[i] = {l, r, a};
    }
    solve(1, k, b);
    for(int i = 1;i<=k;++i) {
        if (met[i].l <= met[i].r) fen.update(met[i].l, met[i].r, met[i].a);
        else fen.update(1, met[i].r, met[i].a), fen.update(met[i].l, m, met[i].a);
    }
    for (auto x : b) {
        __int128 tot = 0;
        for(auto y : pos[x])
            tot += fen.query(y, y);
        if(tot < oa[x]) ans[x] = -1;
    }
    for(int i = 1;i<=n;++i) {
        if(ans[i] != -1) print(ans[i], '\n');
        else putchar('N'), putchar('I'), putchar('E'), putchar('\n');
    }
    return 0;
}
