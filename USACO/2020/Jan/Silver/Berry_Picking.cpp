#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int n, k, b[N], c[N];

bool cmp(int a, int b) {
    return a > b;
}

int main(){
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i = 1;i<=n;i++) {
        cin>>b[i];
    }
    int ans = 0;
    for(int x = 1;x<N;x++) {
        int cnt = 0;
        for(int i = 1;i<=n;i++) c[i] = b[i];
        for(int i = 1;i<=n;i++) {
            while(c[i] > x) {
                c[i] -= x;
                cnt++;
            }
        }
        sort(c + 1, c + n + 1, cmp);
        for(int i = 1;i<=n;i++) c[i] += c[i - 1];
        if(cnt >= k) ans = max(ans, (k >> 1) * x);
        else {
            cnt -= k / 2;
            if(cnt > 0) ans = max(ans, x * cnt + c[(k >> 1) - cnt]);
            else ans = max(ans, c[(k >> 1) - cnt] - c[-cnt]);
        }
    }
    cout<<ans<<"\n";
    return 0;
}
