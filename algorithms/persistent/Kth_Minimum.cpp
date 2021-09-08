#include <bits/stdc++.h>
using namespace std;

int n, m;

const int N = 1e5 + 10;

struct seg {
    struct node{
        int l, r, ans;
    } st[N * 40];
    int root[N], cnt;

    void update(int l, int r, int& x, int y, int pos) {
        x = ++cnt;
        st[x] = st[y];
        st[x].ans ++;
        if(l == r) return;
        int mid = (l + r) >> 1;
        if(pos <= mid) update(l, mid, st[x].l, st[y].l, pos);
        else update(mid + 1, r, st[x].r, st[y].r, pos);
    }

    void build(int& rt, int l, int r) {
        rt = ++cnt;
        if(l == r) return;
        int mid = (l + r) >> 1;
        build(st[rt].l, l, mid);
        build(st[rt].r, mid + 1, r);
    }

    int query(int l, int r, int x, int y, int k) {
        if(l == r) return l;
        int mid = (l + r) >> 1;
        int sum = st[st[y].l].ans - st[st[x].l].ans;
        if(sum >= k) return query(l, mid, st[x].l, st[y].l, k);
        else return query(mid + 1, r, st[x].r, st[y].r, k - sum);
    }

} st;

set<int> a;
int b[N], c[N], o[N];
map<int, int> Map;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 1;i<=n;i++) {
        cin>>b[i];
        a.insert(b[i]);
    }
    int cnt = 0;
    for(auto i = a.begin(); i != a.end(); ++i) {
        Map[*i] = ++cnt;
        o[cnt] = *i;
    }
    for(int i = 1;i<=n;i++) {
        c[i] = Map[b[i]];
    }
    st.build(st.root[0], 1, n);
    for(int i = 1;i<=n;++i) 
        st.update(1, n, st.root[i], st.root[i - 1], c[i]);
    int ans = 0;
    while(m--) {
        int l, r, k;
        cin>>l>>r>>k;
        l ^= ans;
        r ^= ans;
        k ^= ans;
        ans = o[st.query(1, n, st.root[l - 1], st.root[r], k)];
        cout<<ans<<'\n';
    }
    return 0;
}
