#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using ll = __int128;
const int N = 2e5 + 10;
const ll BASE = 257;
const ll MOD = 87609347865089543457;
const ll MOD2 = 9672094367238976237;
const ll BASE2 = 131;
const ll MOD3 = 9982443246458234353;
const ll BASE3 = 13331;
string a, b;
int key[30], hay[N][30];
ll pw[N], hsh[N], pw2[N], hsh2[N], pw3[N], hsh3[N];
set<ll> vis, vis2, vis3;

bool ok(int idx) {
    for(int i = 0;i<30;++i) {
        if(hay[idx][i] - hay[idx - a.size()][i] != key[i]) return 0;
    }
    return 1;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    char c = getchar();
    while(isalpha(c)) a += c, c = getchar();
    while(!isalpha(c)) c = getchar();
    while(isalpha(c)) b += c, c = getchar();
    for(auto x : a) ++key[x - 'a'];
    pw[0] = pw2[0] = 1;
    for(int i = 1;i<=b.size();++i) {
        for(int j = 0;j<30;++j) hay[i][j] = hay[i - 1][j];
        ++hay[i][b[i - 1] - 'a'];
        hsh[i] = (hsh[i - 1] * BASE % MOD + b[i - 1]) % MOD;
        pw[i] = pw[i - 1] * BASE % MOD;
        hsh2[i] = (hsh2[i - 1] * BASE2 % MOD2 + b[i - 1]) % MOD2;
        pw2[i] = pw2[i - 1] * BASE2 % MOD2;
        hsh3[i] = (hsh3[i - 1] * BASE3 % MOD3 + b[i - 1]) % MOD3;
        pw3[i] = pw3[i - 1] * BASE3 % MOD3;
    }
    int ans = 0;
    for(int i = a.size();i<=b.size();++i) {
        if(ok(i)) {
            ll val = (hsh[i] + MOD - hsh[i - a.size()] * pw[a.size()] % MOD) % MOD;
            ll val2 = (hsh2[i] + MOD2 - hsh2[i - a.size()] * pw2[a.size()] % MOD2) % MOD2;
            ll val3 = (hsh3[i] + MOD3 - hsh3[i - a.size()] * pw3[a.size()] % MOD3) % MOD3;
            if(!vis.count(val) && !vis2.count(val2) && !vis3.count(val3)) 
                vis.insert(val), vis2.insert(val2), vis3.insert(val3), ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}
