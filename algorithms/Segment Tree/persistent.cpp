#include <bits/stdc++.h>
using namespace std;

int n, q;
const int N = 1e5 + 10;

struct persistent {
    struct node {
        int l, r, sum;
    } st[N * 40];
    int tot, root[N];

    void push_up(int rt) {
        st[rt].sum = max(st[st[rt].l].sum, st[st[rt].r].sum);
    }
    
    void update(int l, int r, int last, int& rt, int pos, int val) {
        rt = ++tot;
        st[rt] = st[last];
        if(l == r) {
            st[rt].sum = val;
            return;
        }
        int mid = (l + r) >> 1;
        if(pos <= mid) update(l, mid, st[last].l, st[rt].l, pos, val);
        else update(mid + 1, r, st[last].r, st[rt].r, pos, val);
        push_up(rt);
    }

    void build(int& rt, int l, int r) {
        rt = ++tot;
        if(l == r) {
            cin>>st[rt].sum;
            return;
        }
        int mid = (l + r) >> 1;
        build(st[rt].l, l, mid);
        build(st[rt].r, mid + 1, r);
        push_up(rt);
    }

    int query(int l, int r, int& rt, int x, int y) {
        if(x == l && y == r) return st[rt].sum;
        int mid = (l + r) >> 1;
        if(y <= mid) return query(l, mid, st[rt].l, x, y);
        if(x > mid) return query(mid + 1, r, st[rt].r, x, y);
        else return max(query(l, mid, st[rt].l, x, mid), query(mid + 1, r, st[rt].r, mid + 1, y));
    }
} st;

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    cin>>n>>q;
    st.build(st.root[1], 1, n);
    int cnt = 1;
    while(q--) {
        int opt, a, b, c;
        cin>>opt>>a>>b>>c;
        if(opt) st.update(1, n, st.root[a], st.root[++cnt], b, c);
        else cout<<st.query(1, n, st.root[a], b, c)<<'\n';
    }

    return 0;
}
