#include <iostream>
using namespace std;
const int N =3e4 + 10;
const int K = 5e2 + 10;
int t;

int main() {
    cin>>t;
    while(t--) {
        int n, k, w, a[N],dp[N][K], sum[N];
        cin >> n >> k >> w;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum[i] = sum[i - 1] + a[i];
        }

        for (int i = w; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                if (i < j * w) continue;
                dp[i][j] = max(dp[i - 1][j], dp[i - w][j - 1] + sum[i] - sum[i - w]);
            }
        }

        cout << dp[n][k]<<endl;
    }
    return 0;
}

