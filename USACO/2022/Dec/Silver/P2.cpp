#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 5e6 + 5;
struct node {
    int u, v;
    bool operator<(const node& other) const {
        return u / 2 == other.u / 2 ? v < other.v : u / 2 < other.u / 2;
    }
};
bitset<N> np;
int dp[N], last[4];

int n, a[N];

void solve() {
    cin>>n;
    node john = {inf, inf}, nhoj = {inf, inf};
    for(int i = 1;i<=n;++i) cin>>a[i];
    for(int i = 1;i<=n;++i) {
        if(a[i] % 4) john = min(john, {dp[a[i]], i});
        else nhoj = min(nhoj, {dp[a[i]], i});
    }
    puts(john < nhoj ? "Farmer John" : "Farmer Nhoj");
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    last[1] = 1;
    dp[1] = 1;
    for(int i = 2;i<N;++i) {
        if(!np[i]) {
            last[i % 4] = i;
            for(int j = i + i;j<N;j+=i) np[j] = 1;
        }
        if(i & 1) dp[i] = (i - last[i % 4]) / 2 + 1;
        else dp[i] = i / 2;
    }
    int t; cin>>t;
    while(t--) solve();
    return 0;
}