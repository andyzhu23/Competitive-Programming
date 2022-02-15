#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 2e5 + 5;
int n, w, d, dist[N], s[N], p[N];
vector<int> e[N];

int st[N << 2];
#define lc (rt << 1)
#define rc (rt << 1 | 1)

void build(int rt, int l, int r) {
    if(l == r) {
        st[rt] = dist[l] + s[l];
        return;
    }
    int mid = l + r >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    st[rt] = min(st[lc], st[rc]);
}

void update(int rt, int l, int r, int pos, int val) {
    if(l == r) {
        st[rt] += val;
        return;
    }
    int mid = l + r >> 1;
    if(pos <= mid) update(lc, l, mid, pos, val);
    else update(rc, mid + 1, r, pos, val);
    st[rt] = min(st[lc], st[rc]);
}

int query(int rt, int l, int r, int x, int y) {
    if(l == x && y == r) return st[rt];
    int mid = l + r >> 1;
    if(y <= mid) return query(lc, l, mid, x, y);
    else if(x > mid) return query(rc, mid + 1, r, x, y);
    else return min(query(lc, l, mid, x, mid), query(rc, mid + 1, r, mid + 1, y));
}


int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>w>>d;
    while(w--) {
        int u, v;
        cin>>u>>v;
        e[v].pb(u);
    }
    memset(dist, 0x3f, sizeof(dist));
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : e[u]) if(dist[v] > dist[u] + 1) {
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
    for(int i = 1;i<=n;++i) {
        int x; cin>>x;
        s[x] = i;
        p[i] = x;
    }
    build(1, 1, n);
    for(int i = 1;i<=d;++i) {
        int x, y; cin>>x>>y;
        swap(p[x], p[y]);
        update(1, 1, n, p[x], x - y);
        update(1, 1, n, p[y], y - x);
        cout<<query(1, 1, n, 1, n) - 1<<'\n';
    }
    return 0;
}
