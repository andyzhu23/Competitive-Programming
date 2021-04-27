#include <iostream>
#include <iomanip>
#define endl "\n"
#define int long long
using namespace std;
const int N = 2e2 + 10;
const int MOD = 1e5;
int n, dp[N][N];
bool vis[N][N];
string s;


inline int bracket(char a, char b){
    if(a == '(' && b == ')') return true;
    else if(a == '[' && b == ']') return true;
    else if(a == '{' && b == '}') return true;
    else if(a == '(' && b == '?') return true;
    else if(a == '[' && b == '?') return true;
    else if(a == '{' && b == '?') return true;
    else if(a == '?' && b == ')') return true;
    else if(a == '?' && b == ']') return true;
    else if(a == '?' && b == '}') return true;
    else if(a == '?' && b == '?') return 3;
    return false;
}


inline void solve(int l, int r){
    if(r <= l){
        dp[l][r] = 1;
        vis[l][r] = true;
        return;
    }
    for(int i = l + 1;i<=r;i += 2){
        if(!vis[l + 1][i - 1]){
            solve(l + 1, i - 1);
            vis[l + 1][i - 1] = true;
        }
        if(!vis[i + 1][r]){
            solve(i + 1, r);
            vis[i + 1][r] = true;
        }
        dp[l][r] += dp[l + 1][i - 1] * bracket(s[l - 1], s[i - 1]) * dp[i + 1][r];
        if(dp[l][r] > MOD) dp[l][r] = dp[l][r] % MOD + MOD;
    }
    vis[l][r] = true;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    cin>>s;
    solve(1, n);
    if(dp[1][n] >= MOD) cout<<setw(5)<<setfill('0')<<dp[1][n] % MOD<<endl;
    else cout<<dp[1][n]<<endl;
    return 0;
}
