#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dep n - (j - i)

const int N = 100;
const ll INF = 0x3f3f3f3f3f3f3f3f;
struct node {
    int a, b, c;
    bool operator<(const node& other) const {
        return a < other.a;
    }
} nd[N];

int n;
ll k;
ll dp[N][N][N], sum[N];
// dp[i][j][w] the minimum ans for interval i-j that has root weight >= w;

bool cmp(node a, node b) {
    return a.b < b.b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 1;i<=n + 1;i++) {
        for(int w = 1;w<=n;w++) 
            dp[i][i - 1][w] = 0;
    }
    for(int i = 1;i<=n;i++) cin>>nd[i].a;
    for(int i = 1;i<=n;i++) cin>>nd[i].b;
    for(int i = 1;i<=n;i++) cin>>nd[i].c;
    sort(nd + 1, nd + n + 1, cmp);
    for(int i = 1;i<=n;i++) {
        nd[i].b = i;
    }
    sort(nd + 1, nd + n + 1);
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=n;j++) {
            if(nd[i].b < j) dp[i][i][j] = k + nd[i].c;
            else dp[i][i][j] = nd[i].c;
        }
        sum[i] = sum[i - 1] + nd[i].c;
    }
    for(int l = 2;l<=n;l++) {
        for(int i = 1;i + l - 1<=n;i++) {
            int j = i + l - 1;
            // enumerate root weight
            for(int w = 1;w<=n;w++) {
                // enumerate root
                for(int rt = i;rt <= j;rt ++) {
                    // replace the current one so that it will fit within w
                    ll ans = dp[i][rt - 1][w] + dp[rt + 1][j][w] + sum[j] - sum[i - 1] + k;
                    // if the original value fit, don't have to change, but the child need to be greater than it
                    if(nd[rt].b >= w) {
                        ans = min(ans, dp[i][rt - 1][nd[rt].b] + dp[rt + 1][j][nd[rt].b] + sum[j] - sum[i - 1]);
                    }
                    dp[i][j][w] = min(dp[i][j][w], ans);
                }
            }
        }
    }
    cout<<dp[1][n][1]<<'\n';
    return 0;
}