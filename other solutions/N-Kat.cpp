#include <bits/stdc++.h>
using namespace std;
const int N = 11e5;
#define fir first
#define sec second
#define pb push_back
using ll = long long;
using pll = pair<ll, ll>;
pll val[N];
int n, a[N];
vector<int> x, y;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    for(int i = 1;i<=n;++i) cin>>a[i];
    for(int i = 1;i<=(1 << n) - 1;++i) {
        for(int j = 0;j<n;++j) {
            val[i].fir += a[j + 1] * ((i >> j) & 1);
        }
        val[i].sec = i;
    }
    sort(val + 1, val + (1 << n));
    ll mn = 0x3f3f3f3f3f3f3f3f;
    int u, v;
    for(int i = 2;i<=(1 << n) - 1;++i) if(mn > val[i].fir - val[i - 1].fir && ((val[i].sec | val[i - 1].sec) != val[i].sec)) {
        mn = val[i].fir - val[i - 1].fir;
        u = val[i].sec;
        v = val[i - 1].sec;
    }
    for(int i = 0;i<n;++i) if((u >> i) & 1) x.pb(i + 1);
    for(int i = 0;i<n;++i) if((v >> i) & 1) y.pb(i + 1);
    for(int i = 0;i<x.size();++i) cout<<x[i]<<" \n"[i == x.size() - 1];
    for(int i = 0;i<y.size();++i) cout<<y[i]<<" \n"[i == y.size() - 1];
    return 0;
}
