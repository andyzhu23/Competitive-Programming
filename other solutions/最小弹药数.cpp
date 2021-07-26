#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using vi = vector<int>;

const int N = 510;
vi e[N], row;
int vis[N], vis2[N], match[N];
int n, k, tot;

bool Find(int u) {
    for(int v : e[u]) {
        if(!vis[v]) {
            vis[v] = 1;
            if(match[v] == 0 || Find(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i = 1;i<=k;i++) {
        int r, c;
        cin>>r>>c;
        e[r].pb(c);
        if(!vis[r]) row.pb(r);
        vis[r] ++;
        vis2[c] ++;
    }
    int ans = 0;
    for(int i = 1;i<=n;i++) {
        if(vis[i]) ans++;
        if(vis2[i]) ans++;
    }
    ans = 0;
    for(int i : row) {
        memset(vis, 0, sizeof(vis));
        if(Find(i)) {
            ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
