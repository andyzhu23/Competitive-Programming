#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
using pii = pair<int, int>;
const int N = 2e4 + 10;
vector<int> e[N], ans;

int dfn[N], low[N], instk[N], tot, cnt, n, m, color[N];

stack<int> stk;

void dfs(int u) {
    dfn[u] = low[u] = ++tot;
    stk.push(u);
    instk[u] = 1;
    int son = 0;
    for(int v : e[u]) {
        if(!dfn[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
            if(u == 1) son++;
            if(u != 1 && low[v] >= dfn[u]) ans.pb(u);
        } else if(instk[v]) low[u] = min(low[u], dfn[v]);
    }
    if(u == 1 && son >= 2) ans.pb(u);
    if(dfn[u] == low[u]) {
        cnt++;
        while(stk.top() != u) {
            color[stk.top()] = cnt;
            instk[stk.top()] = 0;
            stk.pop();
        }
        color[stk.top()] = cnt;
        instk[stk.top()] = 0;
        stk.pop();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 1;i<=m;i++) {
        int x, y;
        cin>>x>>y;
        e[x].pb(y);
        e[y].pb(x);
    }
    dfs(1);
    int flag = 0;
    cout<<ans.size()<<"\n";
    if(ans.size() == 0) return 0;
    sort(ALL(ans));
    for(int i = 0;i<ans.size() - 1;i++) cout<<ans[i]<<" ";
    cout<<ans[ans.size() - 1]<<"\n";
    return 0;
}
