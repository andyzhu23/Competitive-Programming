#include <bits/stdc++.h>

using namespace std;

// make sure 2e5 because of the hashtags
const int N = 2e5 + 10;
string s; 
int p[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
#endif
    cin>>s;
    int n = s.size();
    s = '@' + s;
    // replace with hash
    string tmp = "@#";
    for(int i = 1;i<=n;++i) {
        tmp += s[i];
        tmp += '#';
    }
    s = tmp;
    n = s.size() - 1;
    int mid = 1, r = 1;
    int ans = 0;
    for(int i = 1;i<=n;++i) {
        if(i < r) p[i] = min(p[mid * 2 - i], r - i);
        while(i > p[i] + 1 && p[i] + 1 + i <= n && s[i - (p[i] + 1)] == s[i + p[i] + 1]) p[i]++;
        if(i + p[i] > r) mid = i, r = i + p[i];
        ans = max(ans, p[i]);
    }
    cout<<ans<<'\n';
    return 0;
}
