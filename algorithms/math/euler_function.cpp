#include <bits/stdc++.h>
using namespace std;
const int N = 32768;
int phi[N + 5], p[N + 5], tot, vis[N + 5];

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    phi[1] = 1;
    for(int i = 2;i<=N;++i) {
        if(!vis[i]) p[++tot] = i, phi[i] = i - 1;
        for(int j = 1;j<=tot && p[j] * i <= N;++j) {
            vis[p[j] * i] = 1;
            if(i % p[j] == 0) {
                phi[i * p[j]] = phi[i] * p[j];
                break;
            } else phi[i * p[j]] = phi[i] * phi[p[j]];
        }
    }
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        cout<<phi[n]<<'\n';
    }
    return 0;
}
