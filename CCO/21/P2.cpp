#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int D = 5e3 + 5;
int a[D], k, q, d, m, tot;
bool flag;
int ans[1000005];
bool tmp;
set<int> vis;

void solve(ll x) {
    if(flag) return;
    if(x == 0 && tot) {
        for(int i = tot;i;--i) cout<<ans[i]<<" \n"[i==1];
        flag = 1;
        return;
    }
    if(vis.count(x)) return;
    vis.insert(x);
    for(int i = 1;i<=d;++i) if((x - a[i]) % k == 0) {
        ans[++tot] = a[i];
        solve((x - a[i]) / k);
        --tot;
    }
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>k>>q>>d>>m;
    bool flagg = 0;
    for(int i = 1;i<=d;++i) cin>>a[i], flagg |= a[i] == 0;
    for(int i = 1;i<=q;++i) {
        vis.clear();
        ll x; cin>>x;
        solve(x);
        if(!flag) cout<<"IMPOSSIBLE\n";
        flag = 0;
    }
    return 0;
}
