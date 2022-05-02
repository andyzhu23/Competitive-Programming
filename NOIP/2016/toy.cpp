#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
string s[N];
int n, m;
bitset<N> p;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>m;
    for(int i = 0;i<n;++i) {
        bool x; cin>>x;
        p[i] = x;
        cin>>s[i];
    }
    int ans = 0;
    for(int i = 1;i<=m;++i) {
        int u, v; cin>>u>>v;
        if(!p[ans]) u ^= 1;
        if(u) v *= -1;
        ans = (ans + n + v) % n;
    }
    cout<<s[ans]<<'\n';
    return 0;
}