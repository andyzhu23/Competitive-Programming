#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int n, v, c, w, dp[N];

int main(){
  cin>>n>>v;
  for(int i = 1;i<=n;i++){
    cin>>c>>w;
    for(int j = v; j>=c; j--){
      dp[j] = max(dp[j], dp[j - c] + w);
    }
  }
  cout<<dp[v]<<endl;
}
