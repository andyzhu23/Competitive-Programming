#include <bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;
const int N = 1e5 + 5;
struct cow {
    int id; 
    ll x, y;
    bool operator<(const cow& other) const {
        return x < other.x;
    }
};

struct edge {
    int u, v;
    ll w;
    bool operator<(const edge& other) const {
        return w < other.w;
    }
};
vector<edge> e;
vector<cow> cows;
int X[N], Y[N], last[15];
int n;

int f[N];

int Find(int x) {return f[x] == x ? x : f[x] = Find(f[x]);}
bool merge(int u, int v) {
    int fu = Find(u);
    int fv = Find(v);
    if(fu == fv) return 0;
    f[fu] = fv;
    return 1;
}

signed main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    for(int i = 1;i<=n;++i) {
        int x, y;
        cin>>x>>y;
        X[i] = x;
        Y[i] = y;
        cows.push_back({i, x, y});
    }
    sort(cows.begin(), cows.end());
    for(int i = 1;i<=n;++i) {
        auto[id, x, y] = cows[i - 1];
        for(int j = 0;j<=10;++j) if(last[j]) {
            ll u = X[last[j]] - x;
            ll v = Y[last[j]] - y;
            e.push_back({id, last[j], u * u + v * v});
        }
        last[y] = id;
    }
    memset(last, 0, sizeof(last));
    for(int i = n;i;--i) {
        auto[id, x, y] = cows[i - 1];
        for(int j = 0;j<=10;++j) if(last[j]) {
            ll u = X[last[j]] - x;
            ll v = Y[last[j]] - y;
            e.push_back({id, last[j], u * u + v * v});
        }
        last[y] = id;
    }
    sort(e.begin(), e.end());
    iota(f, f + n + 1, 0);
    ll ans = 0;
    for(auto[u, v, w] : e) {
        if(merge(u, v)) {
            ans += w;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
