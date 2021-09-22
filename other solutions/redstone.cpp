#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 1e3 + 10;
int n, m, cnt = 0;
vector<int> e[N];
bool vis[N], in[N], incycle[N];

void dfs(int u) {
    if(in[u]) {
        ++cnt;
        incycle[u] = 1;
    }
    if(vis[u]) return;
    in[u] = vis[u] = 1;
    for(int v : e[u]) {
        if(incycle[v]) ++cnt;
        dfs(v);
        incycle[u] |= incycle[v];
    }
    in[u] = 0;
}

int main() {
    scanf("%d %d", &n, &m);
    while(m--) {
        int a, b;
        scanf("%d %d", &a, &b);
        e[a].pb(b);
    }
    for(int i = 1;i<=n;++i) {
        memset(incycle, 0, sizeof(in));
        if(!vis[i]) dfs(i);
    }
    cnt > 0 ? (cnt > 1 ? printf("Infinite Loops Present") : printf("Infinite Loop Present")) : printf("No Infinite Loops");
    printf("\n");
    return 0;
}
