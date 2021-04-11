#include <iostream>
#define endl "\n"
using namespace std;
const int N = 1e6 + 10;
bool lazy[N << 2];
string s;

struct node {
    int four, seven, decrease, increase;
} st[N << 2];

inline void push_up(int rt) {
    st[rt].four = st[rt << 1].four + st[rt << 1 | 1].four;
    st[rt].seven = st[rt << 1].seven + st[rt << 1 | 1].seven;
    st[rt].increase = max(st[rt << 1].increase + st[rt << 1 | 1].seven, st[rt << 1].four + st[rt << 1 | 1].increase);
    st[rt].decrease = max(st[rt << 1].decrease + st[rt << 1 | 1].four, st[rt << 1].seven + st[rt << 1 | 1].decrease);
}

inline void push_down(int rt) {
    if (!lazy[rt]) return;
    lazy[rt << 1] = !lazy[rt << 1];
    lazy[rt << 1 | 1] = !lazy[rt << 1 | 1];
    swap(st[rt << 1].increase, st[rt << 1].decrease);
    swap(st[rt << 1 | 1].increase, st[rt << 1 | 1].decrease);
    swap(st[rt << 1].four, st[rt << 1].seven);
    swap(st[rt << 1 | 1].four, st[rt << 1 | 1].seven);
    lazy[rt] = false;
}

inline void build(int rt, int l, int r) {
    if (l == r) {
        st[rt].decrease = st[rt].increase = 1;
        if (s[l - 1] == '7') {
            st[rt].seven++;
        } else {
            st[rt].four++;
        }
        return;
    }
    int mid = (l + r) >> 1;
    push_down(rt);
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    push_up(rt);
}

inline void update(int rt, int l, int r, int x, int y) {
    if (l == x && y == r) {
        swap(st[rt].decrease, st[rt].increase);
        swap(st[rt].seven, st[rt].four);
        lazy[rt] = !lazy[rt];
        return;
    }
    int mid = (l + r) >> 1;
    push_down(rt);
    if (y <= mid) update(rt << 1, l, mid, x, y);
    else if (x > mid) update(rt << 1 | 1, mid + 1, r, x, y);
    else update(rt << 1, l, mid, x, mid), update(rt << 1 | 1, mid + 1, r, mid + 1, y);
    push_up(rt);
}

int n, m;

inline void solve() {
    string opt;
    cin >> opt;
    if (opt == "count") {
        cout << st[1].increase << endl;
    } else {
        int x, y;
        cin >> x >> y;
        update(1, 1, n, x, y);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    cin >> s;
    build(1, 1, n);
    while (m--) {
        solve();
    }
    return 0;
}
