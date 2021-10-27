#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
string a, b;

int fail[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>a>>b;
    fail[0] = -1;
    for(int i = 1;i<=b.size();++i) {
        int j = fail[i - 1];
        while(j >= 0 && b[j + 1] != b[i]) j = fail[j];
        if(b[j + 1] == b[i]) ++j;
        fail[i] = j;
    }
    int j = -1;
    int ans = 0;
    for(int i = 0;i<a.size();++i) {
        while(j >= 0 && b[j + 1] != a[i]) j = fail[j];
        if(b[j + 1] == a[i]) {
            ++j;
            if(j + 1 == b.size()) ans++;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
