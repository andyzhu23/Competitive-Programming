#include <bits/stdc++.h>
using namespace std;
#define pb push_back
using ll = long long;
const int N = 1e5 + 5;
int n, cnt[N], dep[N], tot, f[N][22];
ll dp[N], leaf[N], b;
bool flag = 1;
int k, q;
vector<int> e[N];
vector<int> dfn;

void dfs(int u = 0) {
    for(int i = 1;i<=20;++i) f[u][i] = f[f[u][i - 1]][i - 1];
    cnt[u] = tot;
    if(e[u].size() == 0) {
        ++tot;
        if(flag) {
            b = dfn.size();
            flag = 0;
        }
    }
    dfn.pb(u);
    assert(u + 1 == dfn.size());
    for(int v : e[u]) {
        dep[v] = dep[u] + 1;
        f[v][0] = u;
        dfs(v);
    }
}

int bs(int x, int y) {
    int lo = 0, hi = dfn.size() - 1, ans = 0;
    while(lo <= hi) {
        int mid = lo + hi >> 1;
        if(cnt[dfn[mid]] >= 0 && mid + cnt[dfn[mid]] * dp[y] >= 0 && mid + cnt[dfn[mid]] * dp[y] < x) 
            ans = mid, lo = mid + 1;
        else hi = mid - 1;
    }
    return ans;
}

deque<int> get(int x) {
    deque<int> ans;
    for(int i = 0;i<=k;++i) {
        int idx = bs(x, k - i);
        ans.pb(dfn[idx]);
        if(idx + cnt[dfn[idx]] * dp[k - i] + 1 == x) break;
        x -= idx + cnt[dfn[idx]] * dp[k - i];
    }
    return ans;
}

int LCA(int u, int v) {
    if(dep[v] > dep[u]) swap(u, v);
    for(int i = 20;~i;--i) {
        if(dep[f[u][i]] >= dep[v]) u = f[u][i];
        if(u == v) return u;
    }
    for(int i = 20;~i;--i) {
        if(f[u][i] != f[v][i]) {
            u = f[u][i];
            v = f[v][i];
        }
    }
    return f[u][0];
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    for(int i = 1;i<n;++i) {
        int x; cin>>x;
        --x;
        e[x].pb(i);
    }
    dfs();
    cin>>k>>q;
    int ok = k;
    k = min(k, 30);
    ok -= k;
    dp[0] = 0, leaf[0] = 1;
    for(int i = 1;i<=k;++i) {
        leaf[i] = leaf[i - 1] * tot;
        if(dp[i - 1] < 0) dp[i] = dp[i - 1];
        else dp[i] = dp[i - 1] + leaf[i - 1] * (n - 1);
    }
    while(q--) {
        int u, v;
        cin>>u>>v;
        int ans = 0;
        if(u <= ok * b + 1 && v <= ok * b + 1) {
            ans = abs(u - v);
            cout<<ans<<'\n';
            continue;
        } else if(u <= ok * b + 1) {
            ans += ok * b + 1 - u;
            u = ok * b + 1;
        } else if(v <= ok * b + 1) {
            ans += ok * b + 1 - v;
            v = ok * b + 1;
        }
        u -= ok * b, v -= ok * b;
        auto a = get(u);
        auto b = get(v);
        while((!a.empty() && !b.empty()) && a.front() == b.front()) a.pop_front(), b.pop_front();
        if(a.empty()) a.pb(0);
        if(b.empty()) b.pb(0);
        int lca = LCA(a.front(), b.front());
        for(auto x : a) ans += dep[x];
        for(auto x : b) ans += dep[x];
        ans -= dep[lca] * 2;
        cout<<ans<<'\n';
    }
    return 0;
}
