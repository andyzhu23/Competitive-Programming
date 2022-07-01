#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
string s;
int n, K, fail[N];

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>s>>K;
    n = s.size();
    s = '@' + s;
    int i = 1, j = 2;
    while(i <= n - K + 1 && j <= n - K + 1) {
        int k = 0;
        while(s[i + k] == s[j + k]) ++k;
        if(s[i + k] > s[j + k]) i += k + 1, swap(i, j);
        else j += k + 1;
        if(i == j) ++j;
    }
    j = n - K + 1;
    int k = 0;
    while(s[i + k] == s[j + k]) ++k;
    if(k <= K && s[j + k] < s[i + k]) swap(i, j);
    for(int k = 0;k<K;++k) cout<<s[i + k];
    cout<<'\n';
    return 0;
}
