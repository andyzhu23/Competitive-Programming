#include <iostream>
#define endl "\n"
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
const ll INF = 4e9;
int n;
ll c, a[N], b[N];

inline void solve(){
    cin >> n >> c;
    ll ans = INF;
    for(int i = 1;i<=n;i++) cin>>a[i];
    for(int i = 1;i<n;i++) cin>>b[i];
    ll k = 0;
    ll cur = 0;
    for(int i = 1;i<=n;i++){
        ans = min(ans, (c - cur - 1) / a[i] + 1 + k);
        if(i == n) continue;
        ll days = 0;
        if(cur < b[i]) days = (b[i] - cur - 1) / a[i] + 1;
        cur = a[i] * (days++) + cur - b[i];
        k += days;
    }
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
