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
const int N = 1e6 + 5;
using ll = long long;
ll b[N], p[N], u[N], bb[N], pp[N], d[N];
int n;
vector<int> stk;
ll a[N], ans;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(n);
    for(int i = 1;i<=n;++i) b[i] = read(), bb[i] = b[i];
    for(int i = 1;i<n;++i) p[i] = read();
    for(int i = 1;i<n;++i) u[i] = read();
    for(int i = 1;i<n;++i) {
        pp[i] = p[i] - u[i];
        int tmp = min(pp[i], bb[i]);
        bb[i] -= tmp;
        pp[i] -= tmp;
        if(bb[i + 1] < pp[i]) {
            puts("NO");
            return 0;
        }
        bb[i + 1] -= pp[i];
    }
    puts("YES");
    for(int i = 1;i<=n;++i) pp[i] = p[i], bb[i] = 0;
    for(int i = 1;i<n;++i) {
        int tmp = min(pp[i], b[i]);
        stk.push_back(i);
        b[i] -= tmp;
        pp[i] -= tmp;
        a[i] = tmp;
        while(b[i + 1] < pp[i]) {
            int x = stk.back();
            ll val = min(u[x], pp[i] - b[i + 1]);
            d[x + 1] += val;
            d[i + 1] -= val;
            u[x] -= val;
            if(u[x] == 0) stk.pop_back();
            pp[i] -= val;
            bb[x] += val;
            ans += val;
        }
        b[i + 1] -= pp[i];
        u[i] = min(u[i], pp[i]);
    }
    print(ans, '\n');
    for(int i = 1;i<n;++i) {
        d[i] += d[i - 1];
        a[i] += d[i];
        print(a[i], ' ');
        print(bb[i], ' ');
        print(p[i] - a[i] - bb[i], '\n');
    }
    return 0;
}

