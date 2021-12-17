#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
using ll = long long;
// p number of 0 from back, p2 number of 1 from front
int n, a[N], b[N];
ll cnt, tot, tot2, p[N], p2[N];

int main() {
    freopen("balance.in", "r", stdin);
    freopen("balance.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1;i<=n * 2;++i) scanf("%d", a + i), b[i] = a[i];
    for(int i = 1;i<=n;++i) {
        p2[i] = cnt;
        cnt += a[i];
    }
    cnt = 0;
    for(int i = n;i;--i) {
        p[i] = cnt;
        if(a[i]) tot += p[i];
        cnt += a[i] ^ 1;
    }
    cnt = 0;
    for(int i = n + 1;i<=n * 2;++i) {
        p2[i] = cnt;
        cnt += a[i];
    }
    cnt = 0;
    for(int i = n * 2;i>n;--i) {
        p[i] = cnt;
        if(a[i]) tot2 += p[i];
        cnt += a[i] ^ 1;
    }
    ll ans = abs(tot - tot2);
    int l = n, r = n + 1;
    ll tott = tot, tott2 = tot2;
    ll prev = 0;
    // move 1 from right to left
    for(int t = 1;t <= n;++t) {
        while(l >= 0 && a[l]) l--;
        while(r <= n * 2 && a[r] ^ 1) r++;
        if(l < 0 || r > n * 2) break;
        prev += r - l;
        cnt = prev;
        tott = tott - p2[l];
        tott2 = tott2 - p[r];
        cnt += abs(tott2 - tott);
        ans = min(ans, cnt);
        swap(a[l], a[r]);
        l--, r++;
    }
    l = n, r = n + 1;
    tott = tot, tott2 = tot2;
    prev = 0;
    // move 1 from left to right
    for(int t = 1;t <= n;++t) {
        while(l >= 0 && b[l] ^ 1) l--;
        while(r <= n * 2 && b[r]) r++;
        if(l < 0 || r > n * 2) break;
        prev += r - l;
        cnt = prev;
        tott = tott + p2[l] - (n - l);
        tott2 = tott2 + p[r] - (r - n - 1);
        cnt += abs(tott2 - tott);
        ans = min(ans, cnt);
        swap(b[l], b[r]);
        l--, r++;
    }
    printf("%d\n", ans);
    return 0;
}
