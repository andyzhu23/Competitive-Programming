#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e2 + 10;
const int INF = 1e8;
int m , q, a[N], dp[N][N];
string name[N];
string vis[N][N];

int main() {
    cin>>m;
    cin>>q;

    for(int i = 1;i<=q;i++){
        cin>>name[i];
        cin>>a[i];
    }

    for(int i = 1;i<=q;i++){
        dp[i][i] = a[i];
        vis[i][i] = name[i];
    }

    for(int i = 1;i<=q;i++){
        for(int j = 1;j<=q;j++){
            if(i != j){
                dp[i][j] = INF;
            }
        }
    }

    for(int l = 2; l <= q; l++){
        for(int i = 1;i<=q;i++){
            int j = i + l - 1;
            if( j > q) continue;
            if(l <= m){
                vis[i][j] = vis[i][i];
                dp[i][j] = dp[i][i];
                for(int k = i + 1; k <= j; k++){
                    vis[i][j] = vis[i][j] + " " + vis[k][k];
                    dp[i][j] = max(dp[i][j], dp[k][k]);
                }
            } else {
                for (int k = i; k < j; k++) {
                    if (dp[i][k] + dp[k + 1][j] < dp[i][j]) {
                        vis[i][j] = vis[i][k] + "\n" + vis[k + 1][j];
                        dp[i][j] = dp[i][k] + dp[k + 1][j];
                    }
                }
            }
        }
    }
    printf("Total Time: %d\n", dp[1][q]);
    cout<<vis[1][q]<<endl;
    return 0;
}
