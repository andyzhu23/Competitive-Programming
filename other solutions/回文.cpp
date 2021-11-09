#include <bits/stdc++.h>
using namespace std;
#define pb push_back

bool in(int l, int r, int p) {
    return p >= l && p <= r;
}

string cal(int l, int r, int n, vector<int>& partner, vector<bool> mark, vector<int>& res, vector<int>& a) {
    string ans = "";
    while(r - l + 1 > n) {
        int p = partner[l];
        if(in(l, r, p) && (mark[p - 1] || mark[p + 1])) {
            res.pb(a[l]);
            mark[p] = 1;
            l++;
            ans += 'L';
        } else {
            p = partner[r];
            if(in(l, r, p) && (mark[p - 1] || mark[p + 1])) {
                res.pb(a[r]);
                mark[p] = 1;
                r--;
                ans += 'R';
            }
            else {
                return "-1";
            }
        }
    }
    while(r >= l) {
        if(a[l] == res.back()) ans += 'L', res.pop_back(), l++;
        else if(a[r] == res.back()) ans += 'R', res.pop_back(), r--;
        else {
            return "-1";
        }
    }
    return ans;
}

void solve() {
    int n; cin>>n;
    vector<int> a(n * 2 + 10);
    for(int i = 1;i<=n * 2;++i) {
        cin>>a[i];
    }
    vector<int> partner(2 * n + 10), pos(n * 2 + 10);
    vector<bool> mark(n * 2 + 10);
    for(int i = 1;i<=2 * n;++i) {
        if(pos[a[i]]) {
            partner[pos[a[i]]] = i;
            partner[i] = pos[a[i]];
        } else pos[a[i]] = i;
    }
    int l = 1, r = n * 2;
    string ans = "";
    vector<int> res;
    mark[partner[l]] = 1;
    res.pb(a[l]);
    l++;
    ans = cal(l, r, n, partner, mark, res, a);
    if(ans != "-1") ans = 'L' + ans;
    if(ans == "-1") {
        mark[partner[l]] = 0;
        ans = "";
        res.clear();
        l--;
        mark[partner[r]] = 1;
        res.pb(a[r]);
        r--;
        ans = cal(l, r, n, partner, mark, res, a);
        if(ans != "-1") ans = 'R' + ans;
    }
    cout<<ans<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t; cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
