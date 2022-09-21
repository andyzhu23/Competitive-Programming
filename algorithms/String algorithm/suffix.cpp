#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, sa[N], rk[N << 1], oldrk[N << 1], cnt[N], id[N];
string s;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>s;
    int m = 127;
    n = s.size();
    s = '@' + s;
    for(int i = 1;i<=n;++i) ++cnt[rk[i] = s[i]];
    for(int i = 1;i<=m;++i) cnt[i] += cnt[i - 1];
    for(int i = n;i>=1;--i) sa[cnt[rk[i]]--] = i;
    memcpy(oldrk, rk, sizeof rk);
    for(int p = 0, i = 1;i<=n;++i) {
        if(oldrk[sa[i]] == oldrk[sa[i - 1]]) {
            rk[sa[i]] = p;
        } else {
            rk[sa[i]] = ++p;
        }
    }
    for(int w = 1;w<n;w <<= 1, m = n) {
        memset(cnt, 0, sizeof cnt);
        memcpy(id, sa, sizeof sa);
        for(int i = 1;i<=n;++i) ++cnt[rk[id[i] + w]];
        for(int i = 1;i<=m;++i) cnt[i] += cnt[i - 1];
        for(int i = n;i>=1;--i) sa[cnt[rk[id[i] + w]]--] = id[i];
        memset(cnt, 0, sizeof cnt);
        memcpy(id, sa, sizeof sa);
        for(int i = 1;i<=n;++i) ++cnt[rk[id[i]]];
        for(int i = 1;i<=m;++i) cnt[i] += cnt[i - 1];
        for(int i = n;i>=1;--i) sa[cnt[rk[id[i]]]--] = id[i];
        memcpy(oldrk, rk, sizeof rk);
        for(int p = 0, i = 1;i<=n;++i) {
            if(oldrk[sa[i]] == oldrk[sa[i - 1]] && oldrk[sa[i] + w] == oldrk[sa[i - 1] + w]) {
                rk[sa[i]] = p;
            } else {
                rk[sa[i]] = ++p;
            }
        }
    }
    for(int i = 1;i<=n;++i) cout<<sa[i]<<" \n"[i==n];
    return 0;
}
