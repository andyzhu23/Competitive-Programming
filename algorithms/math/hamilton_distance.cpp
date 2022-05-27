#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int n, a = -inf, b = inf, c = -inf, d = inf;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    for(int i = 1;i<=n;++i) {
        int x, y; cin>>x>>y;
        a = max(x + y, a);
        b = min(x + y, b);
        c = max(x - y, c);
        d = min(x - y, d);
    }
    cout<<max(a - b, c - d)<<'\n';
    return 0;
}
