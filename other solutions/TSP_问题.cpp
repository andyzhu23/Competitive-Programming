#include <iostream>
#include <memory>
#include <memory.h>
#define endl "\n"
using namespace std;
const int N = 18;
const int INF = 0x3f3f3f3f;
int e[N][N], n, dp[N][1 << N], final;

inline int dfs(int u, int mask){
    if(dp[u][mask] >= INF){
        if(mask == final) dp[u][mask] = e[u][0];
        else {
            for(int v = 0;v<=n;v++){
                if(mask & 1 << v) continue;
                dp[u][mask] = min(dp[u][mask], dfs(v, mask | 1 << v) + e[u][v]);
            }
        }
    }
    return dp[u][mask];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    final = (1 << (n + 1)) - 1;
    memset(dp, 63, sizeof(dp));
    for(int i = 0;i<=n;i++)
        for(int j = 0;j<=n;j++)
            cin>>e[i][j];
    dfs(0, 1);
    cout<<dp[0][1]<<endl;
    return 0;
}
