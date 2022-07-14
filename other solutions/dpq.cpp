#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;
int n, h[N], a[N];
vector<int> stk;

set<int> dis;
unordered_map<int, int> mp;

struct segtree {
#define lc (rt << 1)
#define rc (rt << 1 | 1)
    ll st[N << 2];
    void update(int rt, int l, int r, int pos, ll val) {
        if(l == r) {
            st[rt] = val;
            return;
        }
        int mid = l + r >> 1;
        if(pos <= mid) update(lc, l, mid, pos, val);
        else update(rc, mid + 1, r, pos, val);
        st[rt] = max(st[lc], st[rc]);
    }
    ll query(int rt, int l, int r, int x, int y) {
        if(l == x && y == r) return st[rt];
        int mid = l + r >> 1;
        if(y <= mid) return query(lc, l, mid, x, y);
        else if(x > mid) return query(rc, mid + 1, r, x, y);
        else return max(query(lc, l, mid, x, mid), query(rc, mid + 1, r, mid + 1, y));
    }
} st;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    for(int i = 1;i<=n;++i) {
        cin>>h[i];
        dis.insert(h[i]);
    }
    int len = 0;
    for(auto x : dis) mp[x] = ++len;
    for(int i = 1;i<=n;++i) {
        cin>>a[i];
        h[i] = mp[h[i]];
        st.update(1, 1, n, h[i], st.query(1, 1, n, 1, h[i]) + a[i]);
    }
    cout<<st.query(1, 1, n, 1, n)<<'\n';
    return 0;
}
