#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int K = 25;
char c[N];
int n, k, mx[K][3];

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    // freopen("hps.in", "r", stdin);
    // freopen("hps.out", "w", stdout);
    cin>>n>>k;
    ++k;
    auto convert = [&](char c) {
        switch(c) {
            case 'H': return 1;
            case 'P': return 2;
            case 'S': return 0;
        }
        return 0;
    };
    int ans = 0;
    for(int i = 1;i<=n;++i) {
        cin>>c[i];
        int x = convert(c[i]);
        for(int j = k;j;--j) {
            ++mx[j - 1][x];
            int tmp = max({mx[j - 1][0], mx[j - 1][1], mx[j - 1][2]});
            ans = max(ans, tmp);
            mx[j][0] = max(mx[j][0], tmp);
            mx[j][1] = max(mx[j][1], tmp);
            mx[j][2] = max(mx[j][2], tmp);
        }
    }
    cout<<ans<<'\n';
    return 0;
}
