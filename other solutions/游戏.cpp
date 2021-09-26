#include <bits/stdc++.h>
using namespace std;
#define pb push_back
using ll = long long;
int n;
const int N = 1e4 + 10;
bool np[100001] = {0};
vector<ll> p;
ll dp[N][2001]; // add together is n, using only first p prime numbers

void seive() {
    np[1] = 1;
    for(int i = 2;i<=n;++i) {
        if(np[i]) continue;
        p.pb(i);
        for(int j = i + i;j<=n;j += i) np[j] = 1;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    seive();
    for(int i = 0;i<=n;++i) dp[i][0] = 1;
    for(int j = 0;j<p.size();++j) {
        for(int i = 0;i<=n;++i) {
            dp[i][j + 1] = dp[i][j];
            for(ll k = p[j];k <= i; k *= p[j]) 
                dp[i][j + 1] = dp[i][j + 1] + dp[i - k][j];
        }
    }
    cout<<dp[n][p.size()]<<'\n';
    return 0;
}
