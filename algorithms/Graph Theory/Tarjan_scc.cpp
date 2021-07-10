#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
#define pb push_back
const int N = 1e4 + 10;

stack<int> stk;

int tot, color;

vi e[N];
int low[N], dfn[N];
bool vis[N];

void dfs(int u) {
    dfn[u] = low[u] = ++tot;

    stk.push(u);
    vis[u] = 1;
    for (int v : e[u]) {
        if(!dfn[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if(vis[v]) low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u]) {
        color ++;
        while(stk.top() != u) {
            vis[stk.top()] = 0;
            stk.pop();
        }
        vis[stk.top()] = 0;
        stk.pop();
    }
}


void solve() {
    memset(low, 0, sizeof(low));
    memset(dfn, 0, sizeof(dfn));
    for(int i = 0;i<N;i++) e[i].clear();
    int n, m;
    tot = 0;
    color = 0;
    cin>>n>>m;
    for(int i = 1;i<=m;i++) {
        int u, v;
        cin>>u>>v;
        e[u].pb(v);
    }
    for(int i = 1;i<=n;i++) {
        if(!dfn[i]) dfs(i);
    }
    cout<<(color == 1 ? "Yes" : "No")<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
