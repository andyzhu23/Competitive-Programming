#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 2e5 + 5;
using ll = long long;
int n, m;
vector<int> e[N];
set<int> bst[N];

int f[N];
int Find(int x) {return f[x] == x ? x : f[x] = Find(f[x]);}
bool merge(int u, int v) {
    int fu = Find(u);
    int fv = Find(v);
    if(fu == fv) return 0;
    if(bst[fu].size() > bst[fv].size()) swap(fu, fv);
    f[fu] = fv;
    for(auto x : bst[fu]) if(x > u) bst[fv].insert(x);
    return 1;
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>m;
    for(int i = 1;i<=m;++i) {
        int u, v;
        cin>>u>>v;
        e[u].pb(v);
        e[v].pb(u);
    }
    iota(f, f + n + 1, 0);
    ll ans = 0;
    for(int i = 1;i<=n;++i) {
        for(auto v : e[i]) {
            if(v < i) merge(i, v);
            else bst[Find(i)].insert(v);
        }
        while(!bst[Find(i)].empty() && *bst[Find(i)].begin() <= i) 
            bst[Find(i)].erase(bst[Find(i)].begin());
        ans += n - i - bst[Find(i)].size();
    }
    cout<<1ll * n * (n - 1) / 2 - m - ans<<'\n';
    return 0;
}
