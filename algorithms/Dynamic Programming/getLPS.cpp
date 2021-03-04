#include <iostream>
using namespace std;
string s1,s2;
const int N = 1e3+10;
int dp[N][N];
int main() {
    cin>>s1;
    int len = s1.size();
    for(int i = 0;i<len;i++){
        s2 = s1[i] + s2;
    }

    for(int i = 1;i<=len;i++){
        for(int j = 1;j<=len;j++){
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            dp[i][j] = max(dp[i][j], max(dp[i][j-1], dp[i-1][j]));
        }
    }
    cout<<dp[len][len];
    return 0;
}
