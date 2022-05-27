#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int inf = 0x3f3f3f3f;
int n, m, k, a[N], b[N];

bool ok(int x) {
    for(int i = 1, j = 1;j<=m;++j) {
        if(a[i] < b[j]) break;
        int cnt = 0;
        while(i <= n && cnt < x && a[i] <= b[j] + k) ++cnt, ++i;
        if(i == n + 1) return 1;
    }
    return 0;
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>m>>k;
    for(int i = 1;i<=n;++i) cin>>a[i];
    for(int i = 1;i<=m;++i) cin>>b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    int lo = 1, hi = inf, ans = -1;
    ok(1);
    while(lo <= hi) {
        int mid = lo + hi >> 1;
        if(ok(mid)) ans = mid, hi = mid - 1;
        else lo = mid + 1;
    }
    cout<<ans<<'\n';
    return 0;
}
