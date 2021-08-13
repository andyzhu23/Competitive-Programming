#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define lb lower_bound
const int N = 210;
int n, dfn[N], low[N], instk[N], tot, color[N], cnt, in[N], out[N];
vector<int> e[N], e2[N];
stack<int> stk;

void tarjan(int u) {
    dfn[u] = low[u] = ++tot;
    instk[u] = 1;
    stk.push(u);
    for(int& v : e[u]) {
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if(instk[v]) low[u] = min(dfn[v], low[u]);
    }
    if(dfn[u] == low[u]) {
        ++cnt;
        while(stk.top() != u) {
            color[stk.top()] = cnt;
            instk[stk.top()] = 0;
            stk.pop();
        }
        color[u] = cnt;
        instk[u] = 0;
        stk.pop();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 1;i<=n;i++) {
        while(1) {
            int x; cin>>x;
            if(x == 0) break;
            e[i].pb(x);
        }
        sort(ALL(e[i]));
    }
    for(int i = 1;i<=n;i++) 
        if(!dfn[i]) tarjan(i);
    for(int u = 1;u<=n;u++) {
        for(int& v : e[u]) {
            if(color[u] != color[v]) {
                e2[color[u]].pb(color[v]);
                in[color[v]]++;
                out[color[u]]++;
            }
        }
    }
    int ans1 = 0, ans2 = 0;
    for(int i = 1;i<=cnt;i++) {
        ans1 += in[i] == 0;
        ans2 += out[i] == 0;
    }
    ans2 = cnt == 1 ? 0 : max(ans1, ans2);
    cout<<ans1<<'\n'<<ans2<<'\n';

    return 0;
}
