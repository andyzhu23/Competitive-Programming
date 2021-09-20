#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e5 + 10;

struct persistent {
    struct node {
        int l, r;
        ll val;
    } st[N * 100];
    int root[N], tot;
    void push_up(int rt) {
        st[rt].val = st[st[rt].l].val + st[st[rt].r].val;
    }
    void update(int l, int r, int& x, int y, int pos, ll val) {
        x = ++tot;
        st[x] = st[y];
        if(l == r) {
            st[x].val += val;
            return;
        }
        int mid = (l + r) >> 1;
        if(pos <= mid) update(l, mid, st[x].l, st[y].l, pos, val);
        else update(mid + 1, r, st[x].r, st[y].r, pos, val);
        push_up(x);
    }
    ll query(int rt, int l, int r, int x, int y) {
        if(l == x && y == r) return st[rt].val;
        int mid = (l + r) >> 1;
        if(y <= mid) return query(st[rt].l, l, mid, x, y);
        else if(x > mid) return query(st[rt].r, mid + 1, r, x, y);
        else return query(st[rt].l, l, mid, x, mid) + query(st[rt].r, mid + 1, r, mid + 1, y);
    }
} st;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
#endif
    int n, q;
    cin>>n>>q;
    ll ans = 0;
    int cnt = 0;
    while(q--) {
        ll opt, l, r, x;
        cin>>opt>>l>>r;
        l ^= ans;
        r ^= ans;
        if(opt == 1) {
            st.update(1, n, st.root[cnt + 1], st.root[cnt], l, r);
            ++cnt;
        } else {
            cin>>x;
            x ^= ans;
            ans = st.query(st.root[cnt - x], 1, n, l, r);
            cout<<ans<<'\n';
        }
    }
    return 0;
}
