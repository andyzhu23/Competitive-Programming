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
const int N = 1e5 + 10;
int n, m1, m2, cnt1[N], cnt2[N];
using pii = pair<int, int>;
#define fir first
#define sec second
#define pb push_back
#define all(v) v.begin(), v.end()
vector<pii> u, v;

priority_queue<int, vector<int>, greater<int> > heap;
priority_queue<pii, vector<pii>, greater<pii> > heap2;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    n = read(), m1 = read(), m2 = read();
    for(int i = 1;i<=m1;++i) {
        int a = read(), b = read();
        u.pb({a, b});
    }
    for(int i = 1;i<=m2;++i) {
        int a = read(), b = read();
        v.pb({a, b});
    }
    sort(all(u));
    sort(all(v));
    for(int i = 1;i<=m1;++i) {
        heap.push(i);
        pii cur = u[i - 1];
        int a = cur.fir, b = cur.sec;
        while(!heap2.empty() && heap2.top().fir <= a) {
            heap.push(heap2.top().sec);
            heap2.pop();
        }
        ++cnt1[heap.top()];
        heap2.push({b, heap.top()});
        heap.pop();
    }
    while(!heap.empty()) heap.pop();
    while(!heap2.empty()) heap2.pop();
    for(int i = 1;i<=m2;++i) {
        heap.push(i);
        pii cur = v[i - 1];
        int a = cur.fir, b = cur.sec;
        while(!heap2.empty() && heap2.top().fir <= a) {
            heap.push(heap2.top().sec);
            heap2.pop();
        }
        ++cnt2[heap.top()];
        heap2.push({b, heap.top()});
        heap.pop();
    }
    int ans = 0;
    for(int i = 0;i<=n;++i) cnt1[i] += cnt1[i - 1], cnt2[i] += cnt2[i - 1];
    for(int i = 0;i<=min(m1, n);++i) ans = max(ans, cnt1[i] + cnt2[n - i]);
    print(ans, '\n');
    return 0;
}

