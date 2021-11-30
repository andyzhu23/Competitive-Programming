#include <bits/stdc++.h>
using namespace std;

int dp[100][30], n, ans[30];

int get(char c) {
    return c - 'A' > 25 ? 26 : c - 'A';
}

char put(int x) {
    return x == 26 ? '_' : x + 'A';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    for(int i = 0;i<=26;++i) {
        char c; cin>>c;
        dp[0][i] = get(c);
    }
    for(int i = 1;i<=50;++i) {
        for(int j = 0;j<=26;++j) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }
    cin>>n;
    for(int i = 0;i<30;++i) ans[i] = i;
    for(int i = 40;i >= 0 && n > 0;i--) {
        if(n >= (1ll << i)) {
            n -= 1ll << i;
            for(int j = 0;j<=26;++j) ans[j] = dp[i][ans[j]];
        }
    }
    string s; cin>>s;
    for(auto& c : s) c = put(ans[get(c)]);
    cout<<s<<'\n';
    return 0;
}
