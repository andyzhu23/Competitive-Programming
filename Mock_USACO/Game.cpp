#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;
    string s; cin>>s;
    int tot = 0;
    for(int i = 0;i<n;++i) {
        if(s[i] == '1') {
            tot += n - 1 - i;
        }
    }
    cout<<(tot & 1 ? 'M' : 'L')<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
