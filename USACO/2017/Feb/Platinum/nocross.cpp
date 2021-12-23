#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
#define pb push_back

int a[N], b[N], n, c[N];

template <typename T> void ckmax(T& a, T b) {a = max(a, b);}

struct segtree {
    int st[N << 2];
#define lc (rt << 1)
#define rc (rt << 1 | 1)
    void update(int pos, int val, int rt = 1, int l = 0, int r = n) {
        if(l == r) {
            ckmax(st[rt], val);
            return;
        }
        int mid = l + r >> 1;
        if(pos <= mid) update(pos, val, lc, l, mid);
        else update(pos, val, rc, mid + 1, r);
        st[rt] = max(st[lc], st[rc]);
    }
    int query(int x, int y, int rt = 1, int l = 0, int r = n) {
        if(l == x && y == r) return st[rt];
        int mid = l + r >> 1;
        if(y <= mid) return query(x, y, lc, l, mid);
        else if(x > mid) return query(x, y, rc, mid + 1, r);
        else return max(query(x, mid, lc, l, mid), query(mid + 1, y, rc, mid + 1, r));
    }
} dp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("nocross.in", "r", stdin);
    freopen("nocross.out", "w", stdout);
    cin>>n;
    for(int i = 1;i<=n;++i) cin>>a[i];
    for(int i = 1;i<=n;++i) cin>>b[i], c[b[i]] = i;
    for(int i = 1;i<=n;++i) {
        vector<int> nodes;
        for(int j = -4;j<=4;++j) 
            if(a[i] + j > 0 && a[i] + j <= n)
                nodes.pb(c[a[i] + j]);
        sort(nodes.begin(), nodes.end(), greater<int>());
        for(int d : nodes) dp.update(d, dp.query(0, d - 1) + 1);
    }
    cout<<dp.query(1, n)<<'\n';
    return 0;
}
