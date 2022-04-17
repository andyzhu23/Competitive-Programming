#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e18;
const int Q = 5e6 + 5;
ll n, sum[Q << 2], mx[Q << 2], ans = 0;
int tot, lc[Q << 2], rc[Q << 2], root;

void pushup(int rt) {
    sum[rt] = sum[lc[rt]] + sum[rc[rt]];
    mx[rt] = max(mx[lc[rt]], mx[rc[rt]]);
}

void update(int& rt, ll l, ll r, ll pos, ll val) {
    if(!rt) rt = ++tot;
    if(l == r) {
        sum[rt] = mx[rt] = val;
        return;
    }
    ll mid = l + r >> 1;
    if(pos <= mid) update(lc[rt], l, mid, pos, val);
    else update(rc[rt], mid + 1, r, pos, val);
    pushup(rt);
}

ll qsum(int rt, ll l, ll r, ll x, ll y) {
    if(!rt) return 0;
    if(l == x && y == r) return sum[rt];
    ll mid = l + r >> 1;
    if(y <= mid) return qsum(lc[rt], l, mid, x, y);
    else if(x > mid) return qsum(rc[rt], mid + 1, r, x, y);
    else return qsum(lc[rt], l, mid, x, mid) + qsum(rc[rt], mid + 1, r, mid + 1, y);
}

ll qmx(int rt, ll l, ll r, ll x, ll y) {
    if(!rt) return 0;
    if(l == x && y == r) return mx[rt];
    ll mid = l + r >> 1;
    if(y <= mid) return qmx(lc[rt], l, mid, x, y);
    else if(x > mid) return qmx(rc[rt], mid + 1, r, x, y);
    else return max(qmx(lc[rt], l, mid, x, mid), qmx(rc[rt], mid + 1, r, mid + 1, y));
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int q;
    cin>>n>>q;
    while(q--) {
        char opt;
        ll a, b;
        cin>>opt>>a>>b;
        a ^= ans;
        b ^= ans;
        switch(opt) {
            case 'C': update(root, 1, N, a, b); break;
            case 'S': cout<<(ans = qsum(root, 1, N, a, b))<<'\n'; break;
            case 'M': cout<<(ans = qmx(root, 1, N, a, b))<<'\n'; break;
        }
    }
    return 0;
}