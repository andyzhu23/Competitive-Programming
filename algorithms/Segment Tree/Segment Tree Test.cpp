/*
 * Everything else standard segment tree. For Q, build a segment tree that find the number of G in l and r.
 * Everything else with this tree is standard, when push_up, you want to update how many G is in l and r. I did
 * it by using the standard segment tree way of splitting it in half, and check if the gcd is the same, if it is,
 * I use the value, and if it is not, I further down break the tree until it reaches the leaf node.
 * 
 * make sure to put inline in front of every method as it makes calling method a little quicker which was actually
 * able to make me pass case 12
 */


#include <bits/stdc++.h>
#define endl "\n"
#define f first
#define s second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef map<int, int> mi;
typedef unordered_map<int, int> umi;
typedef unordered_set<int> usi;
typedef set<int> si;
typedef queue<int> qi;
typedef queue<pi> qii;
typedef stack<int> stki;
typedef stack<pi> stkii;
typedef priority_queue<int> pqi;
typedef priority_queue<pi> pqii;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
int Min[N << 2], gcd[N << 2], getG[N << 2];
int n, m, a[N];

inline int getMid(int l, int r) {
    return (l + r) >> 1;
}

inline int getGCD(int x, int y) {
    if (y == 0) return x;
    return getGCD(y, x % y);
}

inline void push_up_getG(int pos, int rt, int l, int r, int mid, int val) {
    if (gcd[rt] == val && pos != rt) {
        getG[pos] += getG[rt];
        return;
    }
    if(l == r) return;
    if (rt == pos) getG[pos] = 0;
    push_up_getG(pos, rt << 1, l, mid, getMid(l, mid), val);
    push_up_getG(pos, rt << 1 | 1, mid + 1, r, getMid(mid + 1, r), val);
}

inline void push_up_Min(int rt) {
    Min[rt] = min(Min[rt << 1], Min[rt << 1 | 1]);
}

inline void push_up_GCD(int rt) {
    gcd[rt] = getGCD(gcd[rt << 1], gcd[rt << 1 | 1]);
}

inline void build(int rt, int l, int r) {
    if (l == r) {
        Min[rt] = a[l];
        gcd[rt] = a[l];
        getG[rt] = 1;
        return;
    }
    int mid = getMid(l, r);
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    push_up_Min(rt);
    push_up_GCD(rt);
    push_up_getG(rt, rt, l, r, mid, gcd[rt]);
}

inline void update(int rt, int l, int r, int pos, int val) {
    if (l == r && l == pos) {
        Min[rt] = val;
        gcd[rt] = val;
        return;
    }
    int mid = getMid(l, r);
    if (pos <= mid) update(rt << 1, l, mid, pos, val);
    else update(rt << 1 | 1, mid + 1, r, pos, val);
    push_up_GCD(rt);
    push_up_Min(rt);
    push_up_getG(rt, rt, l, r, mid, gcd[rt]);
}

inline int queryMin(int rt, int l, int r, int x, int y) {
    if (l == x && y == r) {
        return Min[rt];
    }
    int mid = getMid(l, r);
    if (y <= mid) return queryMin(rt << 1, l, mid, x, y);
    else if (mid < x) return queryMin(rt << 1 | 1, mid + 1, r, x, y);
    else return min(queryMin(rt << 1, l, mid, x, mid), queryMin(rt << 1 | 1, mid + 1, r, mid + 1, y));
}

inline int queryGCD(int rt, int l, int r, int x, int y) {
    if (l == x && y == r) {
        return gcd[rt];
    }
    int mid = getMid(l, r);
    if (y <= mid) return queryGCD(rt << 1, l, mid, x, y);
    else if (mid < x) return queryGCD(rt << 1 | 1, mid + 1, r, x, y);
    else return getGCD(queryGCD(rt << 1, l, mid, x, mid), queryGCD(rt << 1 | 1, mid + 1, r, mid + 1, y));
}

inline int queryGetG(int rt, int l, int r, int x, int y, int val) {
    if (x <= l && r <= y) {
        if (l == r) {
            if (a[l] == val) return 1;
            else return 0;
        }
        if (gcd[rt] == val) return getG[rt];
    }
    int mid = getMid(l, r);
    if (y <= mid) return queryGetG(rt << 1, l, mid, x, y, val);
    else if (mid < x) return queryGetG(rt << 1 | 1, mid + 1, r, x, y, val);
    else return queryGetG(rt << 1, l, mid, x, mid, val) + queryGetG(rt << 1 | 1, mid + 1, r, mid + 1, y, val);
}

inline void solve() {
    char c;
    int x, y;
    scanf(" %c %d %d", &c, &x, &y);
    if (c == 'C') {
        a[x] = y;
        update(1, 1, n, x, y);
    } else if (c == 'M') printf("%d\n", queryMin(1, 1, n, x, y));
    else if (c == 'G') printf("%d\n", queryGCD(1, 1, n, x, y));
    else if (c == 'Q') printf("%d\n", queryGetG(1, 1, n, x, y, queryGCD(1, 1, n, x, y)));

}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        a[i] = x;
    }
    build(1, 1, n);
    while (m--) {
        solve();
    }
    return 0;
}
