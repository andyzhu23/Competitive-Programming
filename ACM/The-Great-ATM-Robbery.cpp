#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 1;
#define pb push_back

int n, m;
template <typename T> using vec = vector<T>;
using vi = vec<int>;
vi e[N], Map[N];
int root, P, tot, cnt, low[N], dfn[N], color[N], sum[N], dp[N];
int16_t a[N];
bitset<N> p, pi, instk;
stack<int> stk;

void tarjan(int& u) {
    dfn[u] = low[u] = ++tot;
    stk.push(u);
    instk[u] = 1;
    for(int& v : e[u]) {
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (instk[v]) low[u] = min(low[u], dfn[v]);
    }
    if(dfn[u] == low[u]) {
        cnt++;
        while(stk.top() != u) {
            color[stk.top()] = cnt;
            instk[stk.top()] = 0;
            sum[cnt] += a[stk.top()];
            stk.pop();
        }
        color[stk.top()] = cnt;
        instk[stk.top()] = 0;
        sum[cnt] += a[stk.top()];
        stk.pop();
    }
}


void dfs(int& u, int fa) {
    for(int v : Map[u]) {
        if(v == fa) continue;
        if(dp[v] == 0) dfs(v, u);
        dp[u] = max(dp[u], dp[v]);
    }
    if(dp[u] || pi[u]) dp[u] += sum[u];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 1;i<=m;i++) {
        int a, b;
        cin>>a>>b;
        e[a].pb(b);
    }
    for(int i = 1;i<=n;i++) cin>>a[i];
    cin>>root>>P;
    for(int i = 1;i<=P;i++) {
        int x; cin>>x;
        p[x] = 1;
    }
    for(int i = 1;i<=n;i++)
        if(!dfn[i]) tarjan(i);
    for(int u = 1;u<=n;u++) {
        for(int i = 0;i<e[u].size();) {
            int& v = e[u][i];
            if(color[u] != color[v]) Map[color[u]].pb(color[v]);
            e[u].erase(i + e[u].begin());
        }
    }

    for(int i = 1;i<=n;i++)
        pi[color[i]] = pi[color[i]] ? 1: p[i];

    dfs(color[root], 0);
    cout<<dp[color[root]]<<"\n";
    return 0;
}
