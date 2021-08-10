#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define lc rt << 1
#define rc rt << 1 | 1
#define ALL(v) v.begin(), v.end()
#define lb lower_bound
#define ub upper_bound
using pii = pair<int, int>;
template <typename T> using vec = vector<T>;
using vi = vec<int>;
const int N = 2e5 + 10;

struct seg {
    vi st[N << 2];
    void push_up(int rt) {
        for(int i : st[lc]) st[rt].pb(i);
        for(int i : st[rc]) st[rt].pb(i);
        sort(ALL(st[rt]));
    }
    void build(int rt, int l, int r, pii b[N]) {
        if(l == r) {
            st[rt].pb(b[l].sec);
            return;
        }
        int mid = (l + r) >> 1;

        build(lc, l, mid, b);
        build(rc, mid + 1, r, b);
        push_up(rt);
    }
    int query(int rt, int l, int r, int x, int y, int k) {
        if(l == r) return st[rt][0];
        // elements in between x and y
        int p = ub(ALL(st[lc]), y) - lb(ALL(st[lc]), x);
        int mid = (l + r) >> 1;
        return p >= k ? query(lc, l, mid, x, y, k) : query(rc, mid + 1, r, x, y, k - p);
    }
} st;

int n, q, a[N];
pii b[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for(int i = 1;i<=n;i++) {
        cin>>a[i];
        b[i] = mp(a[i], i);
    }
    sort(b + 1, b + n + 1);
    st.build(1, 1, n, b);
    int ans = 0;
    while(q--) {
        int l, r, k;
        cin>>l>>r>>k;
        l ^= ans;
        r ^= ans;
        k ^= ans;
        ans = a[st.query(1, 1, n, l, r, k)];
        cout<<ans<<'\n';
    }
    return 0;
}
