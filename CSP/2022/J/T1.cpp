#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ll a, b;
    cin>>a>>b;
    if(a == 0) {
        cout<<0<<'\n';
        return 0;
    }
    ll c = 1;
    while(b) {
        if(b & 1) {
            c *= a;
            if(c > 1e9) c = 0;
        }
        b >>= 1;
        a = a * a;
        if(a > 1e9) a = 0;
    }
    if(c == 0) cout<<-1<<'\n';
    else cout<<c<<'\n';
    return 0;
}
