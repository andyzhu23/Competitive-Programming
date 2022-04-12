#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
const ll inf = 0x3f3f3f3f;
#define f first
#define s second
#define lc (rt << 1)
#define rc (rt << 1 | 1)
const int N = 1e5 + 5;
pll c[N];
ll p[N], dp[N];
int tot = 0, st[N << 2], n;

struct car {
    ll p, s, c, d;
    bool operator<(const car& other) const {
        return p < other.p;
    }
} a[N];

void add(ll m, ll b) {
    c[++tot] = {m, b};
}

ll calc(int idx, int x) {
    return c[idx].s + c[idx].f * p[x];
}

void update(int rt, int l, int r, int x, int y, int u) {
    int mid = l + r >> 1;
    if(y < l || x > r) return;
    if(x <= l && r <= y) {
        int v = st[rt];
        if(c[v].f < c[u].f) swap(u, v);
        ll resu = calc(u, mid);
        ll resv = calc(v, mid);
        if(c[v].f == c[u].f || l == r) st[rt] = resu > resv ? v : u;
        else if(resv > resu) {
            st[rt] = u;
            update(lc, l, mid, x, y, v);
        } else {
            st[rt] = v;
            update(rc, mid + 1, r, x, y, u);
        }
        return;
    }
    update(lc, l, mid, x, y, u);
    update(rc, mid + 1, r, x, y, u);
}

ll query(int rt, int l, int r, int x) {
    if(l == r) return calc(st[rt], x);
    int mid = l + r >> 1;
    if(x <= mid) return min(calc(st[rt], x), query(lc, l, mid, x));
    else return min(calc(st[rt], x), query(rc, mid + 1, r, x));
}

int bs(ll x) {
    int lo = 1, hi = n, ans;
    while(lo <= hi) {
        int mid = lo + hi >> 1;
        if(a[mid].p <= x) ans = mid, lo = mid + 1;
        else hi = mid - 1;
    }
    return ans;
}

set<int> comp;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    for(int i = 1;i<=n;++i) {
        cin>>a[i].p>>a[i].s>>a[i].c>>a[i].d;
        comp.insert(a[i].p);
    }
    int len = 0;
    for(auto x : comp) p[++len] = x;
    sort(a + 1, a + n + 1);
    c[0] = {inf, inf};
    add(0, 0);
    update(1, 0, n, 0, 1, tot);
    for(int i = 1;i<=n;++i) {
        dp[i] = query(1, 0, n, i);
        int j = bs(a[i].p + a[i].s);
        add(a[i].c, dp[i] + a[i].d - a[i].p * a[i].c);
        update(1, 0, n, i, j, tot);
        // cout<<dp[i]<<'\n';
    }
    cout<<dp[n]<<'\n';
    return 0;
}