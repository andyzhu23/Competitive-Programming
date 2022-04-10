#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5;
const int inf = 0x3f3f3f3f;
#define int long long
#define lc (rt << 1)
#define rc (rt << 1 | 1)
#define f first
#define s second
using pdd = pair<double, double>;
using pdi = pair<double, int>;
int n, tot, st[N << 2];
pdd c[N];

void add(double a, double b) {
    c[++tot] = {a, b};
}

double calc(int idx, int pos) {
    return c[idx].f + c[idx].s * (pos - 1);
}

void update(int rt, int l, int r, int x, int y, int u) {
    int mid = l + r >> 1;
    if(y < l || r < x) return;
    if(x <= l && r <= y) {
        int v = st[rt];
        if(c[u].s > c[v].s) swap(u, v);
        double resu = calc(u, mid), resv = calc(v, mid);
        if(c[u].s == c[v].s || l == r) st[rt] = resu > resv ? u : v;
        else if(resu > resv) {
            st[rt] = u;
            update(rc, mid + 1, r, x, y, v);
        } else {
            st[rt] = v;
            update(lc, l, mid, x, y, u);
        }
        return;
    }
    update(lc, l, mid, x, y, u);
    update(rc, mid + 1, r, x, y, u);
}

double query(int rt, int l, int r, int x) {
    if(l > x || r < x) return 0;
    if(l == r) return calc(st[rt], x);
    int mid = l + r >> 1;
    return max({calc(st[rt], x), query(lc, l, mid, x), query(rc, mid + 1, r, x)});
}

signed main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    while(n--) {
        string s; cin>>s;
        if(s == "Project") {
            double a, b;
            cin>>a>>b;
            add(a, b);
            update(1, 1, N - 5, 1, N - 5, tot);
        } else {
            int x; cin>>x;
            cout<<(int)(query(1, 1, N - 5, x) / 100)<<'\n';
        }
    }
    return 0;
}
