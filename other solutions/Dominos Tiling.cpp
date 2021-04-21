#include <iostream>
#define endl "\n"
using namespace std;
using ll = long long;
const int MOD = 1e6;
const int N = 40;
int n, dp[N];
inline void solve(){
    dp[0] = 1;
    for(int i = 2;i<N;i+=2){
        dp[i] += dp[i - 2] * 3;
        dp[i] %= MOD;
        for(int j = 0;j<=i - 4;j+=2){
            dp[i] += dp[j] * 2;
            dp[i] %= MOD;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 5;
    solve();
    while(t--){
        cin>>n;
        cout<<dp[n]<<endl;
    }
    return 0;
}
