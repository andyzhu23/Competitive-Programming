#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 5;
const int base = 131;
const int base2 = 13331;
const int mod = 1e9 + 7;
using ull = unsigned long long;
ull p[N], h[N], key;
ull p2[N], h2[N], key2;
string s, t;

int main() {
    ios::sync_with_stdio(0);
    cin>>s>>t;
    int n = s.size(), m = t.size();
    s = '@' + s;
    t = '@' + t;
    p[0] = p2[0] = 1;
    for(int i = 1;i<=n;++i) {
        h[i] = h[i - 1] * 131 + s[i];
        p[i] = p[i - 1] * 131;
        h2[i] = (h2[i - 1] * base2 % mod + s[i]) % mod;
        p2[i] = p2[i - 1] * base2 % mod;
    }
    for(int i = 1;i<=m;++i) {
        key = key * 131 + t[i];
        key2 = (key2 * base2 + t[i]) % mod;
    }
    for(int i = 1;i + m - 1<=n;++i) {
        int j = i + m - 1;
        if(h[j] - h[i - 1] * p[m] == key && (h2[j] - h2[i - 1] * p2[m] % mod + mod) % mod == key2) {
            cout<<i - 1<<'\n';
            return 0;
        }
    }
    cout<<-1<<'\n';
    return 0;
}
