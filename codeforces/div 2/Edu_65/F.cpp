#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
const int MOD = 1e9 + 7;

ll n, a[N], l[N], r[N];

struct fenwick {
    ll c[N];
    int lowbit(int i) {return i & (-i);}
    void update(int a, ll b) {
        for(int i = a;i<N;i+=lowbit(i)) c[i] = (c[i] + b) % MOD;
    }
    ll query(int a) {
        ll ans = 0;
        for(int i = a;i;i-=lowbit(i)) ans = (ans + c[i]) % MOD;
        return ans;
    }
    ll query(int a, int b) {
        return (query(b) - query(a - 1) + MOD) % MOD;
    }
} fen1, fen2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    set<ll> dis;
    for(int i = 1;i<=n;++i) {
        cin>>a[i];
        dis.insert(a[i]);
    }
    int len = 0;
    unordered_map<ll, int> Map;
    for(auto x : dis) Map[x] = ++len;
    for(int i = 1;i<=n;++i) {
        l[i] = fen1.query(1, Map[a[i]]) % MOD;
        fen1.update(Map[a[i]], i);
    }
    for(int i = n;i>0;--i) {
        r[i] = fen2.query(1, Map[a[i]]) % MOD;
        fen2.update(Map[a[i]], n - i + 1);
    }
    ll ans = 0;
    for(int i = 1;i<=n;++i) {
        ans = (ans + a[i] * (l[i] * (n - i + 1) % MOD + r[i] * i % MOD + (n - i + 1) * i % MOD) % MOD) % MOD;
    }
    cout<<ans<<'\n';
    return 0;
}
