#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, a[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif  
    scanf("%d", &n);
    for(int i = 1;i<=n;++i) scanf("%d", a + i);
    int x;
    for(int i = 1;i<=n;++i) scanf("%d", &x), a[i] -= x;
    int l = 0, ans = 0;
    while(l <= n) {
        while(l <= n && a[l] == 0) l++;
        if(l > n) break;
        int r = l;
        while((a[r] < 0 && a[l] < 0) || (a[r] > 0 && a[l] > 0) && r <= n) ++r;
        int c = a[l];
        for(int i = l;i<r;++i) c = a[l] > 0 ? min(c, a[i]) : max(c, a[i]);
        for(int i = l;i<r;++i) a[i] += -c;
        ans += abs(c);
    }
    printf("%d\n", ans);
    return 0;
}
