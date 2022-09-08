#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
#define fir first
#define sec second
int n, a[N], mn[N], psa[N];
using pii = pair<int, int>;
vector<int> ans;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    freopen("homework.in", "r", stdin);
    freopen("homework.out", "w", stdout);
    cin>>n;
    for(int i = 1;i<=n;++i) cin>>a[i];
    mn[n] = psa[n] = a[n];
    for(int i = n - 1;i;--i) {
        mn[i] = min(mn[i + 1], a[i]);
        psa[i] = psa[i + 1] + a[i];
    }
    pii mx = {0, 1};
    auto cmp = [&](pii a, pii b) {
        if(1ll * a.fir * b.sec == 1ll * a.sec * b.fir) return 2;
        if(1ll * a.fir * b.sec > 1ll * a.sec * b.fir) return 1;
        return 0;
    };
    for(int i = 1;i<n - 1;++i) {
        int a = psa[i + 1] - mn[i + 1];
        int b = n - i - 1;
        int GCD = gcd(a, b);
        a /= GCD, b /= GCD;
        int x = cmp((pii){a, b}, mx);
        if(x == 1) {
            ans.clear();
            ans.push_back(i);
            mx = {a, b};
        } else if(x == 2) ans.push_back(i);
    }
    for(int x : ans) cout<<x<<'\n';
    return 0;
}
