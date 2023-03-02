#include <bits/stdc++.h>
using namespace std;
#define ins insert
#define pb push_back
using ll = long long;
const int N = 1e5 + 5;
int n, m;
vector<int> e[N];
set<int> bst[N];
ll ans = 0;

int f[N];
int Find(int x) {return f[x] == x ? x : f[x] = Find(f[x]);}
void merge(int u, int v) {
    int fu = Find(u);
    int fv = Find(v);
    if(fu == fv) return;
    f[fu] = fv;
    if(bst[fu].size() > bst[fv].size()) swap(bst[fu], bst[fv]);
    for(int x : bst[fu]) bst[fv].ins(x);
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>m;
    iota(f + 1, f + n + 1, 1);
    for(int i = 1;i<=m;++i) {
        int u, v;
        cin>>u>>v;
        e[u].pb(v);
        e[v].pb(u);
    }
    for(int i = 1;i<=n;++i) {
        for(int v : e[i]) {
            if(v < i) merge(v, i);
            else bst[i].ins(v);
        }
        while(!bst[Find(i)].empty() && *bst[Find(i)].begin() <= i) {
            bst[Find(i)].erase(bst[Find(i)].begin());
        }
        ans += n - i - bst[Find(i)].size();
    }
    cout<<1ll * n * (n - 1) / 2 - ans<<'\n';
    return 0;
}
