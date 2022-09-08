#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
using ll = long long;
int n, k, q, a[N], p[N];
ll ans;
vector<int> e[N];
unordered_set<int> big;
unordered_map<int, ll> mp[N], cnt;

struct fenwick {
    int c[N];
    void update(int a, int b) {
        for(int i = a;i<=n;i+=i&(-i)) c[i] += b;
    }
    int query(int a) {
        int ans = 0;
        for(int i = a;i;i-=i&(-i)) ans += c[i];
        return ans;
    }
    int query(int a, int b) {
        return query(b) - query(a - 1);
    }
} fen;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>k>>q;
    for(int i = 1;i<=n;++i) {
        cin>>a[i];
        p[i] = i;
        e[a[i]].push_back(i);
        if(e[a[i]].size() > 100) big.insert(a[i]);
        ans += fen.query(a[i] + 1, k);
        fen.update(a[i], 1);
    }
    for(int i = 1;i<=n;++i) {
        for(auto x : big) mp[a[i]][x] += cnt[x];
        if(big.count(a[i])) ++cnt[a[i]];
    }
    while(q--) {
        int u; cin>>u;
        if(big.count(p[u])) ans = ans + mp[p[u + 1]][p[u]] * 2 - 1ll * e[p[u]].size() * e[p[u + 1]].size();
        else if(big.count(p[u + 1])) ans = ans + 1ll * e[p[u]].size() * e[p[u + 1]].size() - mp[p[u]][p[u + 1]] * 2;
        else {
            ll cnt = 0;
            for(int i = 0, j = 0;i<e[p[u]].size();++i) {
                while(j < e[p[u + 1]].size() && e[p[u]][i] > e[p[u + 1]][j]) ++j;
                cnt += j;
            }
            ans = ans + 1ll * e[p[u]].size() * e[p[u + 1]].size() - cnt * 2;
        }
        cout<<ans<<'\n';
        swap(p[u], p[u + 1]);
    }
    return 0;
}
