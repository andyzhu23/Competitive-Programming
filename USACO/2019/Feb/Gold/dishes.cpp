#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, a[N], b[N];
vector<int> stk[N];

int Find(int x, int l, int r) {
    int ans = -2;
    while(l <= r) {
        int mid = l + r >> 1;
        if(stk[mid].empty() || stk[mid][0] < x) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return ans;
}

bool ok(int x) {
    for(int i = 0;i<=x + 1;++i) stk[i].clear();
    for(int i = 1;i<=x;++i) b[i] = a[i];
    sort(b + 1, b + x + 1);
    int p = 1, l = 1, r = 0;
    for(int i = 1;i<=x;++i) {
        while(!stk[l].empty() && stk[l].back() == b[p]) {
            stk[l].pop_back();
            if(stk[l].empty()) ++l;
            ++p;
        }
        bool flag = 1;
        if(a[i] == b[p]) {
            ++p;
            continue;
        }
        int j = -1;
        if(r > 0) j = Find(a[i], l - 1, r) + 1;
        if(j != -1) {
            stk[j].push_back(a[i]);
            if(j == r + 1) ++r;
            flag = 0;
        }
        if(flag && (stk[r].empty() || stk[r][0] < a[i])) {
            stk[++r].push_back(a[i]);
            flag = 0;
        }
        if(flag) return 0;
    }
    while(!stk[l].empty() && stk[l].back() == b[p]) {
        stk[l].pop_back();
        if(stk[l].empty()) ++l;
        ++p;
    }
    if(p != x + 1) return 0;
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("dishes.in", "r", stdin);
    freopen("dishes.out", "w", stdout);
    cin>>n;
    for(int i = 1;i<=n;++i) cin>>a[i];
    int l = 1, r = n, ans = 0;
    while(l <= r) {
        int mid = l + r >> 1;
        if(ok(mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    cout<<ans<<'\n';
    return 0;
}
