#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

namespace fast_io {
    inline int read() {
        int x = 0, f = 0; char ch = getchar();
        while (!isdigit(ch)) f |= ch == '-', ch = getchar();
        while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
            return f ? -x : x;
    }
    inline void read(int& x) {x = read();}
    template<typename T> inline void print(T x) {
        if (x < 0) putchar('-'), x = -x;
        if (x >= 10) print(x / 10);
            putchar(x % 10 + '0');
    }
    template<typename T> inline void print(T x, char let) {
        print(x), putchar(let);
    }
}
using namespace fast_io;
#define pb push_back
const int N = 1e5 + 10;
int a[N], n, Q, bsiz, block[N];
using ll = long long;
ll ans[N], cnt;

struct query {
    int l, r, id;
    inline bool operator<(const query& other) const {
        if(block[l] == block[other.l]) 
            return l & 1 ? r < other.r : r > other.r;
        else return l < other.l;
    }
};
vector<query> q;

struct fenwick {
    ll c[N];
    inline void update(int a, ll b) {
        for(int i = a;i<=n;i += i & (-i)) c[i] += b;
    }
    inline ll query(int a) {
        ll ans = 0;
        for(int i = a;i;i -= i & (-i)) ans += c[i];
        return ans;
    }
    inline ll query(int a, int b) {
        return query(b) - query(a - 1);
    }
} fen;

set<int> dis;
unordered_map<int, int> Map;

inline void addl(int p) {
    cnt += fen.query(a[p] - 1);
    fen.update(a[p], 1);
}

inline void removel(int p) {
    cnt -= fen.query(a[p] - 1);
    fen.update(a[p], -1);
}

inline void addr(int p) {
    cnt += fen.query(a[p] + 1, n);
    fen.update(a[p], 1);
}

inline void remover(int p) {
    cnt -= fen.query(a[p] + 1, n);
    fen.update(a[p], -1);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    n = read(), Q = read();
    bsiz = sqrt(n);
    for(int i = 1;i<=n;++i) a[i] = read(), dis.insert(a[i]), block[i] = (i - 1) / bsiz + 1;
    int len = 0;
    for(auto x : dis) Map[x] = ++len;
    for(int i = 1;i<=n;++i) a[i] = Map[a[i]];
    for(int i = 1;i<=Q;++i) q.pb({read(), read(), i});
    sort(q.begin(), q.end());
    int l = 1, r = 1;
    addl(1);
    for(auto x : q) {
        while(x.l < l) addl(--l);
        while(x.r > r) addr(++r);
        while(x.l > l) removel(l++);
        while(x.r < r) remover(r--);
        ans[x.id] = cnt;
    }
    for(int i = 1;i<=Q;++i) print(ans[i], '\n');
    return 0;
}
