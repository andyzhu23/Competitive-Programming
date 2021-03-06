#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3 + 10;
const int INF = 1e9;
int n, m, K, dp[N][N];

signed main(){
  cin>>n>>m>>K;
  for(int i = 1;i<=n;i++){
    for(int j = 1;j<=n;j++){
      dp[i][j] = INF;
    }
  }
  for(int i =1 ;i<=m;i++){
    int a, b, c;
    cin>>a>>b>>c;
    dp[a][b] = min(dp[a][b], c);
  }
  for(int k = 1;k<=n;k++){
    for(int i  = 1;i<=n;i++){
      for(int j = 1;j<=n;j++){
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }
  for(int i = 1;i<=K;i++){
    int a, b;
    cin>>a>>b;
    if(dp[a][b] == INF) cout<<"Nothing to say!"<<endl;
    else cout<<dp[a][b]<<endl;
    
  }
  return 0;
}
