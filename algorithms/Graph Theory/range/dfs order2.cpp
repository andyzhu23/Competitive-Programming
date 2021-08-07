#include <iostream>
#include <vector>
#define pb emplace_back
#define endl "\n"
using namespace std;
using ll = long long;
const int N = 1e6 + 10;
ll st[N << 2], lazy[N << 2];
int n, m, root, id[N], rnk[N], sz[N], len, v[N];
vector<int> e[N];

inline void dfs(int u, int fa){
    id[++len] = u;
    rnk[u] = len;
    sz[u] = 1;
    for(int v : e[u]){
        if(v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

inline void push_up(int rt){
    st[rt] = st[rt << 1] + st[rt << 1 | 1];
}

inline void push_down(int rt, int l, int r, int mid){
    st[rt << 1] += (mid - l + 1) * lazy[rt];
    st[rt << 1 | 1] += (r - mid) * lazy[rt];
    lazy[rt << 1] += lazy[rt];
    lazy[rt << 1 | 1] += lazy[rt];
    lazy[rt] = 0;
}

inline void build(int rt, int l, int r){
    if(l == r){
        st[rt] = v[id[l]];
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    push_up(rt);
}

inline void update(int rt, int l, int r, int x, int y, int val){
    if(l == x && y == r){
        st[rt] += (r - l + 1) * val;
        lazy[rt] += val;
        return;
    }
    int mid = (l + r) >> 1;
    push_down(rt, l, r, mid);
    if(y <= mid) update(rt << 1, l, mid, x, y, val);
    else if(x > mid) update(rt << 1 | 1, mid + 1, r, x, y, val);
    else update(rt << 1, l, mid, x, mid, val), update(rt << 1 | 1, mid + 1, r, mid + 1, y, val);
    push_up(rt);
}

inline ll query(int rt, int l, int r, int x, int y){
    if(l == x && y == r)
        return st[rt];
    int mid = (l + r) >> 1;
    push_down(rt, l, r, mid);
    if(y <= mid) return query(rt << 1, l, mid, x, y);
    else if(x > mid) return query(rt << 1 | 1, mid + 1, r, x, y);
    else return query(rt << 1, l, mid, x, mid) + query(rt << 1 | 1, mid + 1, r, mid + 1, y);
}

inline void solve(){
    int opt, a, x;
    cin>>opt>>a;
    if(opt == 1){
        cin>>x;
        update(1, 1, n, rnk[a], rnk[a] + sz[a] - 1, x);
    } else
        cout<<query(1, 1, n, rnk[a], rnk[a] + sz[a] - 1)<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>root;
    for(int i = 1;i<=n;i++) cin>>v[i];
    for(int i = 1;i<n;i++){
        int a, b; cin>>a>>b;
        e[a].pb(b);
        e[b].pb(a);
    }
    dfs(root, 0);
    build(1, 1, n);
    while(m--)
        solve();
    return 0;
}
