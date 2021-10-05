#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, q;

const int N = 1e6 + 10;
const ll INF = 0x3f3f3f3f3f3f3f3f;

struct segtree {
    struct node {
        ll a, b;
        bool operator<(const node& other) const {
            return a + b < other.a + other.b;
        }
        bool operator>(const node& other) const {
            return a + b > other.a + other.b;
        }
    } st[N << 2];
    ll lazy1[N << 2], lazy2[N << 2], MaxA[N << 2], MaxB[N << 2];

#define lc (rt << 1)
#define rc (rt << 1 | 1)

    void push_up(int rt) {
        st[rt] = max(st[lc], st[rc]);
        MaxA[rt] = max(MaxA[lc], MaxA[rc]);
        MaxB[rt] = max(MaxB[lc], MaxB[rc]);
    }

    void chk(ll& a, ll b) {
        a = a == INF ? b : max(a, b);
    }

    void push_down(int rt, int l, int r, int mid) {
        if(lazy1[rt] != INF) {
            lazy1[lc] = lazy1[rc] = lazy1[rt];
            MaxA[lc] = MaxA[rc] = lazy1[rt];
            st[lc] = {lazy1[rt], MaxB[lc]};
            st[rc] = {lazy1[rt], MaxB[rc]};
        }
        if(lazy2[rt] != INF) {
            MaxB[lc] = max(MaxB[lc], lazy2[rt]);
            MaxB[rc] = max(MaxB[rc], lazy2[rt]);
            chk(lazy2[lc], lazy2[rt]);
            chk(lazy2[rc], lazy2[rt]);
            st[lc] = max(st[lc], {MaxA[lc], lazy2[rt]});
            st[rc] = max(st[rc], {MaxA[rc], lazy2[rt]});
        }
        lazy1[rt] = lazy2[rt] = INF;
    }

    void build1(int rt, int l, int r) {
        if(l == r) {
            cin>>st[rt].a;
            MaxA[rt] = st[rt].a;
            return;
        }
        int mid = (l + r) >> 1;
        build1(lc, l, mid);
        build1(rc, mid + 1, r);
        push_up(rt);
    }

    void build2(int rt, int l, int r) {
        if(l == r) {
            cin>>st[rt].b;
            MaxB[rt] = st[rt].b;
            return;
        }
        int mid = (l + r) >> 1;
        build2(lc, l, mid);
        build2(rc, mid + 1, r);
        push_up(rt);
    }

    void update1(int rt, int l, int r, int x, int y, ll k) {
        if(l == x && y == r) {
            lazy1[rt] = MaxA[rt] = k;
            st[rt] = {k, MaxB[rt]};
            return;
        }
        int mid = (l + r) >> 1;
        push_down(rt, l, r, mid);
        if(y <= mid) update1(lc, l, mid, x, y, k);
        else if(x > mid) update1(rc, mid + 1, r, x, y, k);
        else update1(lc, l, mid, x, mid, k), update1(rc, mid + 1, r, mid + 1, y, k);
        push_up(rt);
    }

    void update2(int rt, int l, int r, int x, int y, ll k) {
        if(l == x && y == r) {
            st[rt] = max(st[rt], {MaxA[rt], k});
            MaxB[rt] = max(MaxB[rt], k);
            chk(lazy2[rt], k);
            return;
        }
        int mid = (l + r) >> 1;
        push_down(rt, l, r, mid);
        if(y <= mid) update2(lc, l, mid, x, y, k);
        else if(x > mid) update2(rc, mid + 1, r, x, y, k);
        else update2(lc, l, mid, x, mid, k), update2(rc, mid + 1, r, mid + 1, y, k);
        push_up(rt);
    }

    ll query(int rt, int l, int r, int x, int y) {
        if(l == x && y == r) return st[rt].a + st[rt].b;
        int mid = (l + r) >> 1;
        push_down(rt, l, r, mid);
        if(y <= mid) return query(lc, l, mid, x, y);
        else if(x > mid) return query(rc, mid + 1, r, x, y);
        else return max(query(lc, l, mid, x, mid), query(rc, mid + 1, r, mid + 1, y));
    }
} st;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
#endif
    memset(st.lazy1, 0x3f, sizeof(st.lazy1));
    memset(st.lazy2, 0x3f, sizeof(st.lazy2));
    cin>>n>>q;
    st.build1(1, 1, n);
    st.build2(1, 1, n);
    while(q--) {
        int opt, l, r, k;
        cin>>opt;
        switch (opt) {
        case 1:
            cin>>l>>r>>k;
            st.update1(1, 1, n, l, r, k);
            break;
        case 2:
            cin>>l>>r>>k;
            st.update2(1, 1, n, l, r, k);
            break;
        case 3:
            cin>>l>>r;
            cout<<st.query(1, 1, n, l, r)<<'\n';
            break;
        }
    }
    return 0;
}
