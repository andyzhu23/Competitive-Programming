#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int inf = 0x3f3f3f3f;
using ll = long long;

int n, m, q, a[N], b[N];

struct sparse_table {
    int mn[N][22], mx[N][22], n;
    void init(vector<int>& a, int N) {
        n = N;
        for(int i = 1;i<=n;++i) mn[i][0] = mx[i][0] = a[i];
        for(int j = 1;(1 << j) <= n;++j) {
            for(int i = 1;i + (1 << j) - 1 <=n;++i) {
                mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
                mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int qmx(int l, int r) {
        int len = log2(r - l + 1);
        return max(mx[l][len], mx[r - (1 << len) + 1][len]);
    }
    int qmn(int l, int r) {
        int len = log2(r - l + 1);
        return min(mn[l][len], mn[r - (1 << len) + 1][len]);
    }
} st1, st2, st3, st4, st5, st6;

int psa[N], psb[N];

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>m>>q;
    vector<int> tmp(n + 5);
    for(int i = 1;i<=n;++i) {
        cin>>a[i];
        tmp[i] = a[i];
        psa[i] = psa[i - 1] + (a[i] == 0);
    }
    st1.init(tmp, n);
    for(int i = 1;i<=n;++i) tmp[i] = a[i] >= 0 ? -inf : a[i];
    st2.init(tmp, n);
    for(int i = 1;i<=n;++i) tmp[i] = a[i] <= 0 ? inf : a[i];
    st3.init(tmp, n);
    for(int i = 1;i<=m;++i) {
        cin>>b[i];
        tmp[i] = b[i];
        psb[i] = psb[i - 1] + (b[i] == 0);
    }
    st4.init(tmp, n);
    for(int i = 1;i<=n;++i) tmp[i] = b[i] >= 0 ? -inf : b[i];
    st5.init(tmp, n);
    for(int i = 1;i<=n;++i) tmp[i] = b[i] <= 0 ? inf : b[i];
    st6.init(tmp, n);
    set<int> c1, c2;
    while(q--) {
        c1.clear(), c2.clear();
        int l1, r1, l2, r2, tmp;
        cin>>l1>>r1>>l2>>r2;
        c1.insert(st1.qmx(l1, r1));
        c1.insert(st1.qmn(l1, r1));
        tmp = st2.qmx(l1, r1);
        if(tmp != -inf) c1.insert(tmp);
        tmp = st3.qmn(l1, r1);
        if(tmp != inf) c1.insert(tmp);
        if(psa[r1] - psa[l1 - 1] > 0) c1.insert(0);

        c2.insert(st4.qmx(l2, r2));
        c2.insert(st4.qmn(l2, r2));
        tmp = st5.qmx(l2, r2);
        if(tmp != -inf) c2.insert(tmp);
        tmp = st6.qmn(l2, r2);
        if(tmp != inf) c2.insert(tmp);
        if(psb[r2] - psb[l2 - 1] > 0) c2.insert(0);

        ll ans = -1ll * inf * inf;
        for(auto x : c1) {
            ll ret = 1ll * inf * inf;
            for(auto y : c2) {
                ret = min(ret, 1ll * x * y);
            }
            ans = max(ans, ret);
        }
        cout<<ans<<'\n';
    }
    return 0;
}