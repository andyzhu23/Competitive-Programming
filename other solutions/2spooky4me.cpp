#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e4 + 10;
int n, l, s, a[N], b[N], c[N];
set<int> dis;
unordered_map<ll, int> rnk;
ll id[N];
ll lazy[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    #endif
    cin>>n>>l>>s;
    dis.insert(1);
    dis.insert(l);
    for(int i = 1;i<=n;++i) {
        cin>>a[i]>>b[i]>>c[i];
        if(a[i] <= l) {
            if(a[i] - 1 > 0) dis.insert(a[i] - 1);
            dis.insert(a[i]);
        }
        if(b[i] <= l) {
            dis.insert(b[i]);
            if(b[i] + 1 <= l) dis.insert(b[i] + 1);
        }
    }
    int len = 0;
    for(auto& x : dis) {
        rnk[x] = ++len;
        id[len] = x;
    }
    for(int i = 1;i<=n;++i) {
        lazy[rnk[a[i]]] += c[i];
        if(b[i] + 1 <= l) lazy[rnk[b[i] + 1]] -= c[i];
    }
    ll ans = 0;
    for(int i = 1;i<=len;++i) {
        lazy[i] += lazy[i - 1];
        if(lazy[i] < s) ans += id[i] - id[i - 1];
    }
    cout<<ans<<'\n';
    return 0;
}
