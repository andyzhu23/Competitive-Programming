#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
char c[N], ans[N];

void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s", c + 1);
    for(int i = 1;i<=n;++i) ans[i] = '.';
    int g = 0, h = 0, cnt = 0;
    for(int i = 1;i<=n;++i) {
        if(c[i] == 'G') {
            if(i > g) {
                int pos = min(i + k, n);
                if(ans[pos] == 'H') {
                    ans[pos - 1] = 'G';
                    g = pos + k - 1;
                } else {
                    ans[pos] = 'G';
                    g = pos + k;
                }
                ++cnt;
            }
        } else {
            if(i > h) {
                int pos = min(i + k, n);
                if(ans[pos] == 'G') {
                    ans[pos - 1] = 'H';
                    h = pos + k - 1;
                } else {
                    ans[pos] = 'H';
                    h = pos + k;
                }
                ++cnt;
            }
        }
    }
    printf("%d\n", cnt);
    for(int i = 1;i<=n;++i) putchar(ans[i]);
    putchar('\n');
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t; scanf("%d", &t);
    while(t--) solve();
    return 0;
}