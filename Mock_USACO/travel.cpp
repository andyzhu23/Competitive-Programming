#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 10;
#define pb push_back
using pii = pair<int, int>;
#define fir first
#define sec second
vector<pii> e[N];

int n, siz[N], mx = 0, tot = 0;

void dfs1(int u, int fa = 0, int dist = 0) {
    siz[u] = siz[fa] + dist;
    mx = max(mx, siz[u]);
    tot += dist;
    for(pii v : e[u]) {
        if(fa == v.fir) continue;
        dfs1(v.fir, u, v.sec);
    }
    tot += dist;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    for(int i = 1;i<n;++i) {
        int u, v, w;
        cin>>u>>v>>w;
        e[u].pb({v, w});
        e[v].pb({u, w});
    }
    dfs1(1);
    cout<<tot - mx<<'\n';
    return 0;
}
