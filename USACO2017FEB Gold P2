#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e3+ 10;

int n, a[N], b[N], dp[N][N];

bool isFriend(int x, int y){
    if(abs(x - y) <= 4) return true;
    return false;
}


int main() {
    scanf("%d",&n);
    for(int i = 1; i<=n;i++){
        scanf("%d", &a[i]);
    }
    for(int i = 1;i<=n;i++){
        scanf("%d", &b[i]);
    }

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(isFriend(a[i], b[j])) dp[i][j] = dp[i - 1][j - 1] + 1;
            dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
        }
    }
    printf("%d", dp[n][n]);
    return 0;
}
