#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 1e6 + 5;
int a[N], n;
vector<int> stk;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    for(int i = 1;i<=n;++i) cin>>a[i];
    a[0] = INF, a[n + 1] = INF;
    stk.push_back(0);
    long long ans = 0;
    for(int i = 1;i<=n;++i) {
        while(a[stk.back()] < a[i]) stk.pop_back();
        ans += stk.back() == 0 ? 0 : i - stk.back() + 1;
        stk.push_back(i);
    }
    stk.clear();
    stk.push_back(n + 1);
    for(int i = n;i;--i) {
        while(a[stk.back()] < a[i]) stk.pop_back();
        ans += stk.back() == n + 1 ? 0 : stk.back() - i + 1;
        stk.push_back(i);
    }
    cout<<ans<<'\n';
    return 0;
}