#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int K = 2e5 + 5;

struct fenwick {
    int c[K];
    inline void update(int a, int b) {
        for(int i = a;i<K;i+=i&(-i)) c[i] += b;
    }
    inline int query(int a) {
        int ans = 0;
        for(int i = a;i;i-=i&(-i)) ans += c[i];
        return ans;
    }
    inline int query(int a, int b) {
        return query(b) - query(a - 1);
    }
} fen;

struct node {
    int a, b, c, id, cnt, ans;
    inline bool operator!=(const node& o) const {
        return a != o.a || b != o.b || c != o.c || cnt != o.cnt;
    }
} a[N], b[N];

int n, m, k, ans[K];

inline void solve(int l = 1, int r = m) {
    if(r <= l) return;
    int mid = l + r >> 1;
    solve(l, mid);
    solve(mid + 1, r);
    sort(a + l, a + mid + 1, [](node& u, node& v) {
        if(u.b != v.b) return u.b < v.b;
        return u.c < v.c;
    });
    sort(a + mid + 1, a + r + 1, [](node& u, node& v) {
        if(u.b != v.b) return u.b < v.b;
        return u.c < v.c;
    });
    int j = l;
    for(int i = mid + 1;i<=r;++i) {
        while(j <= mid && a[j].b <= a[i].b) {
            fen.update(a[j].c, a[j].cnt);
            ++j;
        }
        a[i].ans += fen.query(a[i].c);
    }
    for(int i = l;i<j;++i) fen.update(a[i].c, -a[i].cnt);
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>k;
    for(int i = 1;i<=n;++i) {
        cin>>b[i].a>>b[i].b>>b[i].c;
        b[i].id = i;
    }
    sort(b + 1, b + n + 1, [](node& u, node& v) {
        if(u.a != v.a) return u.a < v.a;
        if(u.b != v.b) return u.b < v.b;
        return u.c < v.c;
    });
    int tmp = 0;
    for(int i = 1;i<=n;++i) {
        ++tmp;
        if(b[i] != b[i + 1]) {
            a[++m] = b[i];
            a[m].cnt = tmp;
            tmp = 0;
        }
    }
    solve();
    for(int i = 1;i<=m;++i) {
        ans[a[i].ans + a[i].cnt - 1] += a[i].cnt;
    }
    for(int i = 0;i<n;++i) cout<<ans[i]<<'\n';
    return 0;
}
