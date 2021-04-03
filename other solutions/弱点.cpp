#include <iostream>
#include <memory.h>
#define getMid(l, r) (l + r) >> 1;
#define push_up(rt) st[rt] = st[rt << 1] + st[rt << 1 | 1];
using namespace std;
using ll = long long;
const int N = 1e6 + 10;
int n, a[N];
ll st[N << 2], res1[N], res2[N]; // make sure this is long long

inline void update(int rt, int l, int r, int pos, int val) {
    if (l == r) {
        st[rt] += val;
        return;
    }
    int mid = getMid(l, r);
    if (pos <= mid) update(rt << 1, l, mid, pos, val);
    else update(rt << 1 | 1, mid + 1, r, pos, val);
    push_up(rt);
}

inline int query(int rt, int l, int r, int x, int y) {
    if (l == x && y == r) {
        return st[rt];
    }
    int mid = getMid(l, r);
    if (y <= mid) return query(rt << 1, l, mid, x, y);
    else if (x > mid) return query(rt << 1 | 1, mid + 1, r, x, y);
    else return query(rt << 1, l, mid, x, mid) + query(rt << 1 | 1, mid + 1, r, mid + 1, y);
}

int main() {
    scanf("%d", &n);
    int Max = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        a[i] = x;
        Max = max(Max, x);
        res1[i] += query(1, 1, N, a[i] + 1, N);
        update(1, 1, N, a[i], 1);
    }
    ll ans = 0;
    memset(st, 0, sizeof(st));
    Max = 0;
    for (int i = n; i > 0; i--) {
        Max = max(Max, a[i]);
        res2[i] += query(1, 0, N, 0, a[i] - 1);
        update(1, 1, N, a[i], 1);
        ans += ll(res1[i] * res2[i]);
    }
    printf("%lld\n", ans);
    return 0;
}
