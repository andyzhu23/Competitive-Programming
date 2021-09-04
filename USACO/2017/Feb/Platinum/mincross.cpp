#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, a[N], b[N], x[N], y[N];
using ll = long long;

template<typename T>
struct fenwick {
    T c[N] = {0};
    #define lowbit(x) (x & (-x))
    void update(int a, T b) {
        for(int i = a;i<=n;i+=lowbit(i)) c[i] += b;
    }
    T query(int a) {
        T ans = 0;
        for(int i = a;i;i-=lowbit(i)) ans += c[i];
        return ans;
    }
};

fenwick<ll> st, st2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("mincross.in", "r", stdin);
    freopen("mincross.out", "w", stdout);
    cin>>n;
    for(int i = 1;i<=n;i++) {
        cin>>a[i];
        x[a[i]] = i;
    }
    for(int j = 1;j<=n;j++) {
        cin>>b[j];
        y[b[j]] = j;
    }
    // shift a
    ll tot = 0;
    for(int i = 1;i<=n;i++) {
        tot += st.query(n) - st.query(y[a[i]]);
        st.update(y[a[i]], 1);
    }
    ll ans = tot;
    for(int i = n;i>0;i--) {
        tot += y[a[i]] * 2 - n - 1;
        ans = min(tot, ans);
    }
    // shift b
    tot = 0;
    for(int i = 1;i<=n;i++) {
        tot += st2.query(n) - st2.query(x[b[i]]);
        st2.update(x[b[i]], 1);
    }
    ans = min(tot, ans);
    for(int i = n;i>0;i--) {
        tot += x[b[i]] * 2 - n - 1;
        ans = min(tot, ans);
    }
    cout<<ans<<'\n';
    return 0;
}
/*
remember to shift both a and b as results are different
*/
