#include <bits/stdc++.h>
using namespace std;
#define last(v) v[v.size() - 1]
#define lc rt << 1
#define rc rt << 1 | 1
#define pb push_back
using ll = long long;

const int N = 3e5 + 10;
int cnt, n, q;

template <typename T> struct seg {
    vector<int> t[N << 2];
    vector<T> st[N << 2];

    inline int bs(vector<int>& vec, int x) {
        int l = 0, r = vec.size() - 1, ans = 0;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(vec[mid] <= x) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        return ans;
    }

    inline void push_up(int rt, int dir, int val) {
        if(!dir) {
            t[rt].pb(last(t[lc]));
            st[rt].pb(last(st[rt]) + val);
        } else {
            t[rt].pb(last(t[rc]));
            st[rt].pb(last(st[rt]) + val);
        }
    }

    inline void init(int rt, int l, int r) {
        t[rt].pb(0);
        st[rt].pb(0);
        if(l == r) return;
        int mid = (l + r) >> 1;
        init(lc, l, mid);
        init(rc, mid + 1, r);
    }

    inline void update(int rt, int l, int r, int pos, int val) {
        if(l == r) {
            t[rt].pb(cnt);
            st[rt].pb(val + last(st[rt]));
            return;
        }
        int mid = (l + r) >> 1;
        bool dir;
        if(pos <= mid) {
            dir = 0;
            update(lc, l, mid, pos, val);
        }
        else {
            dir = 1;
            update(rc, mid + 1, r, pos, val);
        }
        push_up(rt, dir, val);
    }

    inline T query(int rt, int l, int r, int x, int y, int tim) {
        if(l == x && y == r) return st[rt][bs(t[rt], tim)];
        int mid = (l + r) >> 1;
        if(y <= mid) return query(lc, l, mid, x, y, tim);
        else if(x > mid) return query(rc, mid + 1, r, x, y, tim);
        else return query(lc, l, mid, x, mid, tim) + query(rc, mid + 1, r, mid + 1, y, tim);
    }
};
seg <ll> st;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    st.init(1, 1, n);
    ll ans = 0;
    while(q--) {
        int opt; cin>>opt;
        if(opt == 1) {
            ll i, v; 
            cin>>i>>v;
            i ^= ans;
            v ^= ans;
            ++cnt;
            st.update(1, 1, n, i, v);
        } else {
            ll l, r, x; cin>>l>>r>>x;
            l ^= ans;
            r ^= ans;
            x ^= ans;
            ans = st.query(1, 1, n, l, r, cnt - x);
            cout<<ans<<'\n';
        }
    }
    return 0;
}
