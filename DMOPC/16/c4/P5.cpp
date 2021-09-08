#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
#define pb push_back
#define all(v) v.begin(), v.end()
#define mp make_pair
#define fir first
#define sec second

const int INF = 0x3f3f3f3f;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w > other.w;
    }
};

struct DSU {
    vi f;
    int n;
    DSU(int n) :n(n) {
        f = vi(n + 1);
        for(int i = 1;i<=n;i++) f[i] = i;
    }
    int Find(int x) {return f[x] == x ? x : f[x] = Find(f[x]);}
    bool merge(int u, int v) {
        int fu = Find(u);
        int fv = Find(v);
        if(fu == fv) return 0;
        f[fu] = fv;
        return 1;
    }
};
const int N = 2e5 + 10;

vector<Edge> e;
vector<pii> mst[N];
int dp[N];

void dfs(int u, int fa) {
    for(pii v : mst[u]) {
        if(v.fir == fa) continue;
        dp[v.fir] = max(dp[v.fir], min(dp[u], v.sec));
        dfs(v.fir, u);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, r, d;
    cin>>c>>r;
    DSU dsu(c);
    for(int i = 1;i<=r;i++) {
        Edge cur;
        cin>>cur.u>>cur.v>>cur.w;
        e.pb(cur);
    }
    sort(all(e));
    for(Edge i : e) 
        if(dsu.merge(i.u, i.v)) {
            mst[i.u].pb(mp(i.v, i.w)),
            mst[i.v].pb(mp(i.u, i.w));
        }
    dp[1] = INF;
    dfs(1, 0);
    int ans = INF;
    for(int i = 1;i<=c;i++) {
        cout<<(i == 1 ? 0 : dp[i])<<'\n';
    }
    return 0;
}
