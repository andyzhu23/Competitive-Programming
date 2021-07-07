#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ins insert
#define lb lower_bound
using vi = vector<int>;
using pii = pair<int, int>;

const int N = 1034;
int n, cnt[N], e[N][N];
vi ans;


void dfs(int u) {
    for(int v = 0; v <= 500;v++) {
        if(!e[u][v]) continue;
        e[u][v] --;
        e[v][u] --;
        dfs(v);
    }
    ans.pb(u);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 1;i<=n;i++) {
        int a, b;
        cin>>a>>b;
        e[a][b]++;
        e[b][a]++;
        cnt[a] ++;
        cnt[b] ++;
    }
    int start = -1;
    for(int i = 1;i<=500;i++) {
        if(cnt[i] & 1) {
            start = i;
            break;
        }
    }
    if(start == -1) {
        for(int i = 1;i<=500;i++) {
            start = i;
            break;
        }
    }
    dfs(start);
    reverse(begin(ans), end(ans));
    for(int i : ans) cout<<i<<"\n";
    return 0;
}
