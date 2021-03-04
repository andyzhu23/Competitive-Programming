#include <iostream>
#include <cstdio>
using namespace std;
const int N = 52;
const int V = 5380;
const int INF = 1e7 + 10;

int v, n, c[N];
int dp[V];

int main() {
    cin>>v;
    cin>>n;
    for(int i = 1;i<=v;i++){
        dp[i] = INF;
    }
    for(int i = 1;i<=n;i++){
        cin>>c[i];
        dp[c[i]] = 1;
    }

    for(int i = 1;i<=v;i++){
        for(int j = 1;j<i;j++){
            dp[i] = min(dp[i], dp[j] + dp[i - j]);
        }
    }
    if(dp[v] == INF) printf("Roberta acknowledges defeat. ");
    else printf("Roberta wins in %d strokes.", dp[v]);

    return 0;
}
