/*
 * Author: Andy Zhu
 * @date    2021-10-29 13:13:09
 * @version 1.0.0
 */

//include
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 10;
int n, a[N], dp[2][200][4];

signed main(){
    cin>>n;
    for(int i = 1;i<=n;++i) cin>>a[i];
    int ans = 0;
    for(int i = 1;i<=n;++i) {
        ans += dp[i & 1 ^ 1][a[i]][3];
        dp[i & 1][a[i]][1] = 1;
        for(int k = 1;k<=3;++k) {
            for(int j = 1;j <= 100;++j) {
                dp[i & 1][j][k] += dp[i & 1 ^ 1][j][k];
                if(j >= a[i]) dp[i & 1][j][k] += dp[i & 1 ^ 1][j - a[i]][k - 1];
            }
        }
        memset(dp[i & 1 ^ 1], 0, sizeof(dp[i & 1 ^ 1]));
    }
    cout<<ans<<'\n';
}
