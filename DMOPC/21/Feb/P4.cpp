#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 2e5 + 5;
using pii = pair<int, int>;
vector<pii> e[N];
int n, m, A, B, C, D, ans[N];
pii f[N];
bool vis[N], path[N], flag, flag2, vis3[N];
vector<int> stk;

void dfs(int u, int no) {
    for(auto[v, id] : e[u]) {
        if(v == no) continue;
        if(vis[v]) continue;
        vis[v] = 1;
        dfs(v, no);
    }
}

void bfs(int u, int last = 1) {
    queue<pii> q;
    memset(vis, 0, sizeof(vis));
    vis[u] = 1;
    q.push({u, last});
    while(!q.empty()) {
        auto[u, last] = q.front(); q.pop();
        for(auto[v, id] : e[u]) {
            if(!ans[id]) {
                if(last == 1) ans[id] = 2;
                else ans[id] = 1;
            }
            if(!vis[v]) {
                vis[v] = 1;
                q.push({v, ans[id]});
            }
        }
    }
}

pii last[N];

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>m;
    for(int i = 1;i<=m;++i) {
        int u, v; cin>>u>>v;
        e[u].pb({v, i});
        e[v].pb({u, i});
        f[i] = {u, v};
    }
    cin>>A>>B>>C>>D;
    for(auto[v, id] : e[C]) {
        if(v == D) {
            cout<<-1<<'\n';
            return 0;
        }
    }
    flag = 0;
    dfs(A, C);
    flag = vis[B];
    memset(vis, 0, sizeof(vis));
    dfs(A, D);
    flag |= vis[B];
    if(!flag) {
        cout<<-1<<'\n';
        return 0;
    }
    cout<<2<<'\n';
    int no;
    if(vis[B]) no = D;
    else no = C;
    if(no == D) {
        memset(vis, 0, sizeof(vis));
        dfs(A, C);
        if(vis[B]) no = C;
    }
    queue<int> q;
    memset(vis, 0, sizeof(vis));
    q.push(A);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        if(u == B) break;
        for(auto [v, id] : e[u]) if(!vis[v] && v != no) {
            vis[v] = 1;
            last[v] = {u, id};
            q.push(v);
        }
    }
    int u = B;
    while(u != A) {
        stk.push_back(last[u].second);
        u = last[u].first;
    }
    for(auto x : stk) ans[x] = 1;
    memset(vis, 0, sizeof(vis));
    bfs(no);
    for(int i = 1;i<=m;++i) cout<<ans[i]<<'\n';
    return 0;
}