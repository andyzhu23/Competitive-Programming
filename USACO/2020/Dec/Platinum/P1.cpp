#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(v) v.begin(), v.end()
using ll = long long;
const int N = 3e3 + 10;
const int MOD = 1e9 + 7;
struct cow {
    int val, type;
    bool operator<(const cow& other) const {
        return val == other.val ? type < other.type : val < other.val;
    }
};
int n;
ll dp[2][N][2]; 
// dp[i][j][k] first i cows, j needs for barn, k = 0 all cows are matched, k = 1 some cow are not matched
vector<cow> cows;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    for(int i = 1;i<=n;++i) {
        int x; cin>>x;
        cows.pb({x, 0});
    }
    for(int i = 1;i<=n;++i) {
        int x; cin>>x;
        cows.pb({x, 1});
    }
    sort(all(cows));
    dp[0][0][0] = 1;
    for(int i = 1;i<=(n << 1);++i) {
        if(!cows[i - 1].type) { // cow
            for(int j = 0;j<=n;++j) {
                if(j) {
                    dp[i & 1][j][0] = dp[i & 1 ^ 1][j - 1][0] % MOD;
                    dp[i & 1][j][1] = dp[i & 1 ^ 1][j - 1][1] % MOD;
                }
                dp[i & 1][j][1] = (dp[i & 1][j][1] + dp[i & 1 ^ 1][j][0] + dp[i & 1 ^ 1][j][1]) % MOD;
            }
        } else { // barn
            for(int j = 0;j<=n;++j) {
                dp[i & 1][j][0] = ((j + 1) * dp[i & 1 ^ 1][j + 1][0] + dp[i & 1 ^ 1][j][0]) % MOD;
                dp[i & 1][j][1] = (j + 1) * dp[i & 1 ^ 1][j + 1][1] % MOD;
            }
        }
        memset(dp[i & 1 ^ 1], 0, sizeof(dp[i & 1 ^ 1]));
    }
    cout<<(dp[0][0][0] + dp[0][0][1]) % MOD<<'\n';
    return 0;
}
