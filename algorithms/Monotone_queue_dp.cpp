#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pf push_front
#define f first
#define s second
#define mp make_pair

using pii = pair<int, int>;

const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
int dp[N], n, m;
deque<pii> dq;

int main(){
    cin>>n>>m;
    int ans = INF;
    for(int i = 1;i<=n;i++) cin>>dp[i];
    for(int i = 1;i<=n;i++) {
        if(i > m) dp[i] += dq.front().first;
        while(!dq.empty() && dq.back().f > dp[i]) 
            dq.pop_back();
        dq.pb(mp(dp[i], i));
        
        if(i > n - m) ans = min(ans, dp[i]); 
        if(!dq.empty() && dq.front().second <= i - m)
            dq.pop_front();
    }
    cout<<ans<<endl;
    return 0;
}
