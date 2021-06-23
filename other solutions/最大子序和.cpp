#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define f first
#define s second
using vi = vector<int>;
using pii = pair<int, int>;
deque<pii> dq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, ans = 0;
    cin>>n>>m;
    vi a(n + 1), dp(n + 1), sum(n + 1); // dp[i] means the maximum end and include at position i
    for(int i = 1;i<=n;i++) {
        cin>>a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    dq.push_back(mp(0, 0));
    for(int i = 1;i<=n;i++) {
        while(!dq.empty() && dq.back().f >= sum[i]) dq.pop_back();
        dq.push_back(mp(sum[i], i));
        dp[i] += sum[i] - dq.front().f;
        ans = max(dp[i], ans);
        if(dq.front().s <= i - m) dq.pop_front();
    }
    cout<<ans<<endl;
    return 0;
}
