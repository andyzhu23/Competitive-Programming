#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
#define int long long
using ll = long long;

struct node{ll x, y;} a[N], b[N];
int n, o = 1;

template<typename T> void ckmax(T& a, T b) {a = max(a, b);}

bool cross(node o, node a, node b) {
    return (b.y - o.y) * (a.x - o.x) <= (a.y - o.y) * (b.x - o.x);
}

bool cross2(node o, node a, node b) {
    return (b.y - o.y) * (a.x - o.x) == (a.y - o.y) * (b.x - o.x);
}

vector<int> stk;

ll len(node a, node b) {
    return (a.y - b.y) * (a.y - b.y) + (a.x - b.x) * (a.x - b.x);
}

ll ts(int lo, int hi, node x) {
    ll ret = max(len(b[lo], x), len(b[hi], x));
    while(lo <= hi) {
        int mid1 = lo + (hi - lo) / 3;
        int mid2 = lo + (hi - lo) / 3 * 2;
        ret = max({ret, len(b[mid1], x), len(b[mid2], x)});
        if(len(b[mid1], x) > len(b[mid2], x)) hi = mid2 - 1;
        else lo = mid1 + 1;
    }
    return ret;
}

bool cmp(node u, node v) {
    if(cross2(a[1], u, v)) return u.x < v.x;
    return cross(a[1], u, v);
}

signed main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    for(int i = 1;i<=n;++i) {
        int x, y;
        cin>>x>>y;
        a[i] = {x, y};
        if(a[o].y > a[i].y || (a[o].y == a[i].y && a[o].x > a[i].x)) o = i;
    }
    swap(a[1], a[o]);
    sort(a + 2, a + n + 1, cmp);
    for(int i = 1;i<=n;++i) {
        while(stk.size() >= 2 && !cross(a[stk[stk.size() - 2]], a[stk.back()], a[i])) stk.pop_back();
        stk.push_back(i);
    }
    int sz = 0;
    for(auto x : stk) b[++sz] = a[x];
    for(auto x : stk) b[++sz] = a[x];
    ll ans = 0;
    for(int i = 1;i<=stk.size();++i) ckmax(ans, ts(i, i + stk.size(), b[i]));
    cout<<ans<<'\n';
    return 0;
}
