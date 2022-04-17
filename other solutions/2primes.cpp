#include <bits/stdc++.h>
using namespace std;
const int N = 31632;
const int M = 5e6 + 5;
#define pb push_back
bitset<M> p;
bitset<M> fail;
set<int> pm;
using ll = long long;
int n, m;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    for(int i = 2;i<N;++i) {
        if(p[i]) continue;
        pm.insert(i);
        for(int j = i + i;j<N;j+=i) p[j] = 1;
    }
    cin>>n>>m;
    if(n == 1) ++n;
    for(int i = n;i<=m;++i) {
        set<int> vis;
        for(auto c : pm) {
            if((ll)c * c > i) break;
            if(i % c == 0 && i / c != 1) {
                for(int j = i; j <= m; j += c) fail[j - n] = 1;
                vis.insert(c);
            }
        }
        for(auto c : vis) pm.erase(c);
    }
    for(int i = 0;i<=m - n;++i) if(!fail[i]) cout<<i + n<<'\n';
    return 0;
}
