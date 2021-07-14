#include <bits/stdc++.h>
using namespace std;

#define fir first
#define sec second
#define mp make_pair
#define pb push_back

using pii = pair<int, int>;
const int N = 1e4 + 10;
int dfn[N], low[N];
vector<int> e[N], Map[N];

int colid[N], color, vis[N], sum[N], n, m, out[N];
stack<int> stk;
vector<pii> edge;

int tot;

void dfs(int u) {
    dfn[u] = low[u] = ++tot;

    stk.push(u);
    vis[u] = 1;

    for(int v : e[u]) {
        if(!dfn[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if(vis[v]) low[u] = min(dfn[v], low[u]);
    }
    if(low[u] == dfn[u]) {
        color++;
        while(stk.top() != u) {
            vis[stk.top()] = 0;
            colid[stk.top()] = color;
            sum[color] ++;
            stk.pop();
        }
        sum[color] ++;
        vis[stk.top()] = 0;
        colid[stk.top()] = color;
        stk.pop();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 1;i<=m;i++) {
        int a, b;
        cin>>a>>b;
        e[a].pb(b);
        edge.pb(mp(a, b));
    }
    for(int i = 1;i<=n;i++) 
        if(!dfn[i]) dfs(i);

    for(pii i : edge) {
        if(colid[i.fir] != colid[i.sec]) {
            Map[colid[i.fir]].pb(colid[i.sec]);
            out[colid[i.fir]]++;
        }
    }
    int ans = 0;
    bool flag = 0;
    for(int i = 1;i<=color;i++) {
        if(out[i] == 0) {
            ans = sum[i];
            if(flag == 1) {
                cout<<0<<"\n";
                return 0;
            }
            flag = 1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
