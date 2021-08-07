#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int k, m, n, e[N][N], match[N], vis[N]; 

bool Find(int x) { // x is the weapon, f[x] is the person
    for(int i = 1; i <= n; i++) {       //  enumerate right point
        if(e[x][i] == 1 && vis[i] == 0) {
            vis[i] = 1;
            if(match[i] == 0 || Find(match[i])) {
                match[i] = x;
                return true;
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>k>>m>>n;
    for(int i = 1;i<=k;i++) {
        int a, b;
        cin>>a>>b;
        e[a][b] = 1;
    }
    int ans = 0;
    for(int i = 1; i <= m;i++) {        //  enumerate left point
        memset(vis, 0, sizeof(vis));
        if(Find(i)) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
