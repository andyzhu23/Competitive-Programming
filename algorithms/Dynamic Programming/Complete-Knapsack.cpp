#include <iostream>
using namespace std;
const int N = 1e3+10;

int n,v;
int c,w,dp[N];
int main() {
    cin>>n>>v;
    for(int i = 1;i<=n;i++){
        cin>>c>>w;
        for(int j = c;j<=v;j++){
            dp[j] = max(dp[j], dp[j - c] + w);
        }
    }
    cout<<dp[v];
    return 0;
}
