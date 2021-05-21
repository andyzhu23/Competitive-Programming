#include <iostream>
#define endl "\n"
using namespace std;
const int N = 1e5 + 10;
int n, m, st[N << 2][21], power[21];
bool lazy[N << 2][21];

inline int fast_pow(int a, int b) {
    if (b == 1) return a;
    else if (b == 0) return 1;
    int tmp = fast_pow(a, b / 2);
    if (b % 2) return tmp * tmp * a;
    else return tmp * tmp;
}

inline void push_up(int rt) {
    for (int i = 1; i <= 20; i++) {
        st[rt][i] = st[rt << 1][i] + st[rt << 1 | 1][i];
    }
}

inline void push_down(int rt, int l, int r, int mid) {
    for (int i = 1; i <= 20; i++) {
        if (lazy[rt][i]) {
            st[rt << 1][i] = mid - l + 1 - st[rt << 1][i];
            st[rt << 1 | 1][i] = r - mid - st[rt << 1 | 1][i];
            lazy[rt << 1][i] ^= lazy[rt][i];
            lazy[rt << 1 | 1][i] ^= lazy[rt][i];
            lazy[rt][i] = 0;
        }

    }
}

inline void build(int rt, int l, int r) {
    if (l == r) {
        int a;
        cin >> a;
        int cnt = 0;
        while (a > 0) {
            st[rt][++cnt] = a % 2;
            a /= 2;
        }
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    push_up(rt);
}

inline void update(int rt, int l, int r, int x, int y, int val[]) {
    if (l == x && y == r) {
        for (int i = 1; i <= 20; i++) {
            if (val[i]) {
                st[rt][i] = r - l + 1 - st[rt][i];
            }
            if (val[i]) lazy[rt][i] = !lazy[rt][i];
        }
        return;
    }
    int mid = (l + r) >> 1;
    push_down(rt, l, r, mid);
    if (y <= mid) update(rt << 1, l, mid, x, y, val);
    else if (x > mid) update(rt << 1 | 1, mid + 1, r, x, y, val);
    else update(rt << 1, l, mid, x, mid, val), update(rt << 1 | 1, mid + 1, r, mid + 1, y, val);
    push_up(rt);
}

inline int query(int rt, int l, int r, int x, int y) {
    if (l == x && y == r) {
        int ans = 0;
        for (int i = 1; i <= 20; i++) {
            ans += st[rt][i] * power[i];
        }
        return ans;
    }
    int mid = (l + r) >> 1;
    push_down(rt, l, r, mid);
    if (y <= mid) return query(rt << 1, l, mid, x, y);
    else if (x > mid) return query(rt << 1 | 1, mid + 1, r, x, y);
    else return query(rt << 1, l, mid, x, mid) + query(rt << 1 | 1, mid + 1, r, mid + 1, y);
}

inline void solve() {
    int opt, l, r, val;
    cin >> opt >> l >> r;
    if (opt == 1) {
        cout << query(1, 1, n, l, r) << endl;
    } else {
        cin >> val;
        int v[21] = {0}, cnt = 0;
        while (val > 0) {
            v[++cnt] = val % 2;
            val /= 2;
        }
        update(1, 1, n, l, r, v);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    power[1] = 1;
    for (int i = 2; i <= 20; i++)
        power[i] = power[i - 1] * 2;
    cin >> n >> m;
    build(1, 1, n);
    while (m--) {
        solve();
    }
    return 0;
}
