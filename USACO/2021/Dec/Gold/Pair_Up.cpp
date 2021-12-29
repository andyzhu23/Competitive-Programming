#include <bits/stdc++.h>
using namespace std;

#define fir first
#define sec second
using pii = pair<int, int>;
template <typename T> inline void ckmax(T& a, T b) {a = max(a, b);}
template <typename T> inline void ckmin(T& a, T b) {a = min(a, b);}

const int N = 1e5 + 10;

struct T1 {
    int n, k, dp[N][2];
    pii a[N];
    void solve() {
        cin>>n>>k;
        memset(dp, 0x3f, sizeof(dp));
        for(int i = 1;i<=n;++i) {
            int x, y; cin>>x>>y;
            a[i] = {x, y};
        }
        dp[0][0] = dp[0][1] = 0;
        dp[1][0] = a[1].sec;
        sort(a + 1, a + n + 1);
        for(int i = 2;i<=n;++i) {
            // calculate dp[i][1]
            if(a[i].fir - a[i - 1].fir <= k) 
                ckmin(dp[i][1], min(dp[i - 2][0], dp[i - 2][1]));
            if(a[i].fir - a[i - 2].fir <= k) {
                int pos = lower_bound(a + 1, a + n + 1, (pii){a[i - 1].fir - k, -1}) - a;
                if(i - pos & 1) ckmin(dp[i][1], dp[pos][1] + a[i - 1].sec);
                else ckmin(dp[i][1], min(dp[pos - 1][0], dp[pos - 1][1]) + a[i - 1].sec);
            }
            // calculate dp[i][0]
            if(a[i].fir - a[i - 1].fir > k) 
                ckmin(dp[i][0], min(dp[i - 1][0], dp[i - 1][1]) + a[i].sec);
            else {
                int pos = lower_bound(a + 1, a + n + 1, (pii){a[i].fir - k, -1}) - a;
                if(i - pos & 1) ckmin(dp[i][0], dp[pos][1] + a[i].sec);
                else ckmin(dp[i][0], min(dp[pos - 1][0], dp[pos - 1][1]) + a[i].sec);
            }
        }
        cout<<min(dp[n][0], dp[n][1])<<'\n';
    }
};

struct T2 {
    int n, k, dp[N][2];
    pii a[N];
    void solve() {
        cin>>n>>k;
        for(int i = 1;i<=n;++i) {
            int x, y; cin>>x>>y;
            a[i] = {x, y};
        }for(int i = 1; i <= n; i++) dp[i][0] = dp[i][1] = -1e9;
        dp[0][0] = dp[0][1] = 0;
        dp[1][0] = a[1].sec;
        sort(a + 1, a + n + 1);
        for(int i = 2;i<=n;++i) {
            // calculate dp[i][1]
            if(a[i].fir - a[i - 1].fir <= k) 
                ckmax(dp[i][1], max(dp[i - 2][0], dp[i - 2][1]));
            if(a[i].fir - a[i - 2].fir <= k) {
                int pos = lower_bound(a + 1, a + n + 1, (pii){a[i - 1].fir - k, -1}) - a;
                if(i - pos & 1) ckmax(dp[i][1], dp[pos][1] + a[i - 1].sec);
                else ckmax(dp[i][1], max(dp[pos - 1][0], dp[pos - 1][1]) + a[i - 1].sec);
            }
            // calculate dp[i][0]
            if(a[i].fir - a[i - 1].fir > k) 
                ckmax(dp[i][0], max(dp[i - 1][0], dp[i - 1][1]) + a[i].sec);
            else {
                int pos = lower_bound(a + 1, a + n + 1, (pii){a[i].fir - k, -1}) - a;
                if(i - pos & 1) ckmax(dp[i][0], dp[pos][1] + a[i].sec);
                else ckmax(dp[i][0], max(dp[pos - 1][0], dp[pos - 1][1]) + a[i].sec);
            }
        }
        cout<<max(dp[n][0], dp[n][1])<<'\n';
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    int t; cin>>t;
    if(t == 1) {
        T1 ans;
        ans.solve();
    } else {
        T2 ans;
        ans.solve();
    }
    return 0;
}
