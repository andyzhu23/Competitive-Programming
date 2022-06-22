#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int c[N], o[N], w[N];
string s;
int n;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>s;
    n = s.size();
    s = '@' + s;
    for(int i = 1;i<=n;++i) {
        c[i] = c[i - 1];
        o[i] = o[i - 1];
        w[i] = w[i - 1];
        if(s[i] == 'C') c[i] ^= 1;
        if(s[i] == 'O') o[i] ^= 1;
        if(s[i] == 'W') w[i] ^= 1;
    }
    int q; cin>>q;
    while(q--) {
        int u, v; cin>>u>>v;
        int a = c[v] ^ c[u - 1];
        int b = o[v] ^ o[u - 1];
        int c = w[v] ^ w[u - 1];
        if(a == 1 && b == 0 && c == 0) cout<<'Y';
        else if(a == 0 && b == 1 && c == 1) cout<<'Y';
        else cout<<'N';
    }
    cout<<'\n';
    return 0;
}