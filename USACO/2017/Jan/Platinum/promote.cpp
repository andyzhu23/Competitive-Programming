#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 1e5 + 10;
using ll = long long;
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
        if(l == r) return 0;
        int mid = (l + r) >> 1;
        if(k <= mid) return query(l, mid, st[x].l, st[y].l, k) + (st[st[y].r].ans - st[st[x].r].ans);
        else return query(mid + 1, r, st[x].r, st[y].r, k);
    }

} st;

int n, len, order[N], son[N], pos[N];
ll p[N];
vector<int> e[N];

void dfs(int u, int fa) {
    order[len--] = u;
    pos[u] = len;
    for(int v : e[u]) {
        if(v == fa) continue;
        dfs(v, u);
        son[u] += son[v] + 1;
    }
}
#define ins insert
set<ll> vis;
unordered_map<ll, int> Map;

int main() {
   freopen("promote.in", "r", stdin);
   freopen("promote.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 1;i<=n;i++) {
        cin>>p[i];
        vis.ins(p[i]);
    }
    int cnt = 0;
    for(auto& x : vis) {
        Map[x] = ++cnt;
    }
    for(int i = 2;i<=n;i++) {
        int x; cin>>x;
        e[i].pb(x);
        e[x].pb(i);
    }
    len = n;
    st.build(st.root[0], 1, n);
    dfs(1, 0);
    for(int i = 1;i<=n;i++)
        st.update(1, n, st.root[i], st.root[i - 1], Map[p[order[i]]]);
    for(int i = 1;i<=n;i++) {
        int l = pos[i] - son[i];
        int r = pos[i];
        cout<<st.query(1, n, st.root[l], st.root[r], Map[p[i]])<<'\n';
    }

    return 0;
}
