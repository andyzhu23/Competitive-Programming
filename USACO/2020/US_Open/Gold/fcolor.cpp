#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
vector<int> e[N];

struct DSU {
    int f[N];
    void init() {
        for(int i = 1;i<N;i++) f[i] = i;
    }
    int Find(int x) {return f[x] == x ? x : f[x] = Find(f[x]);}
    bool merge(int u, int v) {
        int fu = Find(u);
        int fv = Find(v);
        if(fu == fv) return 0;
        f[fv] = fu;
        // because we set them to be the same cow, 
        // we need to merge their edges
        for(int i : e[fv]) e[fu].pb(i);
        e[fv].clear();
        return 1;
    }
} dsu;

int n, m;
queue<int> q;

void merge(int u) {
    if(int(e[u].size()) <= 1) return;
    int nxt = e[u][0];
    while(int(e[u].size()) > 1) {
        // merge all cows admire u as the same color
        dsu.merge(nxt, e[u].back());
        // the last node don't need to exist anymore
        e[u].erase(e[u].begin() + int(e[u].size()) - 1);
    }
    if(e[nxt].size() > 1) q.push(nxt);
}


int main() {
    freopen("fcolor.in", "r", stdin);
    freopen("fcolor.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    dsu.init();
    cin>>n>>m;
    for(int i = 1;i<=m;i++) {
        int a, b;
        cin>>a>>b;
        e[a].pb(b);
    }
    // we might not find all relations in one go
    for(int cnt = 0;cnt<=1;cnt++) {
        for(int i = 1;i<=n;i++) {
            if(e[i].size() > 1) q.push(i);
        }
        // use a queue because we might go through 
        // the same cow more than once
        while(!q.empty()) {
            while(e[q.front()].size() <= 1) q.pop();
            merge(q.front()); q.pop();
        }
    }
    
    unordered_map<int, int> ans;
    int tot = 0;
    for(int i = 1;i<=n;i++) {
        if(!ans[dsu.Find(i)]) ans[dsu.Find(i)] = ++tot;
        cout<<ans[dsu.Find(i)]<<'\n';
    }
    return 0;
}