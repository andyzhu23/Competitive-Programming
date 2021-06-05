#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define ALL(v) v.begin(), v.end()
using namespace std;
struct Edge {int u, v, w;};
const int N = 1e5 + 10;
int n, sz;
vector<int> p[N];
vector<int> e[2 * N], vis(2 * N);
vector<Edge> Map;
vector<int> f(N);

void dfs(int u, int val){
    vis[u] = val;
    for(int v : e[u]){
        if(vis[v]) continue;
        dfs(v, val);
    }
}

bool cmp(Edge a, Edge b){
    return a.w < b.w;
}

int Find(int x) {return x == f[x] ? x : f[x] = Find(f[x]);}

bool merge(int u, int v) {
    int fu = Find(u);
    int fv = Find(v);
    if(fu == fv) return false;
    f[fu] = fv;
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i = 1;i<=n;i++){
        int c, p1, p2, p3, p4;
        cin>>c>>p1>>p2>>p3>>p4;
        p[i] = {c, p1, p2, p3, p4};
        e[p1].pb(p2);
        e[p2].pb(p1);
        e[p3].pb(p4);
        e[p4].pb(p3);
    }

    // find all cycles for all portals
    int c = 0;
    for(int i = 1;i<=2 * n;i++)
        if(!vis[i]) dfs(i, ++c);
        
    // build graph
    for(int i = 1;i<=n;i++)
        Map.pb({vis[p[i][1]], vis[p[i][3]], p[i][0]});

    // kruskal
    int ans = 0;
    sz = Map.size();
    for(int i = 1;i<=c;i++) f[i] = i;
    sort(ALL(Map), cmp);
    for(Edge cur : Map)
        if(merge(cur.u, cur.v)) ans += cur.w;
    cout<<ans<<endl;
    return 0;
}
