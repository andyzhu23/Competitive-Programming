#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define random(a, b) rng() % (b - a + 1) + a
#define pb push_back
using ll = long long;
int n, m;
ll a[N], tot, ctot, sum[N], csum[N];
vector<int> e[N];

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>m;
    for(int i = 1;i<=n;++i) a[i] = random(1, (int)1e9), tot += a[i];
    for(int i = 1;i<=m;++i) {
        int u, v;
        cin>>u>>v;
        e[v].pb(u);
        sum[v] += a[u];
        csum[v] += a[u];
        ctot += a[u];
    }
    int q; cin>>q;
    while(q--) {
        int opt; cin>>opt;
        int u, v;
        switch (opt) {
            case 1: 
                cin>>u>>v;
                csum[v] -= a[u];
                ctot -= a[u];
            break;
            case 2: 
                cin>>u;
                ctot -= csum[u];
                csum[u] = 0;
            break;
            case 3: 
                cin>>u>>v;
                csum[v] += a[u];
                ctot += a[u];
            break;
            case 4: 
                cin>>u;
                ctot += sum[u] - csum[u];
                csum[u] = sum[u];
            break;
        }
        cout<<(tot == ctot ? "YES" : "NO")<<'\n';
    }
    return 0;
}

