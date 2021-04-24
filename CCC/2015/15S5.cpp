#include <iostream>
#include <algorithm>
#define endl "\n"
using namespace std;
const int N = 3e3 + 10;
const int M = 110;
int dp[N][M][M][2];
// dp[i][j][k][1/2]
// the first i in a
// the first j in b
// the last k in b
// whether or not you took the current one: 1 means take, 0 means not take
int n, m, a[N], b[M];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 1;i<=n;i++) cin>>a[i];
    cin>>m;
    for(int i = 1;i<=m;i++) cin>>b[i];
    sort(b + 1, b + m + 1);
    int ans = 0;
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=m;j++){
            for(int k = 0;k<=m;k++){
                if(k + j > m) continue;
                // you can either just use the result from i - 1
                // or using the jth pie to block and the kth pie to increase the maximum
                if(i == 0 && k != 0){
                    dp[i][j][k][1] = dp[i][j][k - 1][0] + b[m - k + 1];
                    continue;
                } else if(i == 0) continue;
                if(k != 0)
                    dp[i][j][k][1] = max(dp[i][j][k][1], max(dp[i - 1][j][k][0] + a[i], dp[i][j][k - 1][0] + b[m - k + 1]));
                else dp[i][j][k][1] = dp[i - 1][j][k][0] + a[i];
                if(j != 0) {
                    dp[i][j][k][0] = max(dp[i][j][k][0], max(dp[i - 1][j][k][0], dp[i][j - 1][k][0]));
                    dp[i][j][k][0] = max(dp[i][j][k][0], max(dp[i - 1][j][k][1], dp[i][j - 1][k][1]));
                } else dp[i][j][k][0] = max(dp[i][j][k][0], max(dp[i - 1][j][k][1], dp[i - 1][j][k][0]));
                ans = max(ans, max(dp[i][j][k][1], dp[i][j][k][0]));
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
