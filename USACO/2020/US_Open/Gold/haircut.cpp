#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
using ll = long long;

struct fenwick {
    int st[N];
    int lowbit(int x) {return x & (-x);}
    void update(int a, int b) {
        for(int i = a;i<N;i+=lowbit(i)) st[i] += b;
    }
    int query(int a) {
        int ans = 0;
        for(int i = a;i;i-=lowbit(i)) ans += st[i];
        return ans;
    }
    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
} st;

int n, a[N], b[N];

int main() {
    // freopen("haircut.in", "r", stdin);
    // freopen("haircut.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 1;i<=n;i++) {
        int x; cin>>x;
        ++x;
        a[x] += st.query(x + 1, N - 1);
        st.update(x, 1);
    }
    ll ans = 0;
    for(int i = 1;i<=n;i++) {
        cout<<ans<<'\n';
        ans += a[i];
    }
    return 0;
}
