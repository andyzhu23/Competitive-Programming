#include <bits/stdc++.h>
using namespace std;

#define pb push_back
using vi = vector<int>;

int n, oe[30][30], e[30][30];

void dfs(int u, vi& ans) {
    for(int i = 0;i<=30;i++) {
        if(e[u][i] <= 0) continue;
        e[u][i] = 0;
        dfs(i, ans);
    }
    ans.pb(u);
}

bool ok() {
    for(int i = 1;i<=30;i++) {
        for(int j = 1;j<=30;j++) {
            if(e[i][j]) return 0;
        }
    }
    return 1;
}

void solve() {
    cin>>n;
    memset(oe, 0, sizeof(oe));

    for(int i = 1;i<=n;i++) {
        string s;
        cin>>s;
        oe[s[0] - 'a' + 1][s[s.size() - 1] - 'a' + 1] ++;
    }
    for(int i = 1;i<=30;i++) {
        for(int j = 1;j<=30;j++) 
            for(int k = 1;k<=30;k++) 
                e[j][k] = oe[j][k];
        vi ans;
        dfs(i, ans);
        if(ok()) {
            cout<<"Ordering is possible."<<"\n";
            return;
        }
    }
    cout<<"The door cannot be opened."<<"\n";
    return;
}

#define docase 1

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #if docase
    int t; cin>>t;
    while(t--) solve();
    #else docase
    solve();
    #endif
    return 0;
}
