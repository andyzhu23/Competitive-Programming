#include <bits/stdc++.h>
using namespace std;
#define pb push_back
using ull = unsigned long long;
string a, b;

ull base = 131;
ull key = 0;

vector<ull> p(1);
vector<ull> h;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
#endif
    cin>>a>>b;
    p[0] = 1;
    h.resize(a.size() + 10);
    for(int i = 1;i<=max(a.size(), b.size());++i) p.pb(p[i - 1] * base);
    for(char c : b) key = key * base + c;
    a = '@' + a;
    int ans = 0;
    for(int i = 1;i<a.size();++i) h[i] = h[i - 1] * base + a[i];
    for(int i = b.size();i<a.size();++i) {
        ull cur = h[i] - h[i - b.size()] * p[b.size()];
        if(cur == key) ans++;
    }
    cout<<ans<<'\n';
    return 0;
}