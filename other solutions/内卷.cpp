#pragma GCC optimize(2)
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

priority_queue<int> heap;
priority_queue<int, vector<int>, greater<int> > heap2;
const int N = 1e5 + 10;
int a[N];
long long tot;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n = read();
    for(int i = 1;i<=n;++i) {
        a[i] = read();
        tot += a[i];
    }
    if(tot % n) {
        puts("-1");
        return 0;
    }
    int res = tot / n;
    for(int i = 1;i<=n;++i) {
        if(a[i] < res) heap2.push(a[i]);
        else heap.push(a[i]);
    }
    int ans = 0;
    while(!heap.empty() && !heap2.empty()) {
        int a = heap.top(); heap.pop();
        int b = heap2.top(); heap2.pop();
        int c = min(res - b, a - res);
        a -= c, b += c;
        if(a != res) heap.push(a);
        if(b != res) heap2.push(b);
        ++ans;
    }
    print(ans, '\n');
    return 0;
}
