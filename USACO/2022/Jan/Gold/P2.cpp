#include <bits/stdc++.h>
using namespace std;


using pii = pair<int, int>;
#define pb push_back
const int N = 2e5 + 5;
vector<pii> e;
vector<int> cur[N];
int n, m, d[N], ans[N], f[N];
struct q {
    int opt, a, b;
} q[N];

map<pii, int> vis;

int Find(int x) {return f[x] == x ? x : f[x] = Find(f[x]);}
bool merge(pii x) {
    int u = x.first;
    int v = x.second;
    int fu = Find(u);
    int fv = Find(v);
    if(fu == fv) return 0;
    f[fu] = fv;
    d[fv] += d[fu];
    cur[fu].pb(fv);
    cur[fv].pb(fu);
    return 1;
}

unordered_set<int> did;

void dfs(int u, int i) {
    ans[u] = i;
    for(int v : cur[u]) if(!did.count(v)) {
        did.insert(v);
        dfs(v, i);
    }
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>m;
    iota(f, f + n + 1, 0);
    memset(ans, -1, sizeof(ans));
    for(int i = 1;i<=n;++i) d[i] = 1;
    for(int i = 1;i<=m;++i) {
        char opt; int a, b;
        cin>>opt;
        if(opt == 'A') {
            cin>>a>>b;
            e.pb({a, b});
            q[i] = {opt, a, b};
        } else if(opt == 'D') {
            cin>>a;
            d[a] = 0;
            q[i] = {opt, a};
        } else {
            cin>>a;
            q[i] = {opt, a};
            vis[e[a - 1]] = 1;
        }
    }
    for(auto x : e) if(!vis[x]) {
        merge(x);
    }
    for(int i = m;i;--i) {
        if(q[i].opt == 'A') continue;
        else if(q[i].opt == 'D') {
            int u = q[i].a;
            int fu = Find(u);
            if(d[fu]++ == 0) {
                dfs(u, i - 1);
            }
        } else {
            int u = e[q[i].a - 1].first;
            int v = e[q[i].a - 1].second;
            int fu = Find(u);
            int fv = Find(v);
            if(fu != fv) {
                if(d[fu] == 0 ^ d[fv] == 0) {
                    d[fu] == 0 ? dfs(u, i - 1) : dfs(v, i - 1);
                }
            }
            merge({u, v});
        }
    }
    for(int i = 1;i<=n;++i) cout<<(ans[i] == -1 ? m : ans[i])<<'\n';
    return 0;
}
