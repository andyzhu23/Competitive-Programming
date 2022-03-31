#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
const int mod = 1e9 + 7;
using ll = long long;
ll dp[N][N], n, cs[N], ct[N];
string s, t;

void solve() {
    memset(dp, 0, sizeof(dp));
    cin>>n;
    string S, T;
    cin>>S>>T;
    s = "@";
    t = "@";
    for(char c : S) {
        if(c == '0') s = "@0";
        else if(c == '1');
        else s += c;
    }
    for(char c : T) {
        if(c == '0') t = "@0";
        else if(c == '1');
        else t += c;
    }
    // cout<<s<<' '<<t<<'\n';
    int ns = s.size() - 1;
    int nt = t.size() - 1;
    dp[0][0] = 1;
    for(int i = 1;i<=n;++i) {
        dp[0][i] = dp[i][0] = 1;
    }
    for(int i = 1;i<=ns;++i) {
        for(int j = 1;j<=nt;++j) {
            if(s[i] == '+' && t[j] == '+') {
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + mod) % mod;
            } else if(s[i] != '+' && t[j] != '+') {
                // cout<<i<<' '<<j<<'\n';
                // cout<<dp[i][j - 1]<<' '<<dp[i - 1][j]<<'\n';
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + mod) % mod;
            } else {
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
            }
        }
    }
    // for(int i = 1;i<=n;++i) {
    //     for(int j = 1;j<=n;++j) {
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    cout<<dp[ns][nt]<<'\n';
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t; cin>>t;
    while(t--) solve();
    return 0;
}

/*
4
1
0
1
3
12+
+02
3
0++
++9
4
5+++
+6+1
*/