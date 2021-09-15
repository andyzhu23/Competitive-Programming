#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
struct node {
    int l, r, val;
}; 
struct seg {
    node st[N * 40];
    int tot, root[N];
    void pushup(int rt) {
        st[rt].val = st[st[rt].l].val + st[st[rt].r].val;
    }
    void update(int l, int r, int& x, int y, int pos, int val) {
        x = ++tot;
        st[x] = st[y];
        if(l == r) {
            st[x].val = val;
            return;
        }
        int mid = (l + r) >> 1;
        if(pos <= mid) update(l, mid, st[x].l, st[y].l, pos, val);
        else update(mid + 1, r, st[x].r, st[y].r, pos, val);
        pushup(x);
    }

    int query(int l, int r, int x, int pos) {
        if(l == r) return st[x].val;
        int mid = (l + r) >> 1;
        if(pos <= mid) return query(l, mid, st[x].l, pos);
        else return query(mid + 1, r, st[x].r, pos);
    }

    void build(int& rt, int l, int r) {
        rt = ++tot;
        if(l == r) {
            st[rt].val = l;
            return;
        }
        int mid = (l + r) >> 1;
        build(st[rt].l, l, mid);
        build(st[rt].r, mid + 1, r);
        pushup(rt);
    }

};

struct DSU {
    seg f;
    int n;
    int cnt = 0;
    void init(int len) {
        n = len;
        f.build(f.root[0], 1, n);
    }
    int Find(int x, int y) {
        int cur = f.query(1, n, f.root[y], x);
        return cur == x ? x : Find(cur, y);
    }
    void merge(int u, int v) {
        int fu = Find(u, cnt);
        int fv = Find(v, cnt);
        f.update(1, n, f.root[cnt + 1], f.root[cnt], fu, fv);
        ++cnt;
        return;
    }
    int query(int a, int b) {
        int fu = Find(a, cnt);
        int fv = Find(b, cnt);
        f.update(1, n, f.root[cnt + 1], f.root[cnt], fu, fu);
        ++cnt;
        return (fu == fv) ? 1 : 0;
    }
} dsu;

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    int n, m;
    cin>>n>>m;
    dsu.init(n);
    while(m--) {
        int opt, a, b;
        cin>>opt>>a;
        if(opt == 2) {
            dsu.f.update(1, n, dsu.f.root[dsu.cnt + 1], dsu.f.root[a], 1, dsu.f.query(1, n, dsu.f.root[a], 1));
            ++dsu.cnt;
            continue;
        } 
        cin>>b;
        if(opt == 1) {
            dsu.merge(a, b);
        } else {
            cout<<dsu.query(a, b)<<'\n';
        }
    }
    return 0;
}
