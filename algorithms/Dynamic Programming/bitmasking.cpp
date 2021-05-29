#include <iostream>
#include <vector>
#define endl "\n"
#define pb push_back
using ll = long long;
using namespace std;
const int N = 15;
int n, K;
ll dp[N][1024][N * N];

struct s{
    int a, cnt;
};
vector<s> v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>K;
    for(int i = 0;i < (1 << n);i++){
        if(i & (i >> 1) || i & (i << 1)) continue;
        int b = i, cnt = 0;
        while(b) {
            cnt += b & 1;
            b = b >> 1;
        }
        s S;
        S.a = i;
        if(cnt > K) continue;
        S.cnt = cnt;
        v.pb(S);
    }
    cout<<v.size()<<endl;
    for(int i = 0;i<v.size();i++){
        dp[1][i][v[i].cnt] = 1;
    }
    
    for(int i = 2;i <= n;i++){
        for(int j = 0;j<v.size();j++){
            for(int k = v[j].cnt;k<=K;k++){
                for(int l = 0;l<v.size();l++){
                    if(v[l].a & v[j].a || v[l].a & (v[j].a << 1) || v[l].a & (v[j].a >> 1)) continue;
                    dp[i][j][k] += dp[i - 1][l][k - v[j].cnt];
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 0;i<v.size();i++){
        ans += dp[n][i][K];
    }
    cout<<ans<<endl;
    return 0;
}
