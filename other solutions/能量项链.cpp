#include <bits/stdc++.h>
using namespace std;

#define fir first
#define sec second
typedef pair<int, int> pii;
const int N = 300; // 300 cause below i put 2 * n
pii a[N];
int n;
// dp[i][j] from i to j the maximum solution
int dp[N][N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    cin>>a[1].fir;
    a[n].sec = a[1].fir;
    for(int i = 2;i<=n;i++) {
        cin>>a[i].fir;
        a[i - 1].sec = a[i].fir;
    }
    for(int i = n + 1;i<=n * 2;i++) {
        a[i] = a[i - n];
    }
    int ans = 0;
    for(int l = 2;l<=n;l++) {
        for(int i = 1;i + l - 1 <= (n << 1);i++) {
            int j = i + l - 1;
            for(int k = i;k<j;k++) {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + a[i].fir * a[k].sec * a[j].sec);
            }
        }
    }
    for(int i = 1;i<=n;i++) {
        ans = max(ans, dp[i][n + i - 1]);
    }
    cout<<ans<<'\n';
    return 0;
}
