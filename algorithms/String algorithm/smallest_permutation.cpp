#include <bits/stdc++.h>
using namespace std;

string s;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
#endif    
    cin>>s;
    n = s.size();
    s = '@' + s + s;
    int i = 1, j = 2, k = 0;
    while(i <= n && j <= n) {
        while(s[i + k] == s[j + k]) ++k;
        s[i + k] > s[j + k] ? i += k + 1 : j += k + 1;
        k = 0;
        if(i == j) ++j;
    }
    for(int x = 0;x<n;++x) cout<<s[x + min(i, j)];
    cout<<'\n';
    return 0;
}
