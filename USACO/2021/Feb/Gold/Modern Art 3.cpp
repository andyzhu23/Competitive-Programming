/*
 * Very very standard DP, if a[i] and a[j] is equal, then the number of brushes of dp[i][j] is the same as 
 * dp[i][j - 1]
 * 
 */



#include <iostream>
#define read for(int i = 1;i<=n;i++) cin>>a[i];
using namespace std;
const int N = 3e2 + 10;
int n,a[N],dp[N][N];
int main(){
    cin>>n;
    read;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            dp[i][j] = j - i + 1;
        }
    }
    for(int l = 2;l<=n;l++){
        for(int i = 1;i<=n;i++){
            int j = l + i - 1;
            if(j > n) continue;
            if(a[i] == a[j]) dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]);
            for(int k = i;k<j;k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}
