#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fir first
#define sec second
using pii = pair<int, int>;
using ll = long long;
const int N = 1e5 + 5;
const int inf = 0x3f3f3f3f;

struct segtree {
    ll mn[N << 2], lazy[N << 2];
#define lc (rt << 1)
#define rc (rt << 1 | 1)
    void push_down(int rt) {
        lazy[lc] += lazy[rt];
        lazy[rc] += lazy[rt];
        mn[lc] += lazy[rt];
        mn[rc] += lazy[rt];
        lazy[rt] = 0;
    }
    void update(int rt, int l, int r, int x, int y, int val) {
        if(l == x && y == r) {
            mn[rt] += val;
            lazy[rt] += val;
            return;
        }
        int mid = l + r >> 1;
        push_down(rt);
        if(y <= mid) update(lc, l, mid, x, y, val);
        else if(x > mid) update(rc, mid + 1, r, x, y, val);
        else update(lc, l, mid, x, mid, val), update(rc, mid + 1, r, mid + 1, y, val);
        mn[rt] = min(mn[lc], mn[rc]);
    }
    void update(int rt, int l, int r, int pos, int val) {
        if(l == r) {
            mn[rt] = val;
            return;
        }
        int mid = l + r >> 1;
        push_down(rt);
        if(pos <= mid) update(lc, l, mid, pos, val);
        else update(rc, mid + 1, r, pos, val);
        mn[rt] = min(mn[lc], mn[rc]);
    }
    int query(int rt, int l, int r) {
        if(l == r) return l;
        int mid = l + r >> 1;
        push_down(rt);
        if(mn[lc] == 0) return query(lc, l, mid);
        else return query(rc, mid + 1, r);
    }
} st;

struct fenwick {
    int c[N];
    void update(int a, int b) {
        for(int i = a;i<N;i+=i&(-i)) c[i] += b;
    }
    int query(int a) {
        int ans = 0;
        for(int i = a;i;i-=i&(-i)) ans += c[i];
        return ans;
    }
    int query(int a, int b) {
        return query(b) - query(a - 1);
    }
} fen;

int n, k, a[N];
pii b[N];
unordered_map<int, int> mp;

pii interval(int x) {
    int l = 0, r = n + 1;
    int lo = 1, hi = n;
    while(lo <= hi) {
        int mid = lo + hi >> 1;
        if(b[mid].fir < x - k) lo = mid + 1, l = mid;
        else hi = mid - 1;
    }
    lo = 1, hi = n;
    while(lo <= hi) {
        int mid = lo + hi >> 1;
        if(b[mid].fir > x + k) hi = mid - 1, r = mid;
        else lo = mid + 1;
    }
    return {l, r};
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>k;
    for(int i = 1;i<=n;++i) {
        cin>>a[i];
        b[i] = {a[i], i};
    }
    sort(b + 1, b + n + 1);
    for(int i = 1;i<=n;++i) if(!mp[b[i].fir]) mp[b[i].fir] = i;
    for(int i = 1;i<=n;++i) {
        int cnt = 0;
        auto[l, r] = interval(a[i]);
        if(l > 0) cnt += fen.query(1, l);
        if(r <= n) cnt += fen.query(r, n);
        fen.update(mp[a[i]], 1);
        st.update(1, 1, n, mp[a[i]], cnt);
        ++mp[a[i]];
    }
    for(int i = 1;i<=n;++i) {
        int x = st.query(1, 1, n);
        cout<<b[x].fir<<'\n';
        auto[l, r] = interval(b[x].fir);
        if(l > 0) st.update(1, 1, n, 1, l, -1);
        if(r <= n) st.update(1, 1, n, r, n, -1);
        st.update(1, 1, n, x, inf);
    }
    return 0;
}
