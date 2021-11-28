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
const int N = 3e3 + 10;
int a[N];
map<int, int> mp[N];
unordered_set<int> vis;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n = read();
    for(int i = 1;i<=n;++i) a[i] = read(), vis.insert(a[i]);
    sort(a + 1, a + n + 1);
    int ans = 0;
    for(int i = 1;i<=n;++i) {
        for(int j = 1;j<i;++j) {
            if(vis.count(a[i] + a[i] - a[j])) 
                mp[i][a[i] - a[j]] = a[j];
            ans = max(ans, mp[j][a[i] - a[j]] + a[j] + a[i]);
            mp[j].erase(mp[j].begin(), mp[j].find((a[i] - a[j])));
        }
    }
    print(ans ,'\n');
    return 0;
}
