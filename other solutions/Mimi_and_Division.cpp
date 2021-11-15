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

const int N = 2e5 + 10;
int n, q, a[N], bsiz, block[N];
int cnt[500][N];

void update() {
    int u = read(), v = read();
    for(int i = 1;i * i<=a[u];++i) 
        if(a[u] % i == 0) {
            cnt[block[u]][i]--;
            if(a[u] / i != i) cnt[block[u]][a[u] / i]--;
        }
    for(int i = 1;i * i<=v;++i) 
        if(v % i == 0) {
            cnt[block[u]][i]++; 
            if(v / i != i) cnt[block[u]][v / i]++;
        }
    a[u] = v;
}

int query() {
    int l = read(), r = read(), x = read();
    int ans = 0;
    for(int i = l;i<=min(r, block[l] * bsiz);++i) {
        ans += a[i] % x == 0;
    }
    if(block[l] == block[r]) return ans;
    for(int i = block[l] + 1;i<block[r];++i) {
        ans += cnt[i][x];
    }
    for(int i = (block[r] - 1) * bsiz + 1;i<=r;++i) {
        ans += a[i] % x == 0;
    }
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    n = read(), q = read();
    bsiz = sqrt(n);
    for(int i = 1;i<=n;++i) {
        block[i] = (i - 1) / bsiz + 1;
        cin>>a[i];
        for(int j = 1;j * j<=a[i];++j) 
            if(a[i] % j == 0) {
                cnt[block[i]][j]++;
                if(a[i] / j != j) cnt[block[i]][a[i] / j]++;
            }
    }
    while(q--) {
        int opt = read();
        if(opt == 1) print(query(), '\n');
        else update();
    }
    return 0;
}