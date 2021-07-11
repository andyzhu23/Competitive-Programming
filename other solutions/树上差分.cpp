#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define lc rt << 1
#define rc rt << 1 | 1
#define mp make_pair
#define pb push_back
using ll = long long;
template <typename T> using vec = vector<T>;
using vi = vec<int>;
using vll = vec<ll>;

const int N = 1e6 + 10;
const int INF = 0x3f3f3f3f;

template <typename T> struct segtree {
    T st[N << 2] = {0};

    void build(int rt, int l, int r) {
        if(l == r) {
            cin>>st[rt];
            return;
        }
        int mid = (l + r) >> 1;
        build(lc, l, mid);
        build(rc, mid + 1, r);
        st[rt] = st[lc] + st[rc];
    }

    void update(int rt, int l, int r, int pos, T val) {
        if(l == r) {
            st[rt] += val;
            return;
        }
        int mid = (l + r) >> 1;
        if(pos <= mid) update(lc, l, mid, pos, val);
        else if(pos > mid) update(rc, mid + 1, r, pos, val);
        else update(lc, l, mid, pos, val), update(rc, mid + 1, r, pos, val);
        st[rt] = st[lc] + st[rc];
    }

    T query(int rt, int l, int r, int x, int y) {
        if(l == x && y == r) return st[rt];
        int mid = (l + r) >> 1;
        if(y <= mid) return query(lc, l, mid, x, y);
        else if(x > mid) return query(rc, mid + 1, r, x, y);
        else return query(lc, l, mid, x, mid) + query(rc, mid + 1, r, mid + 1, y);
    }
};


int n, m, r, f[N][22], tot = 0;
vll dep(N);
vi e[N], id(N), rnk(N), sz(N), a(N);

// get dep, and dfs order
void dfs(int u, int fa) {

    id[++tot] = u;
    rnk[u] = tot;
    dep[u] = dep[fa] + 1;
    sz[u] = 1;

    f[u][0] = fa;
    for (int i = 1;i<=21;i++) f[u][i] = f[f[u][i - 1]][i - 1];

    for (int v : e[u]) {
        if(v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int LCA(int x, int y) {
    if(dep[x] < dep[y]) swap(x, y);
    for(int i = 21;i>=0;i--) {
        if(dep[f[x][i]] >= dep[y]) x = f[x][i];
        if(x == y) return x;
    }
    for(int i = 21;i>=0;i--) {
        if(f[x][i] != f[y][i]) {
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}

segtree<ll> v, sum, fdep;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>r;
    for(int i = 1;i<=n;i++) cin>>a[i];
    for(int i = 1;i<n;i++) {
        int a, b;
        cin>>a>>b;
        e[a].pb(b);
        e[b].pb(a);
    }
    dfs(r, 0);
    for(int i = 1;i<=n;i++) {
        v.update(1, 1, n, rnk[i], a[i]);
    }
    while(m--) {
        int opt, a, b, x;
        cin>>opt>>a;
        if(opt == 1) {
            cin>>b>>x;
            int lca = LCA(a, b);
            sum.update(1, 1, n, rnk[a], x);
            sum.update(1, 1, n, rnk[b], x);
            sum.update(1, 1, n, rnk[lca], -x);
            sum.update(1, 1, n, rnk[f[lca][0]], -x);
            
            fdep.update(1, 1, n, rnk[a], x * dep[a]);
            fdep.update(1, 1, n, rnk[b], x * dep[b]);
            fdep.update(1, 1, n, rnk[lca], -x * dep[lca]);
            fdep.update(1, 1, n, rnk[f[lca][0]], -x * dep[f[lca][0]]);

        } else if(opt == 2) {
            cout<<sum.query(1, 1, n, rnk[a], rnk[a] + sz[a] - 1) + v.query(1, 1, n, rnk[a], rnk[a])<<"\n";
        }
        else {
            cout<<v.query(1, 1, n, rnk[a], rnk[a] + sz[a] - 1)
             + fdep.query(1, 1, n, rnk[a], rnk[a] + sz[a] - 1) - 
             (dep[a] - 1) * sum.query(1, 1, n, rnk[a], rnk[a] + sz[a] - 1)<<"\n";
        }
    }
    return 0;
}
