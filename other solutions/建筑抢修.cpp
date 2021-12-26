#include <bits/stdc++.h>
using namespace std;
namespace fast_io {
    int read() {
        int x = 0, f = 0; char ch = getchar();
        while (!isdigit(ch)) f |= ch == '-', ch = getchar();
        while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
            return f ? -x : x;
    }
    long long readLL() {
        long long x = 0, f = 0; char ch = getchar();
        while (!isdigit(ch)) f |= ch == '-', ch = getchar();
        while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
            return f ? -x : x;
    }
    void read(int& x) {x = read();}
    void read(long long& x) {x = readLL();}
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

struct build {
    ll t1, t2;
    bool operator<(const build& other) const {
        return t1 < other.t1;
    }
};

priority_queue<build> heap;

bool cmp(build a, build b) {
    return a.t2 < b.t2;
}

int n;
vector<build> a;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(n);
    for(int i = 1;i<=n;++i) {
        ll u, v;
        read(u), read(v);
        a.pb({u, v});
    }
    sort(all(a), cmp);
    ll t = 0;
    int ans = 0;
    for(auto x : a) {
        if(t + x.t1 <= x.t2) {
            t += x.t1;
            ++ans;
            heap.push(x);
        } else if(heap.top().t1 > x.t1) {
            t = t - heap.top().t1 + x.t1;
            heap.pop();
            heap.push(x);
        }
    }
    print(ans, '\n');
    return 0;
}

