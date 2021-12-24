#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#define pb push_back
#define all(v) v.begin(), v.end()
stack<int> stk;
int a[N], last[N], p[N], n, act[N];
vector<int> low;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    for(int i = 1;i<=n;++i) {
        cin>>a[i];
        p[a[i]] = i;
    }
    for(int i = n;i;--i) {
        while(!stk.empty() && stk.top() > p[i]) stk.pop();
        last[p[i]] = stk.empty() ? -1 : stk.top();
        stk.push(p[i]);
    }
    int ans = 0;
    cout<<ans<<'\n';
    for(int i = 1;i<=n;++i) {
        // erase low after current position
        while(!low.empty() && low.back() > p[i]) {
            ans -= act[low.back()];
            act[low.back()] = 0;
            low.pop_back();
        }
        // check current position
        act[p[i]] = last[p[i]] != -1 && (low.empty() || last[p[i]] != last[low.back()]);
        ans += act[p[i]];
        low.pb(p[i]);
        cout<<ans<<'\n';
    }
    return 0;
}
