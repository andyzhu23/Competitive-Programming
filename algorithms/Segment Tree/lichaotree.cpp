#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define lc (rt << 1)
#define rc (rt << 1 | 1)
using pdd = pair<double, double>;
using pdi = pair<double, int>;
const int N = 1e5 + 5;
const int mod = 39989;
const int mod2 = 1e9;
int tot = 0, st[N << 2];
pdd p[N];

void add(double m, double b) {
    p[++tot] = {m, b};
}

double calc(int idx, int x) {
    return p[idx].sec + p[idx].fir * x;
}

void update(int rt, int l, int r, int x, int y, int u) {
    int mid = l + r >> 1;
    if(x > r || y < l) return;
    if(x <= l && r <= y) {
        int v = st[rt];
        if(p[u].fir > p[v].fir) swap(u, v);
        double resu = calc(u, mid), resv = calc(v, mid);
        if(p[u].fir == p[v].fir || l == r) st[rt] = resu > resv ? u : v;
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

pdi query(int rt, int l, int r, int x) {
    if(l == r) return {calc(st[rt], x), st[rt]};
    int mid = l + r >> 1;
    if(x <= mid) return max((pdi){calc(st[rt], x), st[rt]}, query(lc, l, mid, x));
    else return max((pdi){calc(st[rt], x), st[rt]}, query(rc, mid + 1, r, x));
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n; cin>>n;
    int ans = 0;
    for(int i = 1;i<=n;++i) {
        int opt; cin>>opt;
        if(opt) {
            int a, b, c, d;
            cin>>a>>b>>c>>d;
            a = (a + ans - 1 + mod) % mod + 1;
            b = (b + ans - 1 + mod2) % mod2 + 1;
            c = (c + ans - 1 + mod) % mod + 1;
            d = (d + ans - 1 + mod2) % mod2 + 1;
            if(a > c) swap(b, d), swap(a, c);
            if(a == c) {
                double m = 0;
                double B = max(b, d);
                add(m, B);
            } else {
                double m = (double)(b - d) / (a - c);
                double B = b - a * m;
                add(m, B);
            }
            update(1, 1, N - 2, a, c, tot);
        } else {
            int x; cin>>x;
            x = (x + ans - 1 + mod) % mod + 1;
            cout<<(ans = query(1, 1, N - 2, x).sec)<<'\n';
        }
    }
    return 0;
}
