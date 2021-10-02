#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
int sum[N][N], n;

int cnt(int i, int j, int x) {
    int k = i + x;
    int w = j + x;
    return sum[k][w] - sum[k][j - 1] - sum[i - 1][w] + sum[i - 1][j - 1];
}

bool ok(int x) {
    for(int i = 1;i<=n - x;++i) {
        for(int j = 1;j<=n - x;++j) {
            if(x == 1 && cnt(i, j, x) == 0) {
                return 1;
            }
            if(cnt(i, j, x) == cnt(i + 1, j + 1, x - 2)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 1;i<=n;++i) {
        string s; cin>>s;
        for(int j = 1;j<=n;++j) {
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + (s[j - 1] == '#');
        }
    }
    int ans = 0;
    for(int i = 1;i<=n - 1;++i) {
        if(ok(i)) ans = i;
    }

    cout<<ans<<'\n';
    return 0;
}
