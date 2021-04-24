#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory.h>
#define f first
#define s second
#define mp make_pair
#define endl "\n"
#define pb emplace_back
using namespace std;
using ll = long long;
typedef pair<int, int> PI;
const int N = 5e4 + 10;
const int L = 2e5 + 10;
const int Q = 1e5 + 10;
int n, q;
ll ans[Q], st[L << 2];

struct path {
    int l, v;
    ll a;

    path(int LL, ll A, int V) {
        l = LL, a = A, v = V;
    }
};

vector<path> e[N];
unordered_map<int, vector<PI>> Map;

inline ll gcd(ll x, ll y) {
    if (y == 0) return x;
    if (x == 0) return y;
    return gcd(y, x % y);
}

inline void push_up(int rt) {
    st[rt] = gcd(st[rt << 1], st[rt << 1 | 1]);
}

inline ll query(int rt, int l, int r, int x, int y) {
    if (l == x && y == r)
        return st[rt];
    int mid = (l + r) >> 1;
    if (y <= mid) return query(rt << 1, l, mid, x, y);
    else if (x > mid) return query(rt << 1 | 1, mid + 1, r, x, y);
    return gcd(query(rt << 1, l, mid, x, mid), query(rt << 1 | 1, mid + 1, r, mid + 1, y));
}

inline void update(int rt, int l, int r, int pos, ll val) {
    if (l == r) {
        st[rt] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) update(rt << 1, l, mid, pos, val);
    else update(rt << 1 | 1, mid + 1, r, pos, val);
    push_up(rt);
}

inline void dfs(int u, int fa) {
    for (PI i : Map[u])
        ans[i.s] = query(1, 1, L, 1, i.f);
    for (path v : e[u]) {
        if (v.v == fa) continue;
        update(1, 1, L, v.l, v.a);
        dfs(v.v, u);
        update(1, 1, L, v.l, 0);
    }
}

inline void init() {
    for (int i = 1; i <= n; i++)
        e[i].clear();
    memset(ans, 0, sizeof(ans));
    memset(st, 0, sizeof(st));
    Map.clear();
}

inline void solve() {
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v, l;
        ll a;
        cin >> u >> v >> l >> a;
        e[u].pb(path(l, a, v));
        e[v].pb(path(l, a, u));
    }
    for (int i = 1; i <= q; i++) {
        int c, w;
        cin >> c >> w;
        Map[c].pb(mp(w, i));
    }
    dfs(1, 0);
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        init();
        solve();
        cout << endl;
    }
    return 0;
}
