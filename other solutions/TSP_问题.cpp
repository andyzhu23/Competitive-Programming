#include <iostream>
#include <memory>
#include <memory.h>
#define endl "\n"
using namespace std;
const int N = 20;
const int INF = 0x3f3f3f3f;
int e[N][N], n, dp[N][1 << N];

inline void dfs(int u, int fa, int mask, int last){
    if(fa == -1) dp[u][mask] = 0;
    else dp[u][mask] = min(dp[u][mask], dp[fa][last] + e[fa][u]);
    for(int v = 0;v<=n;v++){
        if(mask & (1 << v)) continue;
        dfs(v, u, mask | (1 << v), mask);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    memset(dp, 63, sizeof(dp));
    for(int i = 0;i<=n;i++)
        for(int j = 0;j<=n;j++)
            cin>>e[i][j];
    dfs(0, -1, 1, 0);
    int final = (1 << (n + 1)) - 1;
    int ans = INF;
    for(int i = 0;i<=n;i++) {
        ans = min(ans, dp[i][final] + e[i][0]);
    }
    cout<<ans<<endl;
    return 0;
}
