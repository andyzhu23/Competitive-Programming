/*
 * use a segment tree to store the frequency of an element. Then run it twice both front and back to determine the answer.
 * Note that we cannot initialize an array length of 1e9 so we have to use discretization
 */

#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <algorithm>
#include <memory.h>
#define push_up(rt) st[rt] = st[rt << 1] + st[rt << 1 | 1]
#define getMid(l, r) (l + r) >> 1
#define endl "\n"
#define read(s) freopen(s, "r", stdin)
#define write(s) freopen(s, "w", stdout)
using namespace std;
typedef long long ll;
typedef unordered_map<int, int> UMI;
const int N = 1e5 + 10;
UMI Map;
int st[N << 2] = {1};
int n, a[N], res1[N], res2[N], b[N];

inline void readFile() {
    read("bphoto.in");
    write("bphoto.out");
}

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
    if (mid < x) return query(rt << 1 | 1, mid + 1, r, x, y);
    return query(rt << 1, l, mid, x, mid) + query(rt << 1 | 1, mid + 1, r, mid + 1, y);
}

int main() {
    readFile();
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        a[i] = b[i] = x;
    }
    // discretization
    sort(b + 1, b + n + 1);
    int len = 0;
    for (int i = 1; i <= n; i++) {
        if (Map[b[i]] == 0) Map[b[i]] = ++len;
    }
    // number of taller cows on the left
    for (int i = 1; i <= n; i++) {
        int x = Map[a[i]];
        res1[i] = query(1, 1, n + 1, x + 1, n + 1);
        update(1, 1, n, x, 1);
    }
    // clear the tree for reuse
    memset(st, 0, sizeof(st));
    // number of taller cows on the right
    for (int i = n; i > 0; i--) {
        int x = Map[a[i]];
        res2[i] = query(1, 1, n + 1, x + 1, n + 1);
        update(1, 1, n, x, 1);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += max(res1[i], res2[i]) > min(res1[i], res2[i]) << 1;
    }
    cout << ans << endl;
    return 0;
}
