/*
 * for this question, something that we have to understand is that if a price of something increase over the period
 * of two days, then we will buy it no matter what. So now if all n items all increased the price, then we can choose which
 * ones to buy to make the best price. We can use complete knapsack. The difference between the price is your value, the
 * original price is your volume and the money you have is the total capacity.
 */

#include <iostream>
#define int long long
using namespace std;
const int N = 1e3 + 10;
const int V = 1e6 + 10;
int t, n, m, a[N][N], c, w, dp[V], ans;

void completeKnapsack(){
    if(ans < c) return;
    for(int i = c;i<=ans;i++){
        dp[i] = max(dp[i], dp[i - c] + w);
    }
}

signed main(){
    cin>>t>>n>>m;
    ans = m;
    for(int i = 1;i<=t;i++){
        for(int j = 1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i = 1;i<t;i++){
        for(int j =1;j<=ans;j++) dp[j] = 0;
        for(int j = 1;j<=n;j++){
            c = a[i][j];
            w = a[i + 1][j] - c;
            if(w <= 0 || ans < c) continue;

            completeKnapsack();
        }
        ans+=dp[ans];
    }
    cout<<ans<<endl;
    return 0;
}
