#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;
ll n, a[N], p[N];
vector<ll> l, r;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    ll on = n;
    p[0] = 1;
    int len = 0;
    while(n > 0) {
        a[++len] = n % 3;
        n /= 3;
        p[len] = p[len - 1] * 3;
    }
    for(int i = 1;i<=len + 1;++i) {
        a[i + 1] += a[i] / 3;
        a[i] %= 3;
        if(a[i] == 2) {
            r.push_back(p[i - 1]);
            a[i] = 0;
            ++a[i + 1];
        }
        if(a[i] == 1) {
            l.push_back(p[i - 1]);
        }
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    for(int i = 0;i<l.size();++i) {
        cout<<l[i]<<(i == l.size() - 1 ? '\n' : ' ');
    }
    cout<<on<<' ';
    for(int i = 0;i<r.size();++i) {
        cout<<r[i]<<(i == r.size() - 1 ? '\n' : ' ');
    }
    return 0;
}
