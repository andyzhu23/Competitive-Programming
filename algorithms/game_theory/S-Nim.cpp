#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int k, m, s[N], a[N], n, sg[N];
bitset<N> vis;

void solve() {
    memset(sg, 0, sizeof sg);
    for(int i = 1;i<=k;++i) scanf("%d", s + i);
    for(int i = 1;i<N;++i) {
        for(int j = 1;j<=k;++j) if(i >= s[j]) vis[sg[i - s[j]]] = 1;
        while(vis[sg[i]]) ++sg[i];
        for(int j = 1;j<=k;++j) if(i >= s[j]) vis[sg[i - s[j]]] = 0;
    }
    scanf("%d", &m);
    for(int i = 1;i<=m;++i) {
        int tot = 0;
        scanf("%d", &n);
        for(int j = 1;j<=n;++j) {
            int x; scanf("%d", &x);
            tot ^= sg[x];
        }
        putchar(tot == 0 ? 'L' : 'W');
    }
    putchar('\n');
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while(1) {
        scanf("%d", &k);
        if(k == 0) return 0;
        solve();
    }
    return 0;
}
