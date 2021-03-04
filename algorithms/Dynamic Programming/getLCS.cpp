#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e4;
string a,b;
int dp[N][N],len1,len2;
int main() {
    cin>>a>>b;
    len1 = a.size();
    len2 = b.size();
    for(int i = 1;i<=len1;i++){
        for(int j = 1;j<=len2;j++){
            if(a[i - 1] == b[j - 1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout<<dp[len1][len2];
    return 0;
}
