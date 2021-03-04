#include <iostream>
using namespace std;
const int N = 1e3+10;
const int INF = 1e9;
string a,b;
int dp[N][N];
int main() {
    cin>>a>>b;
    int len1 = a.size();
    int len2 = b.size();
    for(int i = 0;i<=len1;i++){
        for(int j = 0;j<=len2;j++){
            dp[i][j] = INF;
        }
    }

    for(int i = 0;i<=1000;i++){
        dp[0][i] = dp[i][0] = i;
    }

    for(int i = 1;i<=len1;i++){
        for(int j = 1;j<=len2;j++){
            if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min(dp[i-1][j-1]+1, min(dp[i-1][j]+1,dp[i][j-1]+1));
        }
    }
    cout<<dp[len1][len2];
    return 0;
}
