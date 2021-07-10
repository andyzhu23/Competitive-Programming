#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using pii = pair<int, int>;
#define mp make_pair
#define fir first
#define sec second
#define pb push_back
const int N = 1e4 + 10;

stack<int> stk;

int tot, color, colid[N];
vector<pii> edge;

vi e[N], Map[N];
int low[N], dfn[N], in[N], sum[N], a[N], dp[N];
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
            colid[stk.top()] = color;
            sum[color] += a[stk.top()];
            stk.pop();
        }
        sum[color] += a[stk.top()];
        vis[stk.top()] = 0;
        colid[stk.top()] = color;
        stk.pop();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    tot = 0;
    color = 0;
    cin>>n>>m;
    for(int i = 1;i<=n;i++) {
        cin>>a[i];
    }
    for(int i = 1;i<=m;i++) {
        int u, v;
        cin>>u>>v;
        edge.pb(mp(u, v));
        e[u].pb(v);
    }
    for(int i = 1;i<=n;i++) {
        if(!dfn[i]) dfs(i);
    }
    for (pii i : edge) {
        if(colid[i.fir] != colid[i.sec]) {
            Map[colid[i.fir]].pb(colid[i.sec]);
            in[colid[i.sec]] ++;
        }
    }
    queue<int> q;
    int ans = 0;
    for(int i = 1;i<=color;i++) {
        if(in[i] == 0) q.push(i);
        dp[i] = sum[i];
        ans = max(ans, dp[i]);
    }

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int i : Map[cur]) {
            in[i] --;
            dp[i] = max(dp[i], dp[cur] + sum[i]);
            ans = max(ans, dp[i]);
            if(in[i] == 0)
                q.push(i);
        }
    }
    cout<<ans<<"\n";
    return 0;
}
