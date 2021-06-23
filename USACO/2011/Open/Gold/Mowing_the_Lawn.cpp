#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ll = long long;

const int N = 1e5 + 10;

ll dp[N][2], a[N], sum[N];
int n, k;
deque<int> dq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i = 1;i<=n;i++) {
        cin>>a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    dq.push_back(0);
    for(int i = 1;i<=n;i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        if(dq.empty()) dp[i][1] = sum[i];
        else dp[i][1] = dp[dq.front()][0] - sum[dq.front()] + sum[i];
        while(!dq.empty() && dp[dq.back()][0] - sum[dq.back()] < dp[i][0] - sum[i]) dq.pop_back();
        if(!dq.empty() && dq.front() <= i - k) dq.pop_front();
        dq.push_back(i);
    }
    cout<<max(dp[n][0], dp[n][1])<<endl;
    return 0;
}
