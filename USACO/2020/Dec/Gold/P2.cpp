#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;
string s;
unordered_map<char, int> key;
int n;

ll dp[N][4][4][4];

int main() {
    key['A'] = 0, key['G'] = 1, key['C'] = 2, key['T'] = 3;
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>s;
    int n = s.size();
    for(int i = 0;i<4;++i) {
        for(int j = 0;j<4;++j) {
            if(s[0] == '?' || key[s[0]] == j) {
                dp[0][i][j][j] = 1;
            }
        }
    }
    for(int i = 1;i<n;++i) {
        for(int j = 0;j<4;++j) {
            if(s[i] != '?' && key[s[i]] != j) continue;
            for(int a = 0;a<4;++a) {
                for(int c = 0;c<4;++c) {
                    for(int d = 0;d<4;++d) {
                        if(a == d) {
                            dp[i][c][j][j] = (dp[i][c][j][j] + dp[i - 1][a][c][d]) % MOD;
                        } 
                        if(j != d) {
                            dp[i][a][c][j] = (dp[i][a][c][j] + dp[i - 1][a][c][d]) % MOD;
                        }
                    }
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 0;i<4;++i) {
        for(int j = 0;j<4;++j) {
            ans = (ans + dp[n - 1][i][j][i]) % MOD;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
