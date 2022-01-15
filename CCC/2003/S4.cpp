#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> // for gp_hash_table
using namespace __gnu_pbds;
namespace fast_io {
    inline int read() {
        int x = 0, f = 0; char ch = getchar();
        while (!isdigit(ch)) f |= ch == '-', ch = getchar();
        while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
            return f ? -x : x;
    }
    inline void read(int& x) {x = read();}
    template<typename T> inline void print(T x) {
        if (x < 0) putchar('-'), x = -x;
        if (x >= 10) print(x / 10);
            putchar(x % 10 + '0');
    }
    template<typename T> inline void print(T x, char let) {
        print(x), putchar(let);
    }
}
using namespace fast_io;

const int BASE = 131;
using ll = unsigned long long;
const int N = 5e3 + 10;
ll h[N], p[N];
char s[N];
gp_hash_table<ll,bool> vis; 
int t;
bool flag = 1;

inline void solve() {
    int n = 0;
    char c = getchar();
    while(!isalpha(c) && !isdigit(c)) c = getchar();
    while(isalpha(c) || isdigit(c)) s[++n] = c, c = getchar();
    for(int i = 1;i<=n;++i) 
        h[i] = (h[i - 1] * BASE + s[i]);
    int ans = 1;
    bool flag = 0;
    for(int l = 1;l<=n;++l) {
        if(flag) {
            ans += n - l + 1;
            continue;
        }
        for(int i = 0;i + l <= n;++i) {
            int j = i + l;
            ll x = (h[j] - h[i] * p[l]);
            if(!vis[x]) ++ans;
            vis[x] = 1;
        }
        if(vis.size() == n - l + 1) flag = 1;
        vis.clear();
    }
    print(ans, '\n');
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    p[0] = 1;
    for(int i = 1;i<N;++i) p[i] = p[i - 1] * BASE;
    t = read();
    while(t-- && flag) 
        solve();
    return 0;
}
