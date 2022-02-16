#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v, w;
};
vector<edge> e;
int n, k;
const int N = 1e5 + 5;
int f[N], sz[N];

int Find(int x) {return f[x] == x ? x : f[x] = Find(f[x]);}
void merge(int u, int v) {
    int fu = Find(u);
    int fv = Find(v);
    f[fu] = fv;
    sz[fv] += sz[fu];
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>k;
    iota(f, f + n + 1, 0);
    long long ans = 0;
    for(int i = 1;i<n;++i) {
        int u, v, w;
        cin>>u>>v>>w;
        e.push_back({u, v, w});
        ans += w;
    }
    for(int i = 1;i<=k;++i) {
        int x; cin>>x;
        sz[x] = 1;
    }
    sort(e.begin(), e.end(), [&](edge& a, edge& b) {
        return a.w > b.w;
    });
    for(auto[u, v, w] : e) if(!(sz[Find(u)] && sz[Find(v)])) {
        merge(u, v);
        ans -= w;
    } 
    cout<<ans<<'\n';
    return 0;
}
