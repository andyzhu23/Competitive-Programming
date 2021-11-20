#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int w, b;

double dp[N][N];

double cal(int w, int b) {
    if(w == 0 && b == 0) return 0;
    if(dp[w][b] != 0.0) return dp[w][b];
    // get a white mice
    dp[w][b] = (double)(w) / (double)(w + b);
    // get a black mice
    double tmp = (double)(b) / (double)(w + b);
    // a black mice came out and the dragon got a black mice
    if(b >= 3)
        dp[w][b] += tmp * (double)(b - 1) / (double)(w + b - 1) * (double)(b - 2) / (double)(w + b - 2) * cal(w, b - 3);
    // a white mice came out and dragon got a black mice
    if(b >= 2 && w >= 1)
        dp[w][b] += tmp * (double)(w) / (double)(w + b - 1) * (double)(b - 1) / (double)(w + b - 2) * cal(w - 1, b - 2);
    return dp[w][b];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    dp[1][0] = 1;
    cin>>w>>b;
    cout<<setprecision(9)<<cal(w, b)<<'\n';
    return 0;
}
