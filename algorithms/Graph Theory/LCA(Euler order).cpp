#include <iostream>
#include <vector>
#define endl "\n"
#define pb emplace_back
#define f first
#define s second
#define mp make_pair
using namespace std;
typedef pair<int, int> PI;
const int N = 1e4 + 10;
PI st[N << 2];
int n, first[N], id[N], dep[N], len;
vector<int> e[N];

inline void dfs(int u, int d, int fa){
    id[++len] = u;
    if(!first[u]) first[u] = len;
    dep[u] = d;
    for(int v : e[u]){
        if(v == fa) continue;
        dfs(v, d + 1, u);
        id[++len] = u;
    }
}

inline void push_up(int rt){
    st[rt] = min(st[rt << 1], st[rt << 1 | 1]);
}

inline void build(int rt, int l, int r){
    if(l == r){
        st[rt].f = dep[id[l]];
        st[rt].s = l;
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    push_up(rt);
}

inline PI query(int rt, int l, int r, int x, int y){
    if(st[rt].f == 0){
        rt ++;
        rt --;
    }
    if(l == x && y == r){
        return st[rt];
    }
    int mid = (l + r) >> 1;
    if(y <= mid) return query(rt << 1, l, mid, x, y);
    else if(x > mid) return query(rt << 1 | 1, mid + 1, r, x, y);
    else return min(query(rt << 1, l, mid, x, mid), query(rt << 1 | 1, mid + 1, r, mid + 1, y));
}

inline void solve(){
    int x, y;
    cin>>x>>y;
    int a = first[x];
    int b = first[y];
    if(a > b) swap(a, b);
    cout<<id[query(1, 1, len, a, b).s]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 1;i<n;i++){
        int a, b;
        cin>>a>>b;
        e[a].pb(b);
        e[b].pb(a);
    }
    dfs(1, 1, 0);
    build(1, 1, len);
    int q; cin>>q;
    while(q--)
        solve();
    return 0;
}
