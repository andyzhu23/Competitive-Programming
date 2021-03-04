#include <iostream>
using namespace std;
const int N = 1e3+10;
const long long INF = 3e9;
int n, m;
int Map[N][N];
long long dp[N][N][3]; // 0 left, 1 up, 2 down

int main() {
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin>>Map[i][j];
            dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = -INF;
        }
    }
    for(int i = 0;i<=n + 2;i++){
        for(int j = 0;j<=m + 2;j++){
            dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = -INF;
        }
    }
    dp[1][1][0] = dp[1][1][1] = dp[1][1][2] = Map[1][1];
    for(int j = 1;j<=m;j++){
        for(int i = 1;i<=n;i++){
            if(j == 1 && i == 1) continue;
            dp[i][j][1] = max(dp[i - 1][j][0], dp[i - 1][j][1]) + Map[i][j];
            dp[i][j][0] = max(dp[i][j - 1][2], max(dp[i][j - 1][0],dp[i][j - 1][1])) + Map[i][j];
        }

        for(int i = n;i>=1;i--){
            if(j == 1 && i == 1) continue;
            dp[i][j][2] = max(dp[i + 1][j][0], dp[i + 1][j][2]) + Map[i][j];
        }
    }
    cout<<max(dp[n][m][0], dp[n][m][1]);
    return 0;
}

