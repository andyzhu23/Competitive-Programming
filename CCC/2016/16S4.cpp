/*
 * Dynamic Programming
 */

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5e2;
int n;
long long dp[N][N],sum[N],ans; // dp[i][j] indicate the maximum possible size that can be reached from the subarray i to j
bool poss[N][N]; // poss[i][j] indicate whether it is possible for the subarray from i to j to combine

int main() {
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>dp[i][i];
        sum[i] = dp[i][i] + sum[i-1]; // pre-fix sum
    }

    for(int i = 1;i<=n;i++) poss[i][i] = true; // initializing

    for(int l = 2;l<=n;l++){ // l is length
        for(int i = 1;i<=n;i++){ // i is the left endpoint of the subarray
            int j = i+l-1; // calculate j which is the right endpoint
            if(j>n) continue;
            for(int k = i;k<j;k++){
                if(poss[i][k] && poss[k+1][j] && dp[i][k] == dp[k+1][j]){ // if the two adjacent points are equal
                    dp[i][j] = sum[j] - sum[i - 1];
                    poss[i][j] = true; // this subarray is possible to be combined
                } else if(k != i){
                    for(int u = i;u<k;u++){
                        if(poss[i][u] && poss[u+1][k] && poss[k+1][j] && dp[i][u] == dp[k+1][j]){
                            dp[i][j] = sum[j] - sum[i - 1];
                            poss[i][j] = true;
                        }
                    }
                }
            }
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = i;j<=n;j++){
            ans = max(dp[i][j],ans);
        }
    }
    cout<<ans;

    return 0;
}
