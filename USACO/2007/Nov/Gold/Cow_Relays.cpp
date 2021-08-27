#include <bits/stdc++.h>
using namespace std;
#define ins insert
#define pb push_back
int n, t, s, e, f[23][1000][1000];
const int INF = 0x3f3f3f3f;
struct ed {
    int u, v, w;
    ed(int U, int V, int W) {
        u = U, v = V, w = W;
    }
};
set<int> vis;
map<int, int> Map;
vector<ed> edge;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>t>>s>>e;
    memset(f, 0x3f, sizeof(f));
    for(int i = 1;i<=t;i++) {
        int u, v, w;
        cin>>w>>u>>v;
        vis.ins(u);
        vis.ins(v);
        edge.pb(ed(u, v, w));
    }
    int cnt = 0;
    for(auto& x : vis) Map[x] = ++cnt;
    for(ed& x : edge) {
        f[0][Map[x.u]][Map[x.v]] = x.w;
        f[0][Map[x.v]][Map[x.u]] = x.w;
    }
    for(int i = 1;i<=22;i++) 
        for(int u = 1;u<=cnt;u++) 
            for(int v = 1; v<=cnt;v++) 
                for(int k = 1;k<=cnt;k++) 
                    f[i][u][v] = min(f[i][u][v], f[i - 1][u][k] + f[i - 1][k][v]);
                
    int ans[1000][1000];
    for(int i = 1;i<=cnt;i++) 
        for(int j = 1;j<=cnt;j++) 
            ans[i][j] = f[int(log2(n))][i][j];
        
    int cnt2 = 1 << int(log2(n));
    for(int i = int(log2(n)) - 1;i>=0;i--) {
        if (cnt2 + (1 << i) > n) continue;
        cnt2 += 1 << i;
        int nxt[1000][1000];
        memset(nxt, 0x3f, sizeof(nxt));
        for (int u = 1; u <= cnt; u++)
            for (int v = 1; v <= cnt; v++)
                for (int k = 1; k <= cnt; k++)
                    nxt[u][v] = min(nxt[u][v], ans[u][k] + f[i][k][v]);

        for (int u = 0; u <= cnt; u++)
            for (int v = 0; v <= cnt; v++)
                ans[u][v] = nxt[u][v];
    }
    cout<<ans[Map[s]][Map[e]]<<'\n';
    return 0;
}
