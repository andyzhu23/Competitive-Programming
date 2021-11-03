#include <bits/stdc++.h>
using namespace std;

namespace fast_io {
    int read() {
        int x = 0, f = 0; char ch = getchar();
        while (!isdigit(ch)) f |= ch == '-', ch = getchar();
        while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
        return f ? -x : x;
    }
    void read(int& x) {x = read();}
    template<typename T> void print(T x) {
        if (x < 0) putchar('-'), x = -x;
        if (x >= 10) print(x / 10);
        putchar(x % 10 + '0');
    }
    template<typename T> void print(T x, char let) {
        print(x), putchar(let);
    }
}
using namespace fast_io;
using ll = long long;
#define pb push_back
#define all(v) v.begin(), v.end()
const int N = 1e5 + 10;
int a[N], n;
set<int> dis;
unordered_map<int, int> Map;

struct fenwick {
    int c[N];
    void update(int a, int b) {
        for(int i = a;i<N;i += i & (-i)) c[i] += b;
    }
    int query(int a) {
        int ans = 0;
        for(int i = a;i;i-=i & (-i)) ans += c[i];
        return ans;
    }
    int query(int a, int b) {
        return query(b) - query(a - 1);
    }
} fen;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(n);
    for(int i = 1;i<=n;++i) {
        read(a[i]);
        dis.insert(a[i]);
    }
    int len = 0;
    for(auto x : dis) Map[x] = ++len;
    ll tot = 0;
    for(int i = 1;i<=n;++i) {
        a[i] = Map[a[i]];
        tot += fen.query(a[i] + 1, n);
        fen.update(a[i], 1);
    }
    ll ans = tot;
    for(int i = 1;i<n;++i) {
        tot -= fen.query(1, a[i] - 1);
        tot += fen.query(a[i] + 1, n);
        ans = min(ans, tot);
    }
    print(ans, '\n');
    return 0;
}
