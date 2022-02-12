#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 5e4 + 5;
const int INF = 0x3f3f3f3f;
using ll = long long;
struct edge {
    int u, v;
    ll w;
    bool c;
    bool operator<(const edge& other) const {
        if(w == other.w) return c < other.c;
        return w < other.w;
    }
};
vector<edge> e;
int n, m, k;
ll ans;

int f[N];
void init() {iota(f, f + N, 0);}
int Find(int x) {return x == f[x] ? x : f[x] = Find(f[x]);}
bool merge(int u, int v) {
    int fu = Find(u);
    int fv = Find(v);
    if(fu == fv) return 0;
    f[fu] = fv;
    return 1;
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>m>>k;
    for(int i = 1;i<=m;++i) {
        int u, v;
        ll w;
        bool c;
        cin>>u>>v>>w>>c;
        e.pb({u, v, w, c});
    }

    auto mst = [&](int x) {
        for(auto& u : e) if(u.c == 0) u.w += x; 
        sort(e.begin(), e.end());
        init();
        ll tot = 0;
        ll cnt = 0;
        for(auto x : e) if(merge(x.u, x.v)) {
            tot += x.w;
            cnt += x.c ^ 1;
        }
        for(auto& u : e) if(u.c == 0) u.w -= x; 
        return make_pair(tot, cnt);
    };

    int l = -105, r = 105;
    while(l <= r) {
        int mid = l + r >> 1;
        pair<ll, ll> cnt = mst(mid);
        if(cnt.second < k) r = mid - 1;
        else l = mid + 1, ans = cnt.first - mid * k;
    }
    cout<<ans<<'\n';
    return 0;
}
