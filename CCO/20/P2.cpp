#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, a[N], b[N], ret[N];
set<int> bst;

int c[N];

void update(int a, int b) {
    for(int i = a;i<=n;i+=i&(-i)) c[i] += b;
}

int query(int a) {
    int ans = 0;
    for(int i = a;i;i-=i&(-i)) ans += c[i];
    return ans;
}

int query(int a, int b) {
    return query(b) - query(a - 1);
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    for(int i = 1;i<=n;++i) cin>>a[i], b[i] = a[i];
    sort(b + 1, b + n + 1);
    for(int i = 1;i<=n;++i) if(b[i] < i) {
        cout<<-1<<'\n';
        return 0;
    }
    for(int i = 1;i<=n;++i) bst.insert(i);
    for(int i = n;i;--i) {
        int x = *prev(bst.upper_bound(a[i]));
        bst.erase(x);
        ret[x] = i;
    }
    long long ans = 0;
    for(int i = 1;i<=n;++i) {
        ans += query(ret[i], n);
        update(ret[i], 1);
    }
    cout<<ans<<'\n';
    return 0;
}
