#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
int n, a[N];

struct node {
    int act;
    ll val;
    node operator+(const node& other) const {
        node ans;
        ans.act = act + other.act;
        ans.val = val + other.val;
        return ans;
    }
};

struct segtree {
    node st[N << 2];
    int lazy[N << 2];
#define lc (rt << 1)
#define rc (rt << 1 | 1)
    void push_down(int rt, int l, int r, int mid) {
        st[lc].val += st[lc].act * lazy[rt];
        st[rc].val += st[rc].act * lazy[rt];
        lazy[lc] += lazy[rt];
        lazy[rc] += lazy[rt];
        lazy[rt] = 0;
    }
    void updateAct(int pos, int val, int rt = 1, int l = 1, int r = n) {
        if(l == r) {
            st[rt].act = val;
            st[rt].val = 0;
            return;
        }
        int mid = l + r >> 1;
        push_down(rt, l, r, mid);
        if(pos <= mid) updateAct(pos, val, lc, l, mid);
        else updateAct(pos, val, rc, mid + 1, r);
        st[rt] = st[lc] + st[rc];
    }
    void update(int x, int y, int val, int rt = 1, int l = 1, int r = n) {
        if(x == l && y == r) {
            st[rt].val += st[rt].act * val;
            lazy[rt] += val;
            return;
        }
        int mid = l + r >> 1;
        push_down(rt, l, r, mid);
        if(y <= mid) update(x, y, val, lc, l, mid);
        else if(x > mid) update(x, y, val, rc, mid + 1, r);
        else update(x, mid, val, lc, l, mid), update(mid + 1, y, val, rc, mid + 1, r);
        st[rt] = st[lc] + st[rc];
    }
    node query(int x, int y, int rt = 1, int l = 1, int r = n) {
        if(x == l && y == r) return st[rt];
        int mid = l + r >> 1;
        push_down(rt, l, r, mid);
        if(y <= mid) return query(x, y, lc, l, mid);
        else if(x > mid) return query(x, y, rc, mid + 1, r);
        else return query(x, mid, lc, l, mid) + query(mid + 1, y, rc, mid + 1, r);
    }
} st;

int last[N], pos[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    for(int i = 1;i<=n;++i) {
        cin>>a[i];
        last[i] = pos[a[i]]; 
        pos[a[i]] = i;
    }
    ll ans = 0;
    for(int i = 1;i<=n;++i) {
        if(last[i]) st.updateAct(last[i], 0);
        st.updateAct(i, 1);
        if(last[last[i]] < last[i] - 1) st.update(last[last[i]] + 1, last[i] - 1, -1);
        if(last[i - 1] + 1 < i - 1) st.update(last[i - 1] + 1, i - 2, 1);
        if(last[i] + 1 <= i - 1) ans += st.query(last[i] + 1, i - 1).val;
    }
    cout<<ans<<'\n';
    return 0;
}
